#ifndef models_h
#define models_h
using namespace std;
#include<vector>

typedef vector<double> SamplePath;

class Model 
    {
    public:
        // getters & setters
        double getS0(){return _S0;}
        void setS0(double S0) { _S0 = S0;}

        double getR(){return _r;}
        void setR(double r) { _r = r;}

        double getSigma(){return _sigma;}
        void setSigma(double sigma) { _sigma = sigma;}

    private:
        double _S0;
        double _r;
        double _sigma;

    };



class BSModel : public Model
    {
    public:
        // Black Scholtz model
        BSModel(double S0, double r, double sigma)
        //{_S0 = S0; _r = r; sigma = _sigma;}
        {setS0(S0); setR(r); setSigma(sigma);}
        // Path generetor
        void GenerateSamplePath(double T,int m,SamplePath& S);

    };

class Vasicek : public Model
    {
    public:
        // Vasicek model
        Vasicek(double S0, double r, double sigma)
        //{_S0 = S0; _r = r; sigma = _sigma;}
        {setS0(S0); setR(r); setSigma(sigma);}
        // Path generetor
        void GenerateSamplePath(double T,int m,SamplePath& S);

    };


#endif