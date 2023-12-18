#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

//ragionno molto su i<t o i<=t
void Eulero_2 (vector<double>& x, vector<double>& v, int N, double t, double f_x(double x, double z), double f_v(double x, double z) ){

    double h = t/static_cast<double>(N);

    for (int i=0; i<N; i++){
        x[i+1] = x[i] + h*(f_x(x[i], v[i]));
        v[i+1] = v[i] + h*(f_v(x[i], v[i]));       
    }

    return;
}

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

void runge_kutta2_2 (vector<double>& x, vector<double>& v, int N, double t, double f_x(double x, double v), double f_v(double x, double v)){

    double kx_1, kx_2, kv_1, kv_2;

    double h = t/static_cast<double>(N);

    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[i], v[i]);
        kv_1 = h*f_v(x[i], v[i]);

        kx_2 = h*f_x(x[i]+kx_1/2., v[i]+kv_1/2.);
        kv_2 = h*f_v(x[i]+kx_1/2., v[i]+kv_1/2.);

        x[i+1] = x[i] + kx_2;
        v[i+1] = v[i] + kv_2;

    }
    return;
}

void runge_kutta4_2 (vector<double>& x, vector<double>& v, int N, double t, double f_x(double x, double v), double f_v(double x, double v)){

    double h = t/static_cast<double>(N);

    double kx_1, kx_2, kx_3, kx_4, kv_1, kv_2, kv_3, kv_4;

    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[i], v[i]);
        kv_1 = h*f_v(x[i], v[i]);

        kx_2 = h*f_x(x[i]+kx_1/2., v[i]+kv_1/2.);
        kv_2 = h*f_v(x[i]+kx_1/2., v[i]+kv_1/2.);

        kx_3 = h*f_x(x[i]+kx_2/2., v[i]+kv_2/2.);
        kv_3 = h*f_v(x[i]+kx_2/2., v[i]+kv_2/2.);

        kx_4 = h*f_x(x[i]+kx_3, v[i]+kv_3);
        kv_4 = h*f_v(x[i]+kx_3, v[i]+kv_3);

        x[i+1] = x[i] + 1./6.*(kx_1 + 2*kx_2 + 2*kx_3 + kx_4);
        v[i+1] = v[i] + 1./6.*(kv_1 + 2*kv_2 + 2*kv_3 + kv_4);
    }

    return;
}

void Eulero_2_t (vector<double>& x, vector<double>& v, int N, double tmax, double f_x(double x, double z, double t), double f_v(double x, double z, double t) ){

    double h = tmax/static_cast<double>(N);
    //ragiono se parto da t= 0 o t=h
    double t = h;

    for (int i=0; i<N; i++){
        x[i+1] = x[i] + h*(f_x(x[i], v[i], t));
        v[i+1] = v[i] + h*(f_v(x[i], v[i], t)); 
        t += h;      
    }

    return;
}

void runge_kutta2_2_t (vector<double>& x, vector<double>& v, int N, double tmax, double f_x(double x, double v, double t), double f_v(double x, double v, double t)){

    double kx_1, kx_2, kv_1, kv_2;
    double t = 0;

    double h = tmax/static_cast<double>(N);

    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[i], v[i], t);
        kv_1 = h*f_v(x[i], v[i], t);

        kx_2 = h*f_x(x[i]+kx_1/2., v[i]+kv_1/2., t + h/2.);
        kv_2 = h*f_v(x[i]+kx_1/2., v[i]+kv_1/2., t + h/2.);

        x[i+1] = x[i] + kx_2;
        v[i+1] = v[i] + kv_2;

        t+=h;

        }
    return;
}

    void runge_kutta4_2_t (vector<double>& x, vector<double>& v, int N, double tmax, double f_x(double x, double v, double t), double f_v(double x, double v, double t)){

    double h = tmax/static_cast<double>(N);
    double t = 0;

    double kx_1, kx_2, kx_3, kx_4, kv_1, kv_2, kv_3, kv_4;

    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[i], v[i], t);
        kv_1 = h*f_v(x[i], v[i], t);

        kx_2 = h*f_x(x[i]+kx_1/2., v[i]+kv_1/2., t + h/2.);
        kv_2 = h*f_v(x[i]+kx_1/2., v[i]+kv_1/2., t + h/2.);

        kx_3 = h*f_x(x[i]+kx_2/2., v[i]+kv_2/2., t + h/2.);
        kv_3 = h*f_v(x[i]+kx_2/2., v[i]+kv_2/2., t + h/2.);

        kx_4 = h*f_x(x[i]+kx_3, v[i]+kv_3, t + h);
        kv_4 = h*f_v(x[i]+kx_3, v[i]+kv_3, t + h);

        x[i+1] = x[i] + 1./6.*(kx_1 + 2*kx_2 + 2*kx_3 + kx_4);
        v[i+1] = v[i] + 1./6.*(kv_1 + 2*kv_2 + 2*kv_3 + kv_4);

        t += h;
    }

    return;
}







#endif