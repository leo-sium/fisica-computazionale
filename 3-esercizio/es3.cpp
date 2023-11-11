#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <math.h>

using namespace std;


double f (double x){
    double ris = pow(x, 7)*exp(-x);
    return ris;
}

double flegendre (double x){
    double ris = (5./2.)*pow(((5./2.)*(x+1.)), 7)*exp(-(5./2.)*(x+1.));
    return ris;
}

//rendo questa cosa più bella

double flaguerre1 (double x){
    double ris = pow(x, 7);
    return ris;
}

double flaguerre2(double x){
    double ris = pow(x+5, 7)*exp(-5);
    return ris;
}

// mostro tutti i risultati, tutti gli andamenti in funzione di N e i risultati dei vari integrali ed errori al variare di N
// mostro anche che per diversi valori di N laguerre 2 fa schifo, mentr 4 e 8 sono esatti e robe del genere 

int main (int argc, char** argv){
    
    int N= 2;
    double xmin = 0;
    double xmax = 5;
    //bool V = true;

    //double ris_romb = romberg (xmin, xmax, 17, f);
    //double ris_trap = trapezio(xmin, xmax, 2, f);
    //double ris_simp = simpson(xmin, xmax, N, f);
    //double ris_leg = legendre(N, flegendre);
    double ris_lag =  laguerre(N, flaguerre1) - laguerre ( N, flaguerre2);

    cout << ris_lag << endl;

    return 0;
}