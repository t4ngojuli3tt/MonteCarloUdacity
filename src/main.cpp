#include <iostream>
#include <random>
#include <math.h>

#include "PathDepOption.h"
#include "EurOption.h"

using namespace std; 

//#define PI 3.14159265



int main(){
    cout << "#################################### Monte Carlo Option pricer #######################################" << endl;
    cout << "This is option pricer based on concurrent Monte Carlo simulation. You can choose between Black-Scholtz and Vasicek model" << endl;
    cout << "It can price Europen, American and Asia options" << endl;
    cout << "#######################################################################################################" << endl;
  /*  
    cout << "Please enter the details of the stock and the option." << endl;  
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
    */
    double S0=100.0, r=0.03, sigma=0.25, T=1.0, K=100.0;
    BSModel Model(S0,r,sigma); 
    int m=1;
    int t =32;
    ArthmAsianCall Option(T,K,m); 
    long N=8192 *32;
    //cout << "Asian Call Price = " << Option.PriceByMC(Model,N) << endl;
    EurOption EurOpiton(T,K,m);
    cout << "Europen Call Price"  << endl; 
    cout << EurOpiton.PriceByMC(Model,N,t) << endl;
/*
    for (int i=1; i <10; i++){
    int t = 50*i;
    cout << N << endl;
    cout << "Europen Call Price async witn  " << t << "tasks" << endl;
    cout << EurOpiton.PriceByMCasync(Model,N,t) << endl;

    }
    
*/



    return 0;
}