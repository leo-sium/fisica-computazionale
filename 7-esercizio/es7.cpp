#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <math.h>
#include <ostream>

using namespace std;

double f(double x){
    double  ris= 0.5*pow(-log(x), 13./2.);
    return ris;
}

double f_laguerre(double x) {
    double ris = 0.5*pow(x, 13./2.);
    return ris;
}

double f_hermite (double x){
    double ris = pow(x,14);
    return ris;
}

int main (int argc, char** argv){

    double xmin = 0;
    double xmax = 1;

    double h = (xmax-xmin)/1000.;

//stessi commenti dell'esercizio  6 faccio qui le cose che ho fatto lì
    int N_trapezio = 1000;
    int N_simpson = 1001;
    int N_romberg = pow(2, 7)+1;
    int N_laguerre = 64;
    int N_hermite = 8;


    double mid = midpoint(xmin, xmin+h, f);
    double ris_trap = mid + trapezio(xmin+h, xmax, N_trapezio, f);
    double ris_simp = mid + simpson(xmin+h, xmax, N_simpson, f);
    double ris_romb = mid + romberg(xmin+h, xmax, N_romberg, f);
    double ris_lag = laguerre(N_laguerre, f_laguerre);
    double ris_her = 0.5*hermite(N_hermite, f_hermite);

    cout << mid << endl;
    cout << setprecision(9) << ris_trap << "\t" << ris_simp << "\t" << ris_romb << "\t" << endl;
    cout << setprecision(9) << ris_lag << "\t" << ris_her << "\t" << endl;


    return 0;
}