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

#define n 2

using namespace std;

double f_x ( vector<double>& x, double t){
    return x[1];
}

double f_v (vector<double>& x, double t){
    return - sin(x[0]);
}

int main (){

    vector<double> iniziali (n);

    iniziali[0] = 0.;
    iniziali[1] = 1.;
    double t = 100;
    int N = 100000;

    double (*f[n]) (vector<double>&, double) = {f_x, f_v};

    eulero(iniziali, t, N, f);




    return 0;
}