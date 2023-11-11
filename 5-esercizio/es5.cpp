#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <math.h>
#include <ostream>

using namespace std;

double f (double x){
    double ris = pow(x,2) + x*sin(4*x);
    return ris;
}

double f_legendre (double x){
    double t = (9./2.)*x + (7./2.);
    double ris = (9./2.)*(pow(t, 2) + t*sin(4*t));
    return ris;

}

int main (int argc, char** argv){

    int N_trapezio = 1000;
    int N_simpson = 1001;
    int N_romberg = pow(2, 7)+1;
    int N_legendre = 48;


    double xmin = -1;
    double xmax = 8;

    double ris_trap = trapezio(xmin, xmax, N_trapezio, f);
    double ris_simp = simpson(xmin, xmax, N_simpson, f);
    double ris_romb = romberg(xmin, xmax, N_romberg, f);
    double ris_leg = legendre(N_legendre, f_legendre);
 

    cout << setprecision(9) << ris_trap << "\t" << ris_simp << "\t" << ris_romb << "\t" << endl;
    cout << setprecision(9) << ris_leg << "\t" << endl;


    return 0;
}