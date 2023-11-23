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
    double ris = -x;
    return ris;
}


int main (){
    double theta0 = 0;
    double z0 = 1.;
    double h = 0.0001;
    double t = 10;


    double x_true = -0.5440211108893698134047476618513772816836430129162238915741840126167572096404934257070756738949832161582938242382628322855195;
    double v_true = -0.8390715290764524522588639478240648345199301651331685468359537310487925868662707684009337127604221389274510544053502436236984;

    vector<double> x(2);
    vector<double> v(2);

    vector<vector<double>> punti_eulero;
    vector<vector<double>> punti_rk2;
    vector<vector<double>> punti_rk4;
    vector<double> p(2);
    vector<double> sium;
    vector<double> passo;



    for(int N = 100; N<= 10000; N+=1){

        h= t/static_cast<double>(N-1);

        x[0]= theta0;    
        v[0]=z0;

        Eulero2(x, v, h, t, f_x, f_v);

        passo.push_back(N);
        p[0] = abs(x[1] - x_true);
        p[1] = abs(v[1] - v_true);
        punti_eulero.push_back(p);
/*
        x[0]= theta0;    
        v[0]=z0;
        
        Eulero2V2(x, v, h, t, f_x, f_v);

        sium.push_back(x[0]);
    */

        x[0]= theta0;
        v[0]=z0;

        runge_kutta2_2(x, v, h, t, f_x, f_v);

        p[0] = abs(x[1] - x_true);
        p[1] = abs(v[1] - v_true);
        punti_rk2.push_back(p);

        x[0]= theta0;
        v[0]=z0;

        runge_kutta4_2(x, v, h, t, f_x, f_v);

        p[0] = abs(x[1] - x_true);
        p[1] = abs(v[1] - v_true);
        punti_rk4.push_back(p);
    }

    fstream file;
    file.open("punti.dat", ios_base::out);
//viene un punto a 10000 non so perchè
    for(int i=0; i<passo.size(); i++){
        file << setprecision(100) << passo[i] << "\t" << punti_eulero[i][0]  << "\t" << punti_rk2[i][0] << "\t"<< punti_rk4[i][0] << "\t"<< sium[i] << endl;
    }
    file.close();

    return 0;

}
