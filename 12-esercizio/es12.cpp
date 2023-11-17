#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "time.h"
#include "vector"

using namespace std;

double f_inv( double z, double a){

    double r = sqrt(-log(1-z));
    double x = r * cos(2*M_PI*a);
    return x;
}

double mag(double x){
    if (x<1) return (1./sqrt(M_PI));
    else return 1./sqrt(M_PI) * x * exp(1 - x * x);
}

double pdf(double x){
    return 1./sqrt(M_PI) * exp( -pow(x,2));

}

double inv(double x){
    if (x<(M_E-1)/(2*sqrt(M_PI))) return rand_range(0, 1.);
    else return (sqrt(-log(1-(2*x*sqrt(M_PI))/M_E)));
}

int main() {

    srand(time(0));

    vector<double> punti_inv;
    vector<double> punti_ar;

    //----------------------------------------------------------------------------------
    double z = 0.;
    double a = 0.;
    double x = 0.;
    int N = pow(10, 6);
    //scrivo bene il motivo di questa generazione e perchè ho calcolato i numeri gaussiani così
    for (int i=0; i<N; i++){
        z = rand_range(0, 1.);
        a = rand_range(0, 1.);
        x = f_inv(z,a);
        punti_inv.push_back(x);
    }
    //---------------------------------------------------------------------------------
   
    for(int i=0; i<N; i++){
        z= rand_range(0., 1.);
        x= inv(z);
        punti_ar.push_back(x);
    }

    fstream file;
    file.open("punti.dat", ios_base::out);

    for(int i=0; i<punti_inv.size(); i++){
        file << setprecision(10)<< punti_ar[i] << endl;
    }
    file.close();

    return 0;
}