#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <math.h>

using namespace std;

double f_legendre(double x){
    double t = (5./2.)*x+(11./2);
    double ris = (5./2.)* cosh(t);
    return ris;
}
/*
double f_laguerre1(double x){
    double t = (x+(1./8.));
    double y = 1./t;
    double ris = (pow(y,2)/2.)*(exp((pow(t,2)+1)/t)+exp((pow(t,2)-1)/t))*exp(-1./8.);
    return ris;
}

double f_laguerre2(double x){
    double t = (x+(1./3.));
    double y = 1./t;
    double ris = (pow(y,2)/2.)*(exp((pow(t,2)+1)/t)+exp((pow(t,2)-1)/t))*exp(-1./3.);
    return ris;
}
*/

//scrivo bene come ho fatto che ho sofferto abbastanza
double f_laguerre (double x){
    return (1./2.)*(exp(8)-exp(3)+exp(-3)-exp(-8));
}

int main (int argc, char** argv){

    int N_trapezio = 1001;
    int N_simpson = 1001;
    int N_romberg = pow(2, 7)+1;
    int N_legendre = 4;
    int N_laguerre = 4;
    //bool V = true;

    double xmin = 3;
    double xmax = 8;

    double ris_trap = trapezio(xmin, xmax, N_trapezio, cosh);
    double ris_simp = simpson(xmin, xmax, N_simpson, cosh);
    double ris_romb = romberg(xmin, xmax, N_romberg, cosh);
    double ris_leg = legendre(N_legendre, f_legendre);
    double ris_lag = laguerre(N_laguerre, f_laguerre); 
    cout << setprecision(9) << ris_trap << "\t" << setprecision(9) << ris_simp << "\t" << setprecision(9) << ris_romb << "\t" << ris_leg << "\t" << setprecision(100) << ris_lag << endl;


    return 0;
}