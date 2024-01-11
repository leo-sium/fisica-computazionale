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

int main(){
    complex<double> punto(-2, -2);
    double mod = abs(punto);
    cout << punto.real() << "\t" << punto.imag() << "\t" << mod <<endl;


    for(int i=0; i<10; i++){
        punto = f(punto);
        cout << punto.real() << "\t" << punto.imag() << "\t" << setprecision(14) <<mod << endl;
    }
    return 0;
}