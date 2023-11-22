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

double theta (double th, double z, double h){
    double ris = th + h*z;
    return ris;
}

double zeta ( double th, double z, double h){
    double ris = z - h*th;
    return ris;
}


int main (){
    double theta0 = 0;
    double z0 = 1.;
    double h = 0.0001;
    double t = 10;

    vector<double> th(2);
    th[0]= theta0;
    vector<double> z(2);
    z[0]=z0;
/*
    for (double i=0; i<t; i+=h){
        th[1]=(theta(th[0], z[0], h));
        z[1]=(zeta(th[0], z[0], h));
        th[0]=th[1];
        z[0]=z[1];

    }
*/

    Eulero2(th, z, h, t, theta, zeta);


    cout << z[0] << "\t" << th[0] << endl;




    return 0;
}
