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

double f_x (double x, double y, double z){
    return  -10*(x-z);
}

double f_y ( double x, double y, double z){
    return  -x*z + 28*x -y;
}

double f_z (double x, double y, double z){
    return x*y - (8./3.)*z;
}

int main (){
    double x0 = 0;
    double y0 = 0;
    double z0 = 1;
    double t = 100;
    int N = 100000;
    double h = t/static_cast<double>(N);

    vector<vector<double>> eulero (N, vector<double> (3, 0.0));
    eulero[0][0] = x0;
    eulero[1][0] = y0;
    eulero[2][0] = z0;

    vector<vector<double>> rk2 (N, vector<double> (3, 0.0));
    rk2[0][0] = x0;
    rk2[1][0] = y0;
    rk2[2][0] = z0;

    vector<vector<double>> rk4 (N, vector<double> (3, 0.0));
    rk4[0][0] = x0;
    rk4[1][0] = y0;
    rk4[2][0] = z0;


    Eulero(eulero, N, t, f_x, f_y, f_z);

    runge_kutta2(rk2, N, t, f_x, f_y, f_z);

    runge_kutta4(rk4, N,  t, f_x, f_y, f_z);

    fstream file;
    file.open("punti_1.dat", ios_base::out);

    for (int i=0; i<N; i++){
        file<< setprecision(100) << static_cast<double>(i)*h << "\t" << eulero[0][i] << "\t" << eulero[1][i] << "\t" << eulero[2][i] <<"\t" << rk2[0][i] << "\t" << rk2[1][i]<< "\t" << rk2[2][i] << rk4[0][i] << "\t" << rk4[1][i] << "\t" << rk4[2][i] << endl;
    }
    file.close();

    return 0;

}