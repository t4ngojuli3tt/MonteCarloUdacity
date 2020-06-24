#include "Option.h"
#include <cmath>
#include <numeric>
#include <chrono>
#include <iostream>
#include <thread>
#include <future>
#include <algorithm>

using namespace std;

double  EurOption::PriceByMCSingleThread(BSModel bsmodel, long N)
    {
    
    double V;
    SamplePath S(getM());

    for(long i=0; i<N; i++)
    {
        bsmodel.GenerateSamplePath(getT(),getM(),S);
        V = (i*V + Payoff(S,getK(), getIsCall()))/(i+1.0);
    }

    return exp(-bsmodel.getR()*getT())*V;
    }


double EurOption::PriceByMC(BSModel bsmodel, long N, int t)
    {
    

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();


    vector<future<double>> F;

    for(long j=0; j<t; j++)
    {   
        F.emplace_back(async(launch::async, &EurOption::PriceByMCSingleThread, this, bsmodel, N/t));
    }

    for_each(F.begin(), F.end(), [](std::future<double> &ftr) { ftr.wait(); });

    double V = 0.0;
    for (auto &x : F){
        V += x.get();
    }

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
    cout << "Execution finished after " << duration <<" microseconds" << endl;

    return V/t;
    }





double EurOption::Payoff(SamplePath& S, double _K, bool _isCall) 
    {
    if (_isCall)
        return max(S.back() - _K ,0.0);
    else
        return max(_K - S.back()  ,0.0);        
    }