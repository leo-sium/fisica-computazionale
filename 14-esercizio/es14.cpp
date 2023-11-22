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

using namespace std;

double f_x (double x, double v, double h){
    double ris = v;
    return ris;
}

double f_v ( double x, double v, double h){
    double ris = -x;
    return ris;
}


int main (){
    double theta0 = 0;
    double z0 = 1.;
    double h = 0.0001;
    double t = 10;

    vector<double> x(2);
    x[0]= theta0;
    vector<double> v(2);
    v[0]=z0;

/*
    for (double i=0; i<t; i+=h){
        th[1]=(theta(th[0], z[0], h));
        z[1]=(zeta(th[0], z[0], h));
        th[0]=th[1];
        z[0]=z[1];

    }
*/

    Eulero2(x, v, h, t, f_x, f_v);

    cout << x[0] << "\t" << v[0] << endl;

    x[0]= theta0;
    v[0]=z0;

    runge_kutta2_2(x, v, h, t, f_x, f_v);

    cout << x[0] << "\t" << v[0] << endl;







    return 0;
}
