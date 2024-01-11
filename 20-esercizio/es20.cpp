#include "iostream"
#include <cmath>
#include <math.h>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <complex>

using namespace std;

complex<double> f(complex<double> z){
    complex<double> uno (1., 0.); //sinceramente non credo sia il modo migliore, ne cerco un'altro
    return z - (pow(z,3)-uno)/(3.*pow(z,2));
}

int main(int argc, char**argv){

    int N = 1000;
    int K = 1000;
    double epsilon = pow(10, -10);
    int cont = 0;
    double h = 4./static_cast<double>(N-1);
    complex<double> punto(-2, -2);
    complex<double> punto2;
    vector<complex<double>> griglia;
    vector<int> iterazioni (pow(N,2));

    for (int i=0; i<N; ++i){
        griglia.push_back(punto);
        for (int j=0; j<N-1; ++j){
            punto.imag(punto.imag()+h);
            griglia.push_back(punto);
        }
        punto.imag(-2);
        punto.real(punto.real()+h);
    }
/*
    for (int i=0; i<griglia.size(); ++i){
        cout << griglia[i].real() << "\t" << griglia[i].imag() << endl;
    }
*/

    for(int i=0; i<griglia.size(); ++i){
        cont = 0;
        punto2 = griglia[i];
        do {
            punto = punto2;
            punto2 = f(punto);
            ++cont;
        }while(abs(punto2 - punto)> epsilon && cont < K);
        iterazioni[i] = cont;
    }

    fstream file;
    file.open("punti.dat", ios_base::out);

    for (int i=0; i<griglia.size(); i++){
        file << setprecision(12) << griglia[i].real() << "\t" << griglia[i].imag() << "\t" << iterazioni[i] << endl;
    }
    file.close();

    return 0;

}