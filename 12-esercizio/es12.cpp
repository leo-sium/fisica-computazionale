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

double inv(double x){
    if(x<(2./3.)){
        return (3./2.)*x;
    }
    else{
        return sqrt(1-log(3.*(1.-x)));
    }
}

double f ( double x){
    return 1./sqrt(M_PI)*exp(-x*x);
}

double g(double x){
    if (x<1) return 1./sqrt(M_PI);
    else return 1./sqrt(M_PI)*x*exp(1-x*x);
}

int main() {

    srand(time(0));

    vector<double> punti_inv;
    vector<double> punti_ar;

    //----------------------------------------------------------------------------------
    double z = 0.;
    double a = 0.;
    double x = 0.;
    double controllo;
    int N = pow(10, 5);
    //scrivo bene il motivo di questa generazione e perchè ho calcolato i numeri gaussiani così
    for (int i=0; i<N; i++){
        z = rand_range(0, 1.);
        a = rand_range(0, 1.);
        x = f_inv(z,a);
        punti_inv.push_back(x);
    }
    //---------------------------------------------------------------------------------
    //la tengo commentata, questa genera il grafico di g(x), magari mi serve nella relazione 
    /*
    for(int i=0; i<N; i++){
        z= rand_range(0., 1.);
        x= inv(z);
        punti_ar.push_back(x);
    }
    */

    while (punti_ar.size()< N) {
        z = rand_range(0., 1.);
        x = inv(z);
        a = rand_range(0., 1.);
        controllo = f(x)/g(x);
        if( a < controllo){
            x = x*moneta();
            punti_ar.push_back(x);
        }

    }

    fstream file;
    file.open("punti.dat", ios_base::out);

    for(int i=0; i<punti_inv.size(); i++){
        file << setprecision(10)<< punti_ar[i] << endl;
    }
    file.close();

    return 0;
}