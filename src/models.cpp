#include "models.h"
#include <cmath>
#include <random>



using namespace std; 
const double PI=4.0*atan(1.0);

double Gauss()
{
// By Box–Muller Theorem the return random variable has disribution N(0,1) 
random_device rd;
mt19937 generator(rd());
uniform_real_distribution<double> rnd(0, 1);

double z1 = rnd(generator);
double z2 = rnd(generator);

return sqrt(-2*log(z1))*cos(2*PI*z2);
}

void BSModel::GenerateSamplePath(double T, int m, SamplePath& S) 
{
    double St = getS0();
    for(int k=0; k<m; k++)
    {
        S[k]= St*exp((getR()-getSigma()*getSigma()*0.5)*(T/m)+getSigma()*sqrt(T/m)*Gauss());
        St=S[k];
    }
}