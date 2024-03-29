#include "PLASTIC_Event_Store.h"

using namespace std;

//---------------------------------------------------------------

PLASTIC_Event_Store::PLASTIC_Event_Store(){
	Event = new PLASTIC_Event*[MEMORY_LIMIT];
	Event_WR = new double[MEMORY_LIMIT];
	for(int i = 0;i < MEMORY_LIMIT;++i){
		Event[i] = NULL;
		Event_WR[i] = -9999;
	}
	event_counter = 0;
}

//---------------------------------------------------------------

PLASTIC_Event_Store::~PLASTIC_Event_Store(){
	for(int i = 0;i < MEMORY_LIMIT;++i) if(Event[i]) delete Event[i];
	cout << "*** PLASTIC: from " << MEMORY_LIMIT << " possible objects " << event_counter << " were used ***" << endl;
	delete[] Event;
	delete[] Event_WR;
}

//---------------------------------------------------------------


void PLASTIC_Event_Store::store(Raw_Event* RAW){
	if(event_counter == MEMORY_LIMIT){
		cerr << "PLASTIC_Event_Store MEMORY_LIMIT of " << MEMORY_LIMIT*1.65/1024. << "MB reached !" << endl;
		cerr << "Check if delete process is working correctly!" << endl;
		cerr << "If it does, you can change the MEMORY_LIMIT by hand in PLASTIC_Event_Store.cxx directly (but be careful!)" << endl;
		exit(0);
	}

	Event[event_counter] = new PLASTIC_Event(RAW);
	Event_WR[event_counter] = (double) RAW->get_WR();
	event_counter++;
}

//---------------------------------------------------------------

void PLASTIC_Event_Store::get(int i){return;}

//---------------------------------------------------------------

void PLASTIC_Event_Store::purge(int i){
	//delete event
	if(Event[i]){
		delete Event[i];
		//shift last event to free memory slot
		Event[i] = Event[event_counter-1];
		Event_WR[i] = Event_WR[event_counter-1];
		//Nullify pointer of last event
		Event[event_counter-1] = NULL;
		Event_WR[event_counter-1] = -9999;
		event_counter--;
	}
	else cerr << "Event " << i << " already NULL -> undefined behavior!" << endl;
}

//---------------------------------------------------------------

int PLASTIC_Event_Store::Time_Comparison(ULong64_t WR){
	
	int return_value = -1;

	double delta = 0;
	double WR_d = (double) WR;
	
	//search through event data for smallest time difference
	for(int i = 0;i < event_counter;++i){
		delta = abs(WR_d - Event_WR[i]);
		if(delta < TIME_THRESHOLD){
			return_value = i;
			break;
		}
	}
	return return_value;
}

//---------------------------------------------------------------