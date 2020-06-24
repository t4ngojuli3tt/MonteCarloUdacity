#include "EurOption.h"
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
    
    double H;
    SamplePath S(m);

    for(long i=0; i<N; i++)
    {
        bsmodel.GenerateSamplePath(T,m,S);
        H = (i*H + Payoff(S,K))/(i+1.0);
    }

    return exp(-bsmodel.getR()*T)*H;
    }


double EurOption::PriceByMC(BSModel bsmodel, long N, int t)
    {
    
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();


    vector<future<double>> H;

    for(long j=0; j<t; j++)
    {   
        //cout << i << " " <<  N/t << endl;
        H.emplace_back(async(launch::async, &EurOption::PriceByMCSingleThread, this, bsmodel, N/t));
    }

    for_each(H.begin(), H.end(), [](std::future<double> &ftr) { ftr.wait(); });

    double Z = 0.0;
    for (auto &x : H){
        Z += x.get();
    }
    
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
    cout << "Execution finished after " << duration <<" microseconds" << endl;

    return Z/t;
    }





double EurOption::Payoff(SamplePath& S, double K) 
    {
    return max(S.back() - K ,0.0);
    }