#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"

using namespace std;

void Eulero2 (vector<double>& x, vector<double>& v, double h, double t, double f_x(double x, double z, double h), double f_v(double x, double z, double h) ){

    if (x.size() != 2 || x.size() != 2){
        cerr << "Errore: inserire vector di dimesione esattamente 2" << endl;
        return;
    }

    for (double i=0; i<t; i+=h){
        x[1]=(f_x(x[0], v[0], h));
        v[1]=(f_v(x[0], v[0], h));
        x[0]=x[1];
        v[0]=v[1];
    }

    return;





}






#endif