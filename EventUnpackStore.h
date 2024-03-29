//                  DESPEC analysis software AM 07.03.19
//
//---------------------------------------------------------------
//       The GSI Online Offline Object Oriented (Go4) Project
//       Experiment Data Processing at EE department, GSI
//---------------------------------------------------------------
//
//Copyright (C) 2000- Gesellschaft f. Schwerionenforschung, GSI
//                    Planckstr. 1, 64291 Darmstadt, Germany
//Contact:            http://go4.gsi.de
//----------------------------------------------------------------
//This software can be used under the license agreements as stated
//in Go4License.txt file which is part of the distribution.
//----------------------------------------------------------------

#ifndef UNPACKEVENTSTORE_H
#define UNPACKEVENTSTORE_H

#define SCN_NUM_CHAN 36

#include "AIDA_Event.h"
#include "TGo4EventElement.h"

struct AidaUnpackData {
     uint64_t AIDATime;
     int AIDAHits;
       
      std::vector<AidaEvent> ImplantEvents;
      std::vector<AidaEvent> DecayEvents;

      std::vector<AidaHit> Implants;
      std::vector<AidaHit> Decays;
};

class EventUnpackStore : public TGo4EventElement {
public:
        EventUnpackStore();
        EventUnpackStore(const char* name);
        virtual ~EventUnpackStore();

        /** Method called by the framework to clear the event element. */
        void Clear(Option_t *t="");
        //Clear the members
        void ClearEvent();       

        //FRS Output
    Float_t fFRS_dE[2], fFRS_dE_cor[2];
    Float_t fFRS_sci_l[12], fFRS_sci_r[12], fFRS_sci_e[12], fFRS_sci_tx[12], fFRS_sci_x[12];
    Float_t fFRS_sci_tofll2, fFRS_sci_tofll3, fFRS_sci_tof2, fFRS_sci_tofrr2, fFRS_sci_tofrr3, fFRS_sci_tof3;
    Float_t fFRS_ID_x2, fFRS_ID_y2, fFRS_ID_a2, fFRS_ID_b2;
    Float_t fFRS_ID_x4, fFRS_ID_y4, fFRS_ID_a4, fFRS_ID_b4;
    Int_t fFRS_sci_dt_21l_21r, fFRS_sci_dt_41l_41r, fFRS_sci_dt_42l_42r, fFRS_sci_dt_43l_43r;
    Int_t fFRS_sci_dt_21l_41l, fFRS_sci_dt_21r_41r, fFRS_sci_dt_21l_42l, fFRS_sci_dt_21r_42r;
    Float_t fFRS_ID_brho[2], fFRS_ID_rho[2];
    Float_t fFRS_beta, fFRS_beta3, fFRS_gamma;
    Float_t fFRS_AoQ, fFRS_AoQ_corr;
    Float_t fFRS_z, fFRS_z2, fFRS_z3;
    Float_t fFRS_timestamp, fFRS_ts, fFRS_ts2;  
    
        //AIDA output 
        std::vector<AidaUnpackData> Aida;
        
         int fAIDAHits;
         int AIDAHits;
         Long64_t fWR_Aida_Det_diff[10000];
         Long64_t AIDATime; 
         Long64_t fWR_main_array[10000]; 
        
        /* the raw adc values*/
//         UInt_t Front_X[4][16];
//         UInt_t Back_Y[8][16];
//         UInt_t Box[10][16];
//         UInt_t Gamma[12][16];
//          //  Long64_t Time;
//         Int_t hit_time[12][16]; //step in time; multiply by 20ns and add it to real time
//         Long64_t trg_time; //real time
        
//         Int_t fiCrate1[SCN_NUM_CHAN]; //This two are for the QDC's 
//         Int_t fiCrate2[SCN_NUM_CHAN];
//         Double_t fiCrate3[SCN_NUM_CHAN];  // For TDC

       
        //General Output
        Int_t  fevent_number;
        Int_t  fProcID[7];
        Int_t  fUsed_Systems[7];
        Int_t  fArray_count;

