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
    double ris = (1./2.)*pow(log(1./x), 2);
    return ris;
}

double f_laguerre (double x){
    double ris = (pow(x+9, 2))*exp(-9)*(1./2.);
    return ris;
}
//faccio la stessa funzione ma prima traslata e poi specchiata e vedo le differenze
double f_hermite (double x){ 
    if(x>=3){
        return pow(x,5);
    }
    else {
        return (pow(6-x,5)*exp(12*(x-3)));
    }
}


int main (int argc, char** argv){

    double xmin = 0;
    double xmax = 1./exp(9);

    double h = (xmax-xmin)/1000.;

//provo a usare anche un valore fisso per il midpoint, provo a calcolare un solo midpoint per tutte, provo le due formule 
// midpoint e ne confronto la precisione. RICORDO CHE  tutte le formule chiuse calcolano gli estremi e così  vanno usate
    int N_trapezio = 1000;
    //double h_trap = (xmax-xmin)/static_cast<double>(N_trapezio);
    int N_simpson = 1001;
    //double h_simp = (xmax-xmin)/static_cast<double>(N_simpson);
    int N_romberg = pow(2, 7)+1;
    //double h_romb = (xmax-xmin)/static_cast<double>(N_romberg);
    int N_laguerre = 8;
    int N_hermite = 100;


    double mid = midpoint(xmin, xmin+h, f);
    /*double ris_trap = midpoint(xmin, xmin+h_trap, f) + trapezio(xmin+h_trap, xmax, N_trapezio, f);
    double ris_simp = midpoint(xmin, xmin+h_simp, f) + simpson(xmin+h_simp, xmax, N_simpson, f);
    double ris_romb = midpoint(xmin, xmin+h_romb, f) + romberg(xmin+h_romb, xmax, N_romberg, f);*/
    double ris_trap = mid + trapezio(xmin+h, xmax, N_trapezio, f);
    double ris_simp = mid + simpson(xmin+h, xmax, N_simpson, f);
    double ris_romb = mid + romberg(xmin+h, xmax, N_romberg, f);
    double ris_lag = laguerre(N_laguerre, f_laguerre);
    double ris_her = 0.5*hermite(N_hermite, f_hermite);


    cout << setprecision(9) << ris_trap << "\t" << ris_simp << "\t" << ris_romb << "\t" << endl;
    cout << setprecision(9) << ris_lag << "\t" << ris_her << "\t" << endl;


    return 0;
}