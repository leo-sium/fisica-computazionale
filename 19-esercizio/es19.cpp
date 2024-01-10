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

double f ( double x){
    //return 2*pow(x,2) - 3*x + 1;
    return pow(x,3) - 4*pow(x,2) - x + 6;
}

vector<vector<double>> bracketing (double xmin, double xmax){

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

vector<double> bisezione ( vector<vector<double>>& intervalli, double precision){

    vector<double> zeri;
    for (int i=0; i<intervalli.size(); ++i ){
    
        double xave = intervalli[i][0];
        double xmin = intervalli[i][0];
        double xmax = intervalli[i][1];

        while ((xmax - xmin) > precision){
            xave = 0.5 * (xmax + xmin);
            if (f(xave) * f(xmin) > 0.) xmin = xave ;
            else xmax = xave ;
        }
        zeri.push_back(xave);
        }  
    return zeri;
}

int main (int argc, char**argv){

    double xmin = -2;
    double xmax = 4.;
    double precisione = 0.0001;

    vector<vector<double>> intervalli = bracketing(xmin, xmax);

    if(trova_segno(xmin, xmax)== 1 &&  intervalli.size()==1){
        cout << "non ci sono zeri nell'intervallo" << endl;
        return 0;
    }

    vector<double> zeri = bisezione (intervalli, precisione);

    for (int i=0; i<intervalli.size(); ++i){
        cout << "intervallo " << i+1 << ": \t"<< intervalli[i][0] << "\t" << intervalli[i][1] << endl;
    }
    for (int i=0; i< zeri.size(); ++i){
        cout << "lo zero " << i+1 << " è: " << zeri[i] << endl;
    }
    return 0;
}