         // Plastic output events
        UInt_t fbPlas_VME_firedQDC;
        UInt_t fbPlas_VME_QDC_Multiplicity;
        Int_t  fbPlas_VME_QDC_ID[32];
        double fbPlas_VME_QDC_E[32];
        UInt_t fbPlas_VME_firedTDC;
        UInt_t fbPlas_VME_TDC_Multiplicity[32];
        Int_t fbPlas_VME_TDC_ID[50];
        double fbPlas_VME_TDC_TS[50][32]; 
        
        double fbPlas_VME_QDC_E_AIDA[32];
        
        Int_t fScalar_fired;
        Int_t fScalar_ID;
        
        UInt_t fFat_firedQDC;
        UInt_t fFat_QDC_Multiplicity;
        Int_t  fFat_QDC_ID[50];
        Double_t fFat_QDC_E[50];
        Double_t fFat_QDC_T[50];
        UInt_t fFat_firedTDC;
        Int_t fFat_TDC_ID[50];
        double fFat_TDC_TS[50][50]; 
        UInt_t fFat_TDC_Multiplicity[50];
        Long64_t fFat_WR;
        
        double_t fSC41[50];
        
        Int_t fGal_fired;
        Int_t fGal_ID[32]; 
        Double_t fGal_E[32];
        Double_t fGal_T[32];
        Int_t fGal_Pileup;
        Long64_t fGal_WR;
        
        Int_t ffing_tamexhits;
        Int_t ffing_leadHits[4];
        Int_t ffing_trailHits[4];
        Int_t ffing_iterator[4];
        Int_t ffing_tamexCh[4][32];
        
        Int_t ffing_Lead_Phys_Chan[4][32];
        Int_t ffing_Trail_Phys_Chan[4][32];
        Int_t ffing_chID[4][32];
        Double_t ffing_Trig[4];
        Double_t ffing_Lead_T[4][100];
        Double_t ffing_Trail_T[4][100];
        Double_t ffing_TOT[4][100];
        Double_t ffing_TOT_added[4][100];
        
       Double_t ffing_lead_coarse[4][100];
       Double_t ffing_lead_fine[4][100];
       Double_t ffing_trail_coarse[4][100];
       Double_t ffing_trail_fine[4][100];
   
        

      /* Pattern unit */
      // UInt_t  fPatternUnit;
/*
        Double_t        l_E[12][16];
        Double_t        l_ETrig[12][16]; 
    TH1	    *h_trapez_fpga[MAX_SFP][MAX_SLAVE][N_CHA];  //! MWD
    TH1     *h_cfd    [MAX_SFP][MAX_SLAVE][N_CHA];  //! MWD
    TH1     *h_FF   [MAX_SFP][MAX_SLAVE][N_CHA];  //! MWD2

    TH1     *h_trace_filt       [MAX_SFP][MAX_SLAVE][N_CHA];  //!
    TH1     *h_macro;  //!
    TH1     *h_tof;  //!
    TH1     *h_macro_fill;  //!
    TH1     *h_tof_fill;  //!
    TH1     *hfStart; //!
    TH1     *h_time;  //!*/
/*
        double tau;
        Int_t adj;
        bool Z;
        bool bRise;
    bool bFall;
    Int_t fStart_ft;
    Int_t fStart_min;
    Int_t ftest_ft;
    Int_t fDelay_av;
    Int_t fWidth_av;
    Int_t fEps_ft;
        Int_t           l_T[12][16];
        Double_t        fTrace[2048];
        Int_t           l_sfp;
        Int_t           l_feb;
        Int_t           l_cha;
        Long64_t        l_t_trig;

        UInt_t Macropulse;
        UInt_t TOF;
        UInt_t Trig;
        UInt_t event_number;
        UInt_t Multihit;*/
   ClassDef(EventUnpackStore,1)
};
#endif //TEVENT_H




//----------------------------END OF GO4 SOURCE FILE ---------------------
