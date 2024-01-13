#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"
#include "fstream"
#include "iomanip"
#include <cstdlib>

using namespace std;

vector<double> somma_vettori(vector<double>& v1, vector<double>& v2){

    if(v1.size() != v2.size()) {
        cout << "i vettori hanno dimensione diversa"<< endl;
        exit(EXIT_FAILURE);
    }

    vector<double> v3 (v1.size());

    for(int i=0; i<v1.size(); ++i){
        v3[i] = v1[i] + v2[i];
    }
    return v3;
} 

vector<double> calcola_k(vector<double>& v1, vector<double>& v2){

    vector<double> temp (v2.size());
    for (int i=0; i<v2.size(); ++i){
        temp[i] = v2[i]/2.;
    }
    return somma_vettori(v1, temp);
}

//ragiono sul numero dei passi, che di sicuro così mi fermo probabilmente un passo prima rispetto all'effettivo tempo finale

void eulero( vector<double>& iniziali, double tmax, int N_passi, double (*f[])(vector<double>&, double)){

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

void runge_kutta_2( vector<double>& iniziali, double tmax, int N_passi, double (*f[])(vector<double>&, double)){

    double h = tmax/static_cast<double>(N_passi);
    double t=h;
    int  n = iniziali.size();

    vector<vector<double>> punti (N_passi, vector<double> (n, 0.0));
    vector<vector<double>> k (2, vector<double>(n, 0.0));
    vector<double> temp(n);

    for(int i=0; i<n; i++){
        punti[0][i] = iniziali[i];
    }

    for (int i=0; i<N_passi-1; ++i){
        for (int j=0; j<n; ++j) k[0][j] = h*(f[j])(punti[i],  t);
        temp = calcola_k(punti[i], k[0]);
        for (int j=0; j<n; ++j) k[1][j] = h*(f[j])( temp, t+h/2.);
        for (int j=0; j<n; ++j) punti[i+1][j] = punti[i][j] + k[1][j];
        t+=h;
    }

    fstream file;
    file.open("punti_rk2.dat", ios_base::out);
    for(int i=0; i<N_passi; ++i){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t";
        for (int j=0; j<n; ++j){
            file<< setprecision(100) << punti[i][j] << "\t"; 
        }
        file<< endl;
    }

}

void runge_kutta_4( vector<double>& iniziali, double tmax, int N_passi, double (*f[])(vector<double>&, double)){

    double h = tmax/static_cast<double>(N_passi);
    double t=h;
    int  n = iniziali.size();

    vector<vector<double>> punti (N_passi, vector<double> (n, 0.0));
    vector<vector<double>> k (4, vector<double>(n, 0.0));
    vector<double> temp(n);

    for(int i=0; i<n; i++){
        punti[0][i] = iniziali[i];
    }

    for (int i=0; i<N_passi-1; ++i){

        for (int j=0; j<n; ++j) k[0][j] = h*(f[j])(punti[i],  t);
        temp = calcola_k(punti[i], k[0]);
        for (int j=0; j<n; ++j) k[1][j] = h*(f[j])( temp, t+h/2.);
        temp = calcola_k(punti[i], k[1]);
        for (int j=0; j<n; ++j) k[2][j] = h*(f[j])( temp, t+h/2.);
        temp = somma_vettori(punti[i], k[2]);
        for (int j=0; j<n; ++j) k[3][j] = h*(f[j])(temp,  t+h);
        for (int j=0; j<n; ++j) punti[i+1][j] = punti[i][j] + 1./6.*(k[0][j] + 2*k[1][j] + 2*k[2][j] + k[3][j]);
        t+=h;
    }
    fstream file;
    file.open("punti_rk4.dat", ios_base::out);
    for(int i=0; i<N_passi; ++i){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t";
        for (int j=0; j<n; ++j){
            file<< setprecision(100) << punti[i][j] << "\t"; 
        }
        file<< endl;
    }
}

#endif