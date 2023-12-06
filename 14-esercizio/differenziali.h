#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

//VALUTO SE RIFARE PASSANDO IL VETTORE COME REFERENCE

//ragionno molto su i<t o i<=t
double Eulero_2 (double x0, double v0, int N, double t, double f_x(double x, double z), double f_v(double x, double z) ){

    vector<double> x(2);
    vector<double> v(2);
    x[0]= x0;
    v[0]= v0;

    double h = t/static_cast<double>(N);

    for (int i=0; i<N; i++){
        x[1] = x[0] + h*(f_x(x[0], v[0]));
        v[1] = v[0] + h*(f_v(x[0], v[0]));

        x[0] = x[1];
        v[0] = v[1];
        
    }

    return x[0];
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

double runge_kutta2_2 (double x0, double v0, int N, double t, double f_x(double x, double v), double f_v(double x, double v)){

    double kx_1, kx_2, kv_1, kv_2;

    double h = t/static_cast<double>(N);

    vector<double> x(2);
    vector<double> v(2);
    x[0]= x0;
    v[0]= v0;


    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[0], v[0]);
        kv_1 = h*f_v(x[0], v[0]);

        kx_2 = h*f_x(x[0]+kx_1/2., v[0]+kv_1/2.);
        kv_2 = h*f_v(x[0]+kx_1/2., v[0]+kv_1/2.);

        x[1] = x[0] + kx_2;
        v[1] = v[0] + kv_2;

        x[0] = x[1];
        v[0] = v[1];

        i= i+h;
    }
    return x[1];
}

    double runge_kutta4_2 (double x0, double v0, int N, double t, double f_x(double x, double v), double f_v(double x, double v)){

    double h = t/static_cast<double>(N);

    double kx_1, kx_2, kx_3, kx_4, kv_1, kv_2, kv_3, kv_4;

    vector<double> x(2);
    vector<double> v(2);
    x[0]= x0;
    v[0]= v0;

    for (int i=0; i<N; i++){

        kx_1 = h*f_x(x[0], v[0]);
        kv_1 = h*f_v(x[0], v[0]);

        kx_2 = h*f_x(x[0]+kx_1/2., v[0]+kv_1/2.);
        kv_2 = h*f_v(x[0]+kx_1/2., v[0]+kv_1/2.);

        kx_3 = h*f_x(x[0]+kx_2/2., v[0]+kv_2/2.);
        kv_3 = h*f_v(x[0]+kx_2/2., v[0]+kv_2/2.);

        kx_4 = h*f_x(x[0]+kx_3, v[0]+kv_3);
        kv_4 = h*f_v(x[0]+kx_3, v[0]+kv_3);

        x[1] = x[0] + 1./6.*(kx_1 + 2*kx_2 + 2*kx_3 + kx_4);
        v[1] = v[0] + 1./6.*(kv_1 + 2*kv_2 + 2*kv_3 + kv_4);
    
        x[0] = x[1];
        v[0] = v[1];

        i= i+h;
    }

    return x[1];
}







#endif