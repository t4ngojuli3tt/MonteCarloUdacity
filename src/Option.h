
#ifndef Option_h
#define Option_h

#include "Model.h"

class Option
{
public:
    // getters & setters for opiton paremeters
    double getT(){return _T;}
    void setT(double T) { _T = T;}

    int getM(){return _m;}
    void setM(int m) { _m = m;}

    double getK(){return _K;}
    void setK(double K) { _K = K;}

    bool getIsCall(){return _isCall;}
    void setIsCall(bool isCall) { _isCall = isCall;}


    virtual double PriceByMC(BSModel Model, long N, int noOfTask) =0;

protected:
    virtual double Payoff(SamplePath& S, double _K, bool _isCall)=0;    
    virtual double PriceByMCSingleThread(BSModel Model, long N)=0;

private:
    double _T;
    int _m;
    double _K;
    bool _isCall;

};

class EurOption : public virtual Option
{
public:
    EurOption(double T, double K, int m, bool isCall)
    {setT(T); setK(K); setM(m);setIsCall(isCall);}
    double PriceByMC(BSModel Model, long N, int noOfTask);
    
protected:
    double Payoff(SamplePath& S, double _K, bool _isCall);    
    double PriceByMCSingleThread(BSModel Model, long N);
  
};


#endif