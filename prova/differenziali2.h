#ifndef differenziali2_h
#define differenziali2_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"
#include "fstream"
#include "iomanip"

using namespace std;

//ragiono sul numero dei passi, che di sicuro così mi fermo probabilmente un passo prima rispetto all'effettivo tempo finale

void eulero( vector<double>& iniziali, double tmax, int N_passi, double (*f[2])(vector<double>&, double)){

    double h = tmax/static_cast<double>(N_passi);
    double t=h;
    int  n = iniziali.size();

    vector<vector<double>> punti (N_passi, vector<double> (n, 0.0));

    for(int i=0; i<n; i++){
        punti[0][i] = iniziali[i];
    }

    for (int i=0; i<N_passi-1; ++i){
        for (int j=0; j<n; ++j){
            punti[i+1][j] = punti[i][j] + h*(f[j](punti[i], t));
        }
        t+=h;
    }

    fstream file;
    file.open("punti_eulero.dat", ios_base::out);
    for(int i=0; i<N_passi; ++i){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t";
        for (int j=0; j<n; ++j){
            file<< setprecision(100) << punti[i][j] << "\t"; 
        }
        file<< endl;
    }

}


#endif