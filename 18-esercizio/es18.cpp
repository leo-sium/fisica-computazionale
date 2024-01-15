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
#include "time.h"
#include "vector"

#define n 6

using namespace std;

double m1 = 0.3;
double m2 = 0.3;
double m3 = 0.3;

vettore f_r1 (vector<vettore>& v){
    return v[0];
}

vettore f_v1 (vector<vettore>& r){
    vettore r12 = r[0] - r[1];
    vettore r13 = r[0] - r[2];
    return r12*(-m2)/pow(r12.modulo(), 3) - r13*(-m3)/pow(r13.modulo(), 3);
}

vettore f_r2 (vector<vettore>& v){
    return v[1];
}

vettore f_v2(vector<vettore>& r){
    vettore r21 = r[1] - r[0];
    vettore r23 = r[1] - r[2];
    return r21*(-m1)/pow(r21.modulo(), 3) - r23*(-m3)/pow(r23.modulo(), 3);
}

vettore f_r3 (vector<vettore>& v){
    return v[2];
}

vettore f_v3(vector<vettore>& r){
    vettore r31 = r[2] - r[0];
    vettore r32 = r[2] - r[1];
    return r31*(-m1)/pow(r31.modulo(), 3) - r32*(-m2)/pow(r32.modulo(), 3);
}

int main (){

    vettore r1(1, 0, 0);
    vettore r2(-1, 0, 0);
    vettore r3(0, 0, 0);

    vettore v1(0, 0.15, -0.15);
    vettore v2(0, -0.15, 0.15);
    vettore v3(0, 0, 0);

    vector<vettore> r{r1, r2, r3};
    vector<vettore> v{v1, v2, v3};

    double t = 10;
    int N = 1000;

    vettore (*f[n]) (vector<vettore>&) = {f_r1, f_r2, f_r3, f_v1, f_v2, f_v3};
    
    runge_kutta_4(r, v, t, N, f);

    return 0;

}