#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "differenziali2.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "time.h"
#include "vector"

#define n 3

using namespace std;

double f_x ( vector<double>& x, double t){
    return -10*(x[0]-x[2]); 
}

double f_v (vector<double>& x, double t){
    return -x[0]*x[2] + 28*x[0] - x[1];
}

double f_z (vector<double>& x, double  t){
    return x[0]*x[1] - (8./3.)*x[3];
}

int main (){

    vector<double> iniziali (n);

    iniziali[0] = 0.;
    iniziali[1] = 0.;
    iniziali[2] = 1.;
    double t = 100;
    int N = 100000;

    double (*f[n]) (vector<double>&, double) = {f_x, f_v, f_z};

    eulero(iniziali, t, N, f);
    runge_kutta_2(iniziali,  t, N, f);
    runge_kutta_4(iniziali, t, N, f);




    return 0;
}