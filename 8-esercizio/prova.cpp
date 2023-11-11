#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cmath>
#include <cstdlib>
#include <math.h>
#include "vector"


using namespace std;

double f(vector<double> x){
    int M = x.size();
    double sum = 0.;
    for (int i=0; i< M; i++){
        sum += pow(x.at(i), 2);
    }

    double ris = sqrt(1-sum);
    cout  << ris << endl;

    return ris;
}

int main(){

    vector<vector<double>> punti;

    vector<double> v1 = {1./6. , 1./6.};
    vector<double> v2 = {3./6., 1./6.};
    vector<double> v3 = {5./6., 1./6.};
    vector<double> v4 = {1./6. , 3./6.};
    vector<double> v5 = {3./6., 3./6.};
    vector<double> v6 = {5./6., 3./6.};
    vector<double> v7 = {1./6. , 5./6.};
    vector<double> v8 = {3./6., 5./6.};

    punti.push_back(v1);
    punti.push_back(v2);
    punti.push_back(v3);
    punti.push_back(v4);
    punti.push_back(v5);
    punti.push_back(v6);
    punti.push_back(v7);
    punti.push_back(v8);

    double sum = 0;

    for (int i=0; i<punti.size(); i++){

        sum += midpoint_multi(punti.at(i), 1./3., f);
        
    }

    double I = sum*8;

    cout << I << endl;



    return 0;
}