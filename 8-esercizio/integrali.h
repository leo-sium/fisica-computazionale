#ifndef integrali_h
#define integrali_h

#include "cmath"
#include "string.h"
#include "iostream"
#include <math.h>
#include "fstream"
#include "vector"

using namespace std;

// Ancora da ottimizzare
double trapezio ( double xmin,  double xmax, int N, double f(double)){

    double h = (xmax-xmin)/(static_cast<double>(N)-1);
    double partsum = 0;
    double sum = 0;

    for(int i=0; i<N; i++){
        partsum = f(xmin+ static_cast<double>(i)*h);
        //if(isinf(partsum)) continue;
        if(i==0) partsum = partsum/2;
        if(i==N-1) partsum = partsum/2;
        sum += partsum;

    }

    double ris = h*sum;

    return ris;


}
//da sistemare 
double simpson (double xmin, double xmax, int N, double f(double)){
//migliorare messaggio di errore
    if( N%2==0){
        cout << "inserire N dispari nel calcolo con il metodo di Simpson"<< endl;
        exit(1);
    }

    double h = (xmax-xmin)/(static_cast<double>(N)-1);
    double partsum = 0;
    double sum = 0;

    for(int i=0; i<N; i++){
        partsum = f(xmin+ static_cast<double>(i)*h);
        //if(isinf(partsum)) continue;
        if((i+1)%2 == 0 && i!= N-1) partsum = partsum*4 ;
        if((i+1)%2!=0 && i!= N-1 && i!=0) partsum= partsum*2;
        
        sum += partsum;
    }

    double ris = h*sum/3;

    return ris;
}

//Da ottimizzare e commentare
double romberg (double xmin, double xmax, int N, double f(double), bool V=false){ 

// Qui ricavo il valore di J. DEVO SISTEMARE  E CAMBIARE NOMME VARIABILI
    int J  = 0;
    double h, sum = 0;
    int sium = N-1;
    while (sium != 1){
        sium = sium/2;
        J++;       
    }
//-----------------------------------------------------------------------
// creo una matrice e la inizializzo a 0
    double Mat [J+1][J+1];

    for (int n=0; n<= J; n++){
        for(int m=0; m<= J; m++){
            Mat[n][m] = 0.;
        }
    }
//-----------------------------------------------------------------------
//calcolo tutto

    Mat[0][0]= trapezio(xmin, xmax, 2, f); //provo a cambiare così non cambio una funzione in più

    for (int n = 1; n<=J; n++){
        for (int m = 0; m<=n; m++){

            if (m == 0){
                h = (xmax-xmin)/(pow(2,n));
                sum = 0;
                for (int k= 1; k<=(pow(2, n))/2; k++){
                    
                    sum += f(xmin + (2*k-1)*h);
                }
                Mat [n][0] = 0.5* Mat[n-1][0]+ h*sum;     
            }

            else{
                Mat[n][m] = (pow(4, m)*Mat[n][m-1] - Mat[n-1][m-1])/(pow(4,m)-1);
            }
        }
    }
//----------------------------------------------------------------------
    if (V==true) {
        int n;
        int m;
        cout << "inserisci riga e poi colonna" << endl;
        cin >> n >> m;
        return Mat[n][m];
    }
    else{
        return Mat[J][J];
    }
}
//questa è la midpoint a  5 intervalli, faccio anche quella a 2 intervalli
double midpoint5(double xmin, double xmax, double f(double)){

    double h = (xmax-xmin)/5.;
    double partsum=0;
    double sum= 0;
    double ris = 0;

    for (int i=1; i<5; i++){
        partsum= f(xmin + h*i);
        if (i==1 || i==4) partsum = partsum*11;
        sum += partsum;
    }
    ris = (5./24.)*h*sum;
    return ris;
}

double midpoint2(double xmin, double xmax, double f(double)){

    double h = (xmax - xmin)/2.;
    double I = 2*h*f(xmin+h);
    return I;
}

double midpointesteso(double xmin, double xmax, int N, double f(double)){

    double h = (xmax-xmin)/(static_cast<double>(N));
    double partsum = 0;
    double sum = 0;
    for (int i=1; i<=N; i++){
        partsum = h*f(xmin + static_cast<double>(i)*h); //ho tolto il 2 perchè la h che uso è la distanza tra i tue punti e la h nella formula è la semi-distanza
        sum+=partsum;
    }
    return sum;
}

//da sistemare + formula riscalare vedi in lib esercizio 4
double legendre (int N, double f(double)){

    double x[N] = {0.};
    double p[N] = {0.};

    fstream Pesi_Gaussiani;
    string nomefile = "Legendre" + to_string(N) + ".dat";
    Pesi_Gaussiani.open(nomefile, ios_base::in);

    for(int i=0; i<N; i++){
        Pesi_Gaussiani >> x[i] >> p[i];
    }
    Pesi_Gaussiani.close();

    double sum = 0.;
    double partsum = 0.;

    for (int i=0; i<N; i++){
        partsum = p[i]*f(x[i]);
        sum += partsum;
    }

    return sum;
}

//da sistemare e commentare
double laguerre(int N, double f(double)){

    double x[N] = {0.};
    double p[N] = {0.};

    fstream Pesi_Gaussiani;
    string nomefile = "Laguerre" + to_string(N) + ".dat";
    Pesi_Gaussiani.open(nomefile, ios_base::in);

    for(int i=0; i<N; i++){
        Pesi_Gaussiani >> x[i] >> p[i];
    }
    Pesi_Gaussiani.close();

    double partsum = 0.;
    double sum = 0;

    for (int i=0; i<N; i++){
        partsum = p[i]*f(x[i]);
        sum+= partsum;
    } 

    return sum;

}

double hermite(int N, double f(double)){

    double x[N] = {0.};
    double p[N] = {0.};

    fstream Pesi_Gaussiani;
    string nomefile = "Hermite" + to_string(N) + ".dat";
    Pesi_Gaussiani.open(nomefile, ios_base::in);

    for(int i=0; i<N; i++){
        Pesi_Gaussiani >> x[i] >> p[i];
    }
    Pesi_Gaussiani.close();

    double partsum = 0.;
    double sum = 0;

    for (int i=0; i<N; i++){
        partsum = p[i]*f(x[i]);
        sum+= partsum;
    } 

    return sum; 
}
// a questa funzione passo direttamente il punto medio
double midpoint_multi ( vector<double> p, double h, double f(vector<double>)) {

    int M = p.size();
    double z = f(p);
    double ris = z* pow(2*h, M);
    return ris;
}

double rand_range (double min, double max){
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }

















#endif
