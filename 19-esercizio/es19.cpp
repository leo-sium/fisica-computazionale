#include "iostream"
#include <cmath>
#include <math.h>
#include <ostream>
#include "vector"
#include "zeri.h"

using namespace std;

double f ( double x){
    return 2*pow(x,2) - 3*x + 1;
    //return pow(x,3) - 4*pow(x,2) - x + 6;
}

double f_der (double x){
    return 4*x - 3;
}

double g (double x){
    return (46189*pow(x,10) - 109395*pow(x,8) + 90090*pow(x,6) - 30030*pow(x,4) + 3465*pow(x,2) - 63)/256. ;
}

double g_der(double x){
    return (461890*pow(x,9)- 876160*pow(x,7)+ 540540*pow(x,5)-120120*pow(x,3)+6930*x)/256.;
}


int main (int argc, char**argv){

    double xmin = -2;
    double xmax = 2.;
    double precisione1 = 0.000001;
    double precisione2 = 0.000001;

    vector<vector<double>> intervalli = bracketing(xmin, xmax, g);

    if(trova_segno(f(xmin), f(xmax))== 1 &&  intervalli.size()==1){
        cout << "non ci sono zeri nell'intervallo" << endl;
        return 0;
    }

    vector<double> zeri_bi = bisezione (intervalli, precisione1, g);
    vector<double> zeri_newton = Newton(intervalli, precisione2,g, g_der);

    for (int i=0; i<intervalli.size(); ++i){
        cout << "intervallo " << i+1 << ": \t"<< intervalli[i][0] << "\t" << intervalli[i][1] << endl;
    }
    cout << "con il metodo di bisezione:" << endl;
    for (int i=0; i< zeri_bi.size(); ++i){
        cout << "lo zero " << i+1 << " è: " << zeri_bi[i] << endl;
    }

    cout << "con il metodo di Newton-Raphson:" << endl;
    for (int i=0; i< zeri_newton.size(); ++i){
        cout << "lo zero " << i+1 << " è: " << zeri_newton[i] << endl;
    }
    return 0;
}