#include "iostream"
#include "cmath"
#include <cmath>
#include <math.h>
#include <ostream>
#include "vector"

using namespace std;

int trova_segno ( double a, double b){
    if ( a*b > 0) return 1;
    if (a*b < 0) return -1;
    else return 0;
}

vector<vector<double>> bracketing (double xmin, double xmax, double f(double)){

    double h = ((xmax - xmin) / 100);

    vector<vector<double>> intervalli;
    vector<double> coppia(2);
    int segno = trova_segno(f(xmin), f(xmax));

    for (int i=0; i< 100; i++){
        xmin += h;
        if (trova_segno(f(xmin), f(xmax))!= segno && trova_segno(f(xmin), f(xmax))!=0){
            coppia[1]=xmin;
            // QUI metto un controllo se capito proprio sullo zero, non è necessario sempre, dipende da come implemento la bisezione
            if (f(xmin-h) == 0) coppia[0] = xmin - 2*h;
            else coppia[0] = xmin-h;
            intervalli.push_back(coppia);
            segno = trova_segno(f(xmin), f(xmax));
        }
    }
 //   punti.insert(punti.begin(), punti[0] - 2*h);
    if (intervalli.size() == 0){
        coppia = {xmin, xmax};
        intervalli.push_back(coppia);
    } 

    return intervalli;
}


vector<double> bisezione ( vector<vector<double>>& intervalli, double precision, double f(double)){

    vector<double> zeri;
    double xmin, xmax, xave;
    for (int i=0; i<intervalli.size(); ++i ){
    
        xave = intervalli[i][0];
        xmin = intervalli[i][0];
        xmax = intervalli[i][1];

        while ((xmax - xmin) > precision){
            xave = 0.5 * (xmax + xmin);
            if (f(xave) * f(xmin) > 0.) xmin = xave ;
            else xmax = xave ;
        }
        zeri.push_back(xave);
        }  
    return zeri;
}

vector<double> Newton (vector<vector<double>>& intervalli, double precision, double f(double), double f_der(double)){
    
    vector<double> zeri;
    double x, delta;
    for (int i=0; i<intervalli.size(); ++i){
        x = intervalli[i][1];
        while(f(x)>precision){
            delta = - f(x)/f_der(x);
            x = x - delta;
        }
        zeri.push_back(x);
    }
    return zeri;
}