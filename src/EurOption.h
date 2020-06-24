
#ifndef EurOption_h
#define EurOption_h

#include "models.h"

class EurOption
{
public:
    double T;
    int m;
    double K;
    EurOption(double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double PriceByMC(BSModel Model, long N, int noOfTask);

private:
    double Payoff(SamplePath& S, double K_);    
    double PriceByMCSingleThread(BSModel Model, long N);
};

#endif