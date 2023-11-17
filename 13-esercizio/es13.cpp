#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "time.h"
#include "vector"

using namespace std;

//non posso  usare la funzione inversa perchè non ho una cumulativa, dovrò usare la accept /reject

double f_cos (double x){
    return x * cos(x);
}

double f_cos_im ( double x){
    return asin(x);
}

double f_sin(double x){
    return x*sin(x);
}

double f_sin_im(double x){
    return acos(1-x);
}


int main(){

    srand(time(0));
    int N = pow(10,5);
    double x,y;
    double xmin = 0.;
    double xmax = M_PI/2.;
    double xmax_s = M_PI;
    vector<double> punti;

    double I_mc = monte_carlo(xmin, xmax, N, f_cos);

    double I_imp = monte_carlo(0, 1, N, f_cos_im);

    double I2_mc = monte_carlo(xmin, xmax_s, N, f_sin);

    double I2_imp = monte_carlo(0, 2, N, f_sin_im);

    cout << I_mc << "\t" << I_imp << "\t" << I2_mc << "\t" "\t" << I2_imp << endl;


    return 0;

}