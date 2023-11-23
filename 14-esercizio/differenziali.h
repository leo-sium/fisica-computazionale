#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

//ragionno molto su i<t o i<=t
/*
void Eulero2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z), double f_v(double x, double z) ){

    if (x.size() != 2 || v.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    for (double i=0; i<t; i+=h){
        x[1]= x+ h*(f_x(x, v));
        v[1]=v + h*(f_v(x, v));
        x=x[1];
        v=v[1];
        
    }

    return;
}
*/
/*
void Eulero2V2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double v), double f_v(double x, double v) ){

    if(t!=0){
        t = t-h;
        Eulero2V2 (x, v, h, t, f_x, f_v );
    }

    x[1] = x + h*(f_x(x, v));
    v[1] = v + h*(f_v(x, v));

    x= x[1];
    v = v[1];

    return;

}
*/
/*
void runge_kutta2_2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z), double f_v(double x, double z)){

    if (x.size() != 2 || v.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    vector<double> kx(2);
    vector<double> kv(2);
    double i=0;


    while(i<t){

        kx_1 = h*f_x(x, v);
        kv_1 = h*f_v(x, v);

        kx_2 = h*f_x(x+kx_1/2., v+kv_1/2.);
        kv_2 = h*f_v(x+kx_1/2., v+kv_1/2.);

        x[1] = x + kx_2;
        v[1] = v + kv_2;

        x = x[1];
        v = v[1];

        i= i+h;
    }
    return;
}
*/
    void runge_kutta4_2 (double x0, double v0, double h, double t, double f_x(double x, double v), double f_v(double x, double v)){

    double i = 0;

    double kx_1, kx_2, kx_3, kx_4, kv_1, kv_2, kv_3, kv_4;

    double x= x0;
    double v= v0;

    while(i<t){

        kx_1 = h*f_x(x, v);
        kv_1 = h*f_v(x, v);

        kx_2 = h*f_x(x+kx_1/2., v+kv_1/2.);
        kv_2 = h*f_v(x+kx_1/2., v+kv_1/2.);

        kx_3 = h*f_x(x+kx_2/2., v+kv_2/2.);
        kv_3 = h*f_v(x+kx_2/2., v+kv_2/2.);

        kx_4 = h*f_x(x+kx_3, v+kv_3);
        kv_4 = h*f_v(x+kx_3, v+kv_3);

        x = x + 1./6.*(kx_1 + 2*kx_2 + 2*kx_3 + kx_4);
        v = v + 1./6.*(kv_1 + 2*kv_2 + 2*kv_3 + kv_4);

        i= i+h;
    }

    return;
}







#endif