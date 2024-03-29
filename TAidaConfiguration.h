#ifndef AIDA_ANL_CONFIG
#define AIDA_ANL_CONFIG

#include <string>
#include <vector>

enum DSSDSide
{
  Junction = -1,
  Ohmic = 1,
};

struct DSSDConfiguration
{
  int DSSD;
  int Top;
  int Bottom;
  int Left;
  int Right;
  DSSDSide XSide;
  DSSDSide YSide;
};

struct FEEConfiguration
{
  int DSSD;
  DSSDSide Side;
  bool High;
};

class TAidaConfiguration
{
public:
    static TAidaConfiguration const* GetInstance();
    static void Create(std::string path);

    int FEEs() const;
    int DSSDs() const;

    bool AdjustADC() const;
    bool IgnoreMBSTS() const;

    double EventWindow() const;
    double FrontBackWindow() const;
    double FrontBackEnergyH() const;
    double FrontBackEnergyL() const;

    DSSDConfiguration DSSD(int i) const;
    FEEConfiguration FEE(int i) const;

private:
    TAidaConfiguration(std::string path);
    void ReadConfiguration(std::string path);
    void DSSDtoFEE();

    static TAidaConfiguration* instance;

    int fees;
    int dssds;
    bool adjustadc;
    bool ignorembsts;
    double eventwindow;
    double fbwindow;
    double fbenergyh;
    double fbenergyl;

    std::vector<DSSDConfiguration> dssd;
    std::vector<FEEConfiguration> fee;
};

inline TAidaConfiguration const* TAidaConfiguration::GetInstance()
{
  return instance;
}

inline void TAidaConfiguration::Create(std::string path)
{
  delete instance;
  instance = new TAidaConfiguration(path);
}

inline int TAidaConfiguration::FEEs() const
{
  return fees;
}

inline int TAidaConfiguration::DSSDs() const
{
  return dssds;
}

inline bool TAidaConfiguration::AdjustADC() const
{
  return adjustadc;
}

inline bool TAidaConfiguration::IgnoreMBSTS() const
{
  return ignorembsts;
}

inline double TAidaConfiguration::EventWindow() const
{
  return eventwindow;
}

inline double TAidaConfiguration::FrontBackWindow() const
{
  return fbwindow;
}

inline double TAidaConfiguration::FrontBackEnergyH() const
{
  return fbenergyh;
}

inline double TAidaConfiguration::FrontBackEnergyL() const
{
  return fbenergyl;
}

inline DSSDConfiguration TAidaConfiguration::DSSD(int i) const
{
  return dssd[i];
}

inline FEEConfiguration TAidaConfiguration::FEE(int i) const
{
  return fee[i];
}

#endif /* AIDA_ANL_CONFIG */
