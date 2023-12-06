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
    int N = 10000;
//riffaccio passando vettori come reference

    double x_true = -0.5440211108893698134047476618513772816836430129162238915741840126167572096404934257070756738949832161582938242382628322855195;
    double v_true = -0.8390715290764524522588639478240648345199301651331685468359537310487925868662707684009337127604221389274510544053502436236984;

    vector<double> x(2);
    vector<double> v(2);

    vector<double> punti_eulero;
    vector<double> punti_rk2;
    vector<double> punti_rk4;
    vector<double> passo;


    for (int i = 100; i<N; i++){
    
        passo.push_back(static_cast<double>(i)/t);

        punti_eulero.push_back(Eulero_2(theta0, z0, i, t, f_x, f_v));

        punti_rk2.push_back(runge_kutta2_2(theta0, z0, i, t, f_x, f_v));

        punti_rk4.push_back(runge_kutta4_2(theta0, z0, i, t, f_x, f_v));

    }

    cout << setprecision(20) << punti_eulero[punti_eulero.size()-1] << "\t" << punti_rk2[punti_rk2.size()-1] << "\t" << punti_rk4[punti_rk4.size()-1]<< endl;


    fstream file;
    file.open("punti.dat", ios_base::out);
//viene un punto a 10000 non so perchè
    for(int i=0; i<passo.size(); i++){
        file << setprecision(100) << passo[i] << "\t" << abs(punti_eulero[i] - x_true) << "\t" << abs(punti_rk2[i] - x_true) << "\t"<< abs(punti_rk4[i] - x_true) << endl;
    }
    file.close();

    return 0;

}
