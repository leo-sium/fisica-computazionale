#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <math.h>

using namespace std;

double f (double x){
    double ris = pow(x, 7)*exp(-x);
    return ris;
}

int main( int argc, char** argv){
    int N = 17;
    int J = 4;
    double xmin, h, sum = 0;
    double xmax = 5;
    double tr[5];
    double ric[5];
    for (int i=0; i<=J; i++){
        tr[i]= trapezio( xmin, xmax, pow(2, i)+1, f);
    }

    ric[0]= trapezio (xmin, xmax, 2, f);

    for (int i=1; i<=J; i++){

        h = (xmax-xmin)/(pow(2,i));
        sum = 0;
        for (int k= 1; k<=(pow(2, i))/2.; k++){
            sum += f(xmin + (2.*k-1)*h);
        }
        ric[i] = 0.5*ric[i-1] + h*sum;
    }
    for (int i=0; i<J+1; i++){
        cout << tr[i]<< "\t" << ric[i] << endl;
    }

    return 0;
}