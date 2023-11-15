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
#include <vector>
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

    double N = pow(10, 6);

    double I_1 = 672.19323731283680927664797017826546492574500186733942065874221332;
    double I_2 = 1480.4609508621402842169020454124156183872962099931681274803958396;
    double I_3 = 169.09199252874577513825077822164630272078603901996717867845299026;

    double xmin_1 = 0;
    double xmax_1 = 5;
    double ymin_1 = 0;
    double ymax_1 = f_1(7);
    double I_hm_1 = 0;
    double I_mc_1 = 0;
    vector<double> dev_hm_1;
    vector<double> dev_mc_1;

    double xmin_2 = 3;
    double xmax_2 = 8;
    double ymin_2 = 0;
    double ymax_2 = f_2(8);
    double I_hm_2 = 0;
    double I_mc_2 = 0;
    vector<double> dev_hm_2;
    vector<double> dev_mc_2;

    double xmin_3 = -1;
    double xmax_3 = 8;
    double ymin_3 = 0;
    double ymax_3 = f_3(8);
    double I_hm_3 = 0;
    double I_mc_3 = 0;
    vector<double> dev_hm_3;
    vector<double> dev_mc_3;

    for(int i=10000; i<N; i+=10000){

        I_hm_1 = abs( hit_or_miss(xmin_1, xmax_1, ymin_1, ymax_1, i, f_1) - I_1);
        I_mc_1 = abs( monte_carlo(xmin_1, xmax_1, i, f_1 ) - I_1);
        dev_hm_1.push_back(I_hm_1);
        dev_mc_1.push_back(I_mc_1);


        //double I_trap_1 = trapezio(xmin_1, xmax_1, N, f_1);
        //cout << "primo integrale:" << endl << "metodo monte carlo\t"<< I_mc_1 << endl <<"metodo hit or miss\t" << I_hm_1 << endl << "metodo trapezio\t\t" << I_trap_1 << endl;

        I_hm_2 = abs( hit_or_miss(xmin_2, xmax_2, ymin_2, ymax_2, i, f_2) - I_2);
        I_mc_2 = abs( monte_carlo(xmin_2, xmax_2, i, f_2 ) - I_2);
        dev_hm_2.push_back(I_hm_2);
        dev_mc_2.push_back(I_mc_2);
        //double I_trap_2 = trapezio(xmin_2, xmax_2, N, f_2);
        //cout << "secondo integrale:"<< endl << "metodo monte carlo \t"<< I_mc_2 << endl << "metodo hit or miss\t" << I_hm_2 << endl << "metodo trapezio\t\t" << I_trap_2 << endl;

        I_hm_3 = abs( hit_or_miss(xmin_3, xmax_3, ymin_3, ymax_3, i, f_3) - I_3);
        I_mc_3 = abs(monte_carlo(xmin_3, xmax_3, i, f_3 ) - I_3);
        dev_hm_3.push_back(I_hm_3);
        dev_mc_3.push_back(I_mc_3);

        //double I_trap_3 = trapezio(xmin_3, xmax_3, N, f_3);
        //cout << "terzo integrale:" << endl << "metodo monte carlo\t"<< I_mc_3 << endl << "metodo hit or miss\t" << I_hm_3 << endl << "metodo trapezio\t\t" << I_trap_3 << endl;

    }
    int j=10000;
    fstream file_1;
    file_1.open("integrale_1.dat", ios_base::out);
    for (int i=0; i< dev_hm_1.size(); i++){
        file_1 << j << "\t" << setprecision(10)<< dev_hm_1[i] << "\t" << setprecision(10) << dev_mc_1[i] << endl;
        j+=10000;
    }
    file_1.close();

    j=10000;
    fstream file_2;
    file_2.open("integrale_2.dat", ios_base::out);
    for (int i=0; i< dev_hm_2.size(); i++){
        file_2 << j << "\t" << setprecision(10)<< dev_hm_2[i] << "\t" << setprecision(10) << dev_mc_2[i] << endl;
        j+=10000;
    }
    file_2.close();

    j=10000;
    fstream file_3;
    file_3.open("integrale_3.dat", ios_base::out);
    for (int i=0; i< dev_hm_3.size(); i++){
        file_3 << j << "\t" << setprecision(10)<< dev_hm_3[i] << "\t" << setprecision(10) << dev_mc_3[i] << endl;
        j+=10000;
    }
    file_3.close();

    return 0;
}