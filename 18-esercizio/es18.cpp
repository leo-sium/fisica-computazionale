#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "differenziali.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "vector"

#define n 6


// sto usando una pessima gestione della memoria, vedo di migliorare, magari usando le reference/alias
using namespace std;

vector<double> m {1.6, 0.3, 0.3};


vettore f_r1 (vector<vettore>& v){
    return v[0];
}

vettore f_v1 (vector<vettore>& r){
    vettore r12 = r[0] - r[1];
    vettore r13 = r[0] - r[2];
    return r12*(-m[1])/pow(r12.modulo(), 3) + r13*(-m[2])/pow(r13.modulo(), 3);
}

vettore f_r2 (vector<vettore>& v){
    return v[1];
}

vettore f_v2(vector<vettore>& r){
    vettore r21 = r[1] - r[0];
    vettore r23 = r[1] - r[2];
    return r21*(-m[0])/pow(r21.modulo(), 3) + r23*(-m[2])/pow(r23.modulo(), 3);
}

vettore f_r3 (vector<vettore>& v){
    return v[2];
}

vettore f_v3(vector<vettore>& r){
    vettore r31 = r[2] - r[0];
    vettore r32 = r[2] - r[1];
    return r31*(-m[0])/pow(r31.modulo(), 3) + r32*(-m[1])/pow(r32.modulo(), 3);
}

int main (){

    vettore r1(1, 0, 0);
    vettore r2(-1, 0, 0);
    vettore r3(0, 0, 0);

    vettore v1(0, 0.4, 0.);
    vettore v2(0, -0.8, 0.7);
    vettore v3(0, -0.8, -0.7);

    vector<vettore> r_iniziale{r1, r2, r3};
    vector<vettore> v_iniziale{v1, v2, v3};
    vector<vector<vettore>> r, v;
    
    double temp = 0;

    double t = 100;
    int N = 1000000;
    double h = t/static_cast<double>(N);
    double r12, r13, r23;


    vector<double> K(N);
    vector<double> U(N);
    vector<double> E(N);


    double G = 6.67*pow(10, -11 );

    vettore (*f[n]) (vector<vettore>&) = {f_r1, f_r2, f_r3, f_v1, f_v2, f_v3};
    
    vector<vector<vector<vettore>>> risultati = runge_kutta_4(r_iniziale, v_iniziale, t, N, f);

    r = risultati[0];
    v = risultati[1];
 

    for (int i=0; i< N; ++i){
        for(int j=0; j<3; ++j){
           K[i] += pow(v[i][j].modulo(), 2)*(m[j]/2.);
        }
//trovo un modo di farlo più elegante

        r12 = (r[i][0] - r[i][1]).modulo();

        U[i] = -(G*m[0]*m[1]/(r[i][1]-r[i][0]).modulo() + G*m[0]*m[2]/(r[i][2]-r[i][0]).modulo() + G*m[2]*m[1]/(r[i][1]-r[i][2]).modulo());
        E[i] = U[i]+K[i];
    }

    fstream file;
    file.open("energia.dat", ios_base::out);
    for(int i=0; i<N; ++i){
        file<< setprecision(6) << static_cast<double>(i)*h << "\t";
        file<< setprecision(6) << K[i] << "\t" << U[i] << "\t" << E[i] << endl;
    }
    file.close();

    return 0;

}