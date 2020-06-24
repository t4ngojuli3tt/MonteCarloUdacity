#include <iostream>
#include <random>
#include <math.h>

#include "Option.h"

using namespace std; 



int main(){
    cout << "#################################### Monte Carlo Option Price Calculator #######################################" << endl;
    cout << "This is option pricer based on concurrent Monte Carlo simulation. It can price call and put Europen options" << endl;
    cout << "#######################################################################################################" << endl;
 
    cout << "Please enter the details of the stock and the option." << endl;
    cout << "Please enter all arguments as double (e.g. S0 = 100.0), except 'Is call' where bool is expected, 1 if you want to value call option, 0 if put." << endl;    
    cout << "Current stock price:" << endl;  
    double S0;
    cin >> S0; 

    cout << "Risk rate:" << endl;  
    double r;
    cin >> r; 

    cout << "Volatility:" << endl;  
    double sigma;
    cin >>  sigma; 

    cout << "Strike price:" << endl;  
    double K;
    cin >>  K; 

    cout << "Expiry date:" << endl;  
    double T;
    cin >> T; 

    cout << "Is call:" << endl;  
    bool isCall;
    cin >> isCall; 
    
    // values of test parameters, for these values the option price is 11.348, results show that the implementation is correct.
    //double S0=100.0, r=0.03, sigma=0.25, T=1.0, K=100.0;
    //bool isCall=true;
    // paramter m is not usefule for Europen option, it would be for path-dependent options, so here is kept fix. 
    int m=1;
    // N is a number of simulation and t number of async task, so 8192 is a number of simulation in the one task. 
    // This N number of simulation provide resonalby good results and for this N t = 32 provide optimal performance.  
    int t =32;
    long N=8192 *32;
    BSModel Model(S0,r,sigma); 
    EurOption EurOption(T,K,m,isCall);
    cout << "Europen Call Price"  << endl; 
    cout << EurOption.PriceByMC(Model,N,t) << endl;




    return 0;
}