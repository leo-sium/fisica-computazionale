#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "differenziali.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "time.h"
#include "vector"

using namespace std;

double f_x (double x, double v){
    double ris = v;
    return ris;
}

double f_v ( double x, double v){
    double ris = -x;
    return ris;
}

int main(){
    double theta0 = 0;
    double z0 = 1.;
    double h = 0.0002;
    double t = 10;
    double x_true = 0.;

    vector<double> punti;
    vector<double> tempi;

    vector<double> x(2);
    vector<double> v(2);

    vector<double> kx(4);
    vector<double> kv(4);
    double i = 0;

    x[0]= theta0;    
    v[0]=z0;

    while(i<t){

        kx[0] = h*f_x(x[0], v[0]);
        kv[0] = h*f_v(x[0], v[0]);

        kx[1] = h*f_x(x[0]+kx[0]/2., v[0]+kv[0]/2.);
        kv[1] = h*f_v(x[0]+kx[0]/2., v[0]+kv[0]/2.);

        kx[2] = h*f_x(x[0]+kx[1]/2., v[0]+kv[1]/2.);
        kv[2] = h*f_v(x[0]+kx[1]/2., v[0]+kv[1]/2.);

        kx[3] = h*f_x(x[0]+kx[2], v[0]+kv[2]);
        kv[3] = h*f_v(x[0]+kx[2], v[0]+kv[2]);

        x[1] = x[0] + 1./6.*(kx[0] + 2*kx[1] + 2*kx[2] + kx[3]);
        v[1] = v[0] + 1./6.*(kv[0] + 2*kv[1] + 2*kv[2] + kv[3]);

        x[0] = x[1];
        v[0] = v[1];

        i= i+h;

        tempi.push_back(i);
        punti.push_back(x[0]);
    }

    fstream file;
        file.open("evol.dat", ios_base::out);
        for(int j=0; i<punti.size(); ++i){
            file << tempi[i] << "\t" << punti[i]<< endl;
        }

    file.close();








    return 0;

}