#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cstdlib>
#include <math.h>
#include "time.h"
#include "vector"

using namespace std;

double f_1(double x){
    return -log(1-x);
}

double f_2(double x){
    return sqrt(-log(1-x));
}

int main(){
    
    int N = pow (10, 5);
    double x = 0;
    double y = 0.;
    srand(time(0));
    vector<double> punti_1;
    vector<double> punti_2;
    vector<double> punti_3;

    for(int i=0; i<N; i++){
        x = rand_range(0,1-exp(-2));
        y = f_1(x);
        punti_1.push_back(y);
    }

    for(int i=0; i<N; i++){
        x = rand_range(1- exp(-1),1);
        y = f_1(x);
        punti_2.push_back(y);
    }

    for(int i=0; i<N; i++){
        x = rand_range(0,1);
        y = f_2(x);
        punti_3.push_back(y);
    }

    fstream file_1;
    file_1.open("punti_1.dat", ios_base::out);

    for(int i=0; i<punti_1.size(); i++){
        file_1 << setprecision(10)<< punti_1[i] << endl;
    }
    file_1.close();

    fstream file_2;
    file_2.open("punti_2.dat", ios_base::out);

    for(int i=0; i<punti_2.size(); i++){
        file_2 << setprecision(10)<< punti_2[i] << endl;
    }
    file_2.close();

    fstream file_3;
    file_3.open("punti_3.dat", ios_base::out);

    for(int i=0; i<punti_3.size(); i++){
        file_3 << setprecision(10)<< punti_3[i] << endl;
    }
    file_3.close();

    return 0;

}