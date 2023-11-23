#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

void Eulero2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z), double f_v(double x, double z) ){

    if (x.size() != 2 || v.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    for (double i=0; i<t; i+=h){
        x[1]= x[0]+ h*(f_x(x[0], v[0]));
        v[1]=v[0] + h*(f_v(x[0], v[0]));
        x[0]=x[1];
        v[0]=v[1];
        
    }

    return;
}

    void runge_kutta2_2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z), double f_v(double x, double z)){

    if (x.size() != 2 || v.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    vector<double> kx(2);
    vector<double> kv(2);

    for (double i=0; i<t; i+=h){

        kx[0] = h*f_x(x[0], v[0]);
        kv[0] = h*f_v(x[0], v[0]);

        kx[1] = h*f_x(x[0]+kx[0]/2., v[0]+kv[0]/2.);
        kv[1] = h*f_v(x[0]+kx[0]/2., v[0]+kv[0]/2.);

        x[1] = x[0] + kx[1];
        v[1] = v[0] + kv[1];

        x[0] = x[1];
        v[0] = v[1];
    }
    return;
}

    void runge_kutta4_2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z), double f_v(double x, double z)){

            if (x.size() != 2 || v.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    vector<double> kx(4);
    vector<double> kv(4);

    for (double i=0; i<t; i+=h){

        kx[0] = h*f_x(x[0], v[0]);
        kv[0] = h*f_v(x[0], v[0]);

        kx[1] = h*f_x(x[0]+kx[0]/2., v[0]+kv[0]/2.);
        kv[1] = h*f_v(x[0]+kx[0]/2., v[0]+kv[0]/2.);

        kx[2] = h*f_x(x[0]+kx[1]/2., v[0]+kv[1]/2.);
        kv[2] = h*f_v(x[0]+kx[1]/2., v[0]+kv[1]/2.);

        kx[3] = h*f_x(x[0]+kx[2], v[0]+kv[2]);
        kv[3] = h*f_v(x[0]+kx[2], v[0]+kv[2]);

        x[1] = x[0] + 1./6.*(kx[0] + 2*kx[1] + 2*kx[2] + kx[3]);
        v[1] = v[0] + 1./6.*(kv[0] + 2*kv[1] + 2*kv[2] + kv[3]);

        x[0] = x[1];
        v[0] = v[1];
    }

    return;
}







#endif