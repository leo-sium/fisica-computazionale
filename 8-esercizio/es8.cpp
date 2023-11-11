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

//DA FNIRE IL MONTE CARLO

double f_det(vector<double> x){
    int M = x.size();
    double sum = 0.;
    for (int i=0; i< M; i++){
        sum += pow(x.at(i), 2);
    }

    double ris = sqrt(1-sum);
    //cout << setprecision(7) << ris << endl;

    return ris;
}

double f_mc(vector<double> x){
    int M = x.size();
    double sum = 0.;
    for (int i=0; i< M; i++){
        sum += pow(x.at(i), 2);
    }

    if ( sum < 1.){
        double ris = sqrt(1. - sum);
        return ris;
    }

    else {
        double ris = 0;
        return ris;
    }
}

void Genera_punti(vector<double>& coord, vector<double>& p, vector<vector<double>>& punti, int k, int indice) {
    if (indice == k) {
        double sum = 0;
        for (int j=0; j< k; j++) {
            sum+= pow(p.at(j), 2);
        }
        if (sum <= 1) {
            punti.push_back(p);
        }
        return;
    }

    for (int i = 0; i < coord.size(); i++) {
        p[indice] = coord[i];
        Genera_punti(coord, p, punti, k, indice+1);
    }
}

int main( int argc, char** argv){

    int M = 8;
    int N_det = 20;
    double xmin = 0.;
    double xmax = 1.;
    double I_det = 0.;
/*
    double h = (xmax-xmin)/(2*N_det);
    vector<vector<double>> punti;
    vector<double> coord;
    vector<double> p(M-1);

        for(int j=0; j<N_det; j++){
            coord.push_back((2*j+1)*h);
        }

    Genera_punti(coord, p, punti, M-1, 0);

    for (int i=0; i<punti.size(); i++){
        I_det += midpoint_multi( punti.at(i) , h, f_det);
    }
    I_det = I_det*pow(2, M);

    cout << I_det << endl;
*/
    int N_mc =  pow(10, 5);
    double I_mc = 0;
    vector<vector<double>> punti_mc;
    vector<double> p_mc(M-1);
    srand(time(0));

    for(int j=0; j< N_mc; j++){
        for (int i=0; i< p_mc.size(); i++){
            p_mc[i] = rand_range(xmin, xmax);
        } 
        punti_mc.push_back(p_mc);
    }

    for (int i=0; i<punti_mc.size();i++){

        I_mc += f_mc(punti_mc[i]);
    }

    I_mc = (I_mc*pow(2., M))/ static_cast<double>(N_mc); //chiedo perchè questa cosa, io genero N^M punti, ma raggruppati in N vettori da M coordinate

    cout <<  I_mc << endl;








    



    return 0;
}