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

double f_x (double x, double v){
    double ris = v;
    return ris;
}

double f_v ( double x, double v){
    double gamma = 2.;
    double ris = -sin(x) - gamma*v;
    return ris;
}

int main (){
    double theta0 = 0;
    double z0 = 1.;
    double t = 10;
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

    Eulero_2(x_eulero, v_eulero, N, t, f_x, f_v);

    runge_kutta2_2(x_rk2, v_rk2, N, t, f_x, f_v);

    runge_kutta4_2(x_rk4, v_rk4, N,  t, f_x, f_v);

    fstream file;
    file.open("punti_2.dat", ios_base::out);

    for (int i=0; i<N; i++){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t" << x_eulero[i] << "\t" << v_eulero[i] << "\t" << x_rk2[i] << "\t" << v_rk2[i]<< "\t" << x_rk4[i] << "\t" << v_rk4[i] << endl;
    }
    file.close();

    return 0;

}