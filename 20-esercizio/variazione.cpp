#include "iostream"
#include <cmath>
#include <math.h>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <complex>

using namespace std;
 
 //funzione di ricorrenza
complex<double> f(complex<double> z){
    complex<double> uno (1., 0.); //sinceramente non credo sia il modo migliore, ne cerco un'altro
    return z - (pow(z,3)-uno)/(3.*pow(z,2));
}

int main(int argc, char**argv){

    int N = 1000; //risoluzione
    int K = 30; //massimo di iterazioni
    //zeri della funzione
    complex<double> zero1 (1, 0);
    complex<double> zero2 (polar(1., 2*M_PI/3));
    complex<double> zero3 (polar(1., -2*M_PI/3));
    double mod1, mod2, mod3, minimo;

    double h = 4./static_cast<double>(N-1);
    complex<double> punto(-2, -2);
    vector<complex<double>> griglia;
    vector<int> valore_zero (pow(N,2));

    for (int i=0; i<N; ++i){
        griglia.push_back(punto);
        for (int j=0; j<N-1; ++j){
            punto.imag(punto.imag()+h);
            griglia.push_back(punto);
        }
        punto.imag(-2);
        punto.real(punto.real()+h);
    }

    for(int i=0; i<griglia.size(); ++i){

        punto = griglia[i];     
        for(int j=0; j<K; ++j){
            punto= f(punto);
        }
        mod1 = abs(punto-zero1);
        mod2 = abs(punto - zero2);
        mod3 = abs(punto - zero3);

        minimo = min(min(mod1,mod2), mod3);

        if ( minimo== mod1) valore_zero[i] = 1;
        else if( minimo== mod2) valore_zero[i] = 2;
        else if( minimo== mod3) valore_zero[i] = 3;
        else valore_zero[i] = 0;
    }
    fstream file;
    file.open("punti_var.dat", ios_base::out);
    for (int i=0; i<griglia.size(); i++){
        file << setprecision(12) << griglia[i].real() << "\t" << griglia[i].imag() << "\t" << valore_zero[i] << endl;
    }
    file.close();

    return 0;
}