#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

//ragionno molto su i<t o i<=t
void Eulero (vector<vector<double>>& punti, int N, double t, double f_x(double x, double y, double z), double f_y(double x, double y, double z), double f_z(double x, double y, double z) ){

    double h = t/static_cast<double>(N);

    for (int i=0; i<N; i++){
        punti[0][i+1] = punti[0][i] + h*(f_x(punti[0][i], punti[1][i], punti[2][i]));
        punti[1][i+1] = punti[1][i] + h*(f_y(punti[0][i], punti[1][i], punti[2][i]));       
    }

    return;
}



void runge_kutta2 (vector<vector<double>>& punti, int N, double t, double f_x(double x, double y, double z), double f_y(double x, double y, double z), double f_z(double x, double y, double z) ){

    vector<double> kx (2);
    vector<double> ky (2);
    vector<double> kz (2);


    double h = t/static_cast<double>(N);

    for (int i=0; i<N; i++){

        kx[0] = h*f_x(punti[0][i], punti[1][i], punti[2][i]);
        ky[0] = h*f_y(punti[0][i], punti[1][i], punti[2][i]);
        kz[0] = h*f_z(punti[0][i], punti[1][i], punti[2][i]);


        kx[1] = h*f_x(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);
        ky[1] = h*f_y(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);
        ky[1] = h*f_z(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);

        punti[0][i+1] = punti[0][i] + kx[1];
        punti[1][i+1] = punti[1][i] + ky[1];
        punti[2][i+1] = punti[2][i] + kz[1];

    }
    return;
}

void runge_kutta4 (vector<vector<double>>& punti, int N, double t, double f_x(double x, double y, double z), double f_y(double x, double y, double z), double f_z(double x, double y, double z) ){

    double h = t/static_cast<double>(N);

    vector<double> kx (4);
    vector<double> ky (4);
    vector<double> kz (4);

    for (int i=0; i<N; i++){

        kx[0] = h*f_x(punti[0][i], punti[1][i], punti[2][i]);
        ky[0] = h*f_y(punti[0][i], punti[1][i], punti[2][i]);
        kz[0] = h*f_z(punti[0][i], punti[1][i], punti[2][i]);

        kx[1] = h*f_x(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);
        ky[1] = h*f_y(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);
        ky[1] = h*f_z(punti[0][i]+kx[0]/2., punti[1][i]+ky[0]/2., punti[2][i]+kz[0]/2.);


        kx[2] = h*f_x(punti[0][i]+kx[1]/2., punti[1][i]+ky[1]/2., punti[2][i]+kz[1]/2.);
        ky[2] = h*f_y(punti[0][i]+kx[1]/2., punti[1][i]+ky[1]/2., punti[2][i]+kz[1]/2.);
        ky[2] = h*f_z(punti[0][i]+kx[1]/2., punti[1][i]+ky[1]/2., punti[2][i]+kz[1]/2.);


        kx[3] = h*f_x(punti[0][i]+kx[2], punti[1][i]+ky[2], punti[2][i]+kz[3]);
        ky[3] = h*f_y(punti[0][i]+kx[2], punti[1][i]+ky[2], punti[2][i]+kz[3]);
        ky[3] = h*f_z(punti[0][i]+kx[2], punti[1][i]+ky[2], punti[2][i]+kz[3]);


        punti[0][i+1] = punti[0][i] + 1./6.*(kx[0] + 2*kx[1] + 2*kx[2] + kx[3]);
        punti[1][i+1] = punti[1][i] + 1./6.*(ky[0] + 2*ky[1] + 2*ky[2] + ky[3]);
        punti[2][i+1] = punti[2][i] + 1./6.*(kz[0] + 2*kz[1] + 2*kz[2] + ky[3]);
    }

    return;
}

#endif