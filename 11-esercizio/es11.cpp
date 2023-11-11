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

double f(double x){
    return -log(x);
}

int main(){
    
    int N = pow (10, 5);
    double x = 0;
    double y = 0.;
    srand(time(0));
    vector<double> punti;
    for(int i=0; i<N; i++){
        x = rand_range(exp(-2),1);
        y = f(x);
        punti.push_back(y);
    }

    fstream file;
    file.open("punti.dat", ios_base::out);

    for(int i=0; i<punti.size(); i++){
        file << setprecision(10)<< punti[i] << endl;
    }

    file.close();

}