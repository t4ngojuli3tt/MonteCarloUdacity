#include "PathDepOption.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel bsmodel, long N)
    {
    double H=0.0;
    SamplePath S(m);
    for(long i=0; i<N; i++)
    {
        bsmodel.GenerateSamplePath(T,m,S);
        H = (i*H + Payoff(S))/(i+1.0);
    }
    return exp(-bsmodel.getR()*T)*H;
    }

double ArthmAsianCall::Payoff(SamplePath& S) 
    {
    double Ave=0.0;
    for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
    }