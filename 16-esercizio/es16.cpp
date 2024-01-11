#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "differenziali.h"
#include <cmath>
#include <fstream>
#include <math.h>
#include <ostream>
#include "vector"

using namespace std;

double f_x (double x, double v, double t){
    double ris = v;
    return ris;
}

double f_v ( double x, double v, double t){

    double A = 0.5;
    double B = 0.5;
    double gamma = 0.03;
    double ris = - gamma*v -( A - B*cos(t))*sin(x);
    return ris;
}

int main (){
    double theta0 = 0;
    double z0 = 0.1;
    double t = 100;
    int N = 100000;
    double h = t/static_cast<double>(N);

    vector<double> x_eulero (N);
    vector<double> v_eulero (N);
    x_eulero[0] = theta0;
    v_eulero[0] = z0;

    vector<double> x_rk2 (N);
    vector<double> v_rk2 (N);
    x_rk2[0] = theta0;
    v_rk2[0] = z0;

    vector<double> x_rk4 (N);
    vector<double> v_rk4 (N);
    x_rk4[0] = theta0;
    v_rk4[0] = z0;

    Eulero_2_t(x_eulero, v_eulero, N, t, f_x, f_v);

    runge_kutta2_2_t(x_rk2, v_rk2, N, t, f_x, f_v);

    runge_kutta4_2_t(x_rk4, v_rk4, N,  t, f_x, f_v);

    fstream file;
    file.open("punti_1.dat", ios_base::out);

    for (int i=0; i<N; i++){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t" << x_eulero[i] << "\t" << v_eulero[i] << "\t" << x_rk2[i] << "\t" << v_rk2[i]<< "\t" << x_rk4[i] << "\t" << v_rk4[i] << endl;
    }
    file.close();

    return 0;

}