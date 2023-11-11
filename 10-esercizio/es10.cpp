#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cstdlib>
#include <math.h>
#include "time.h"

using namespace std;

double f_1 (double x){
    double ris = pow(x, 7)*exp(-x);
    return ris;
}

double f_2(double x){
    double ris = cosh(x);
    return ris;
}

double f_3(double x){
    double ris = pow(x, 2)+ x*sin(4*x);
    return ris;
}

int main (int argc, char** argv){

    double N = pow(10, 5);
    double xmin_1 = 0;
    double xmax_1 = 5;
    double ymin_1 = 0;
    double ymax_1 = f_1(7);

    double I_hm_1 = hit_or_miss(xmin_1, xmax_1, ymin_1, ymax_1, N, f_1);
    double I_mc_1 = monte_carlo(xmin_1, xmax_1, N, f_1 );
    double I_trap_1 = trapezio(xmin_1, xmax_1, N, f_1);

    cout << "primo integrale:" << endl << "metodo monte carlo\t"<< I_mc_1 << endl <<"metodo hit or miss\t" << I_hm_1 << endl << "metodo trapezio\t\t" << I_trap_1 << endl;


    double xmin_2 = 3;
    double xmax_2 = 8;
    double ymin_2 = 0;
    double ymax_2 = f_2(8);

    double I_hm_2 = hit_or_miss(xmin_2, xmax_2, ymin_2, ymax_2, N, f_2);
    double I_mc_2 = monte_carlo(xmin_2, xmax_2, N, f_2 );
    double I_trap_2 = trapezio(xmin_2, xmax_2, N, f_2);

    cout << "secondo integrale:"<< endl << "metodo monte carlo \t"<< I_mc_2 << endl << "metodo hit or miss\t" << I_hm_2 << endl << "metodo trapezio\t\t" << I_trap_2 << endl;

    double xmin_3 = -1;
    double xmax_3 = 8;
    double ymin_3 = 0;
    double ymax_3 = f_3(8);

    double I_hm_3 = hit_or_miss(xmin_3, xmax_3, ymin_3, ymax_3, N, f_3);
    double I_mc_3 = monte_carlo(xmin_3, xmax_3, N, f_3 );
    double I_trap_3 = trapezio(xmin_3, xmax_3, N, f_3);

    cout << "terzo integrale:" << endl << "metodo monte carlo\t"<< I_mc_3 << endl << "metodo hit or miss\t" << I_hm_3 << endl << "metodo trapezio\t\t" << I_trap_3 << endl;

    //urlo del sium

    return 0;
}