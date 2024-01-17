#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "differenziali.h"
#include <cmath>
#include <fstream>
#include <math.h>
#include "vector"
// sto usando una pessima gestione della memoria, vedo di migliorare, magari usando le reference/alias

#define n 6 //dimensione del sistema di equazioni differenziali 

using namespace std;

vector<double> m {0.3, 0.3, 0.3}; // vettore che contiene le masse dei corpi

//Dichiaro le funzioni vettoriali di aggiornamento delle posizioni e delle velocità dei corpi

vettore f_r1 (vector<vettore>& v){
    return v[0];
}

vettore f_v1 (vector<vettore>& r){
    vettore r12 = r[0] - r[1];
    vettore r13 = r[0] - r[2];
    return r12*(-m[1])/pow(r12.modulo(), 3) + r13*(-m[2])/pow(r13.modulo(), 3);
}

vettore f_r2 (vector<vettore>& v){
    return v[1];
}

vettore f_v2(vector<vettore>& r){
    vettore r21 = r[1] - r[0];
    vettore r23 = r[1] - r[2];
    return r21*(-m[0])/pow(r21.modulo(), 3) + r23*(-m[2])/pow(r23.modulo(), 3);
}

vettore f_r3 (vector<vettore>& v){
    return v[2];
}

vettore f_v3(vector<vettore>& r){
    vettore r31 = r[2] - r[0];
    vettore r32 = r[2] - r[1];
    return r31*(-m[0])/pow(r31.modulo(), 3) + r32*(-m[1])/pow(r32.modulo(), 3);
}

int main (){

//condizioni iniziali del problema-------------------------------------------
    vettore r1(1, 0, 0);
    vettore r2(-1, 0, 0);
    vettore r3(0, 0, 0);

    vettore v1(0, 0.15, -0.15);
    vettore v2(0, -0.15, 0.15);
    vettore v3(0, 0, 0);

    vector<vettore> r_iniziale{r1, r2, r3};
    vector<vettore> v_iniziale{v1, v2, v3};
    vector<vector<vettore>> r, v;
    double r12, r13, r23;

    double tmax = 100; //il tempo finale di calcolo dell'equazione differenziale
    int N_passi = 1000000; //numero di passi in cui suddivido l'intervallo di tempo
    double h = tmax/static_cast<double>(N_passi);

    vector<double> K(N_passi);
    vector<double> U(N_passi);
    vector<double> E(N_passi);

    double G = 1;

    vettore (*f[n]) (vector<vettore>&) = {f_r1, f_r2, f_r3, f_v1, f_v2, f_v3};
    
//la seguente funzione restituisce un vettore che ha per componenti le posizioni di tutti i corpi ad ogni istante e le corrispondenti velocità
    vector<vector<vector<vettore>>> risultati = runge_kutta_4(r_iniziale, v_iniziale, tmax, N_passi, f);

    r = risultati[0];
    v = risultati[1];
// calcolo l'energia cinetica del sistema----------------------------------------
    for (int i=0; i< N_passi; ++i){
        for(int j=0; j<3; ++j){
           K[i] += pow(v[i][j].modulo(), 2)*(m[j]/2.);
        }
// Calcolo l'energia potenziale del sistema-----------------------------------------
//trovo un modo di farlo più elegante
        r12 = (r[i][0] - r[i][1]).modulo();
        U[i] = -(G*m[0]*m[1]/(r[i][1]-r[i][0]).modulo() + G*m[0]*m[2]/(r[i][2]-r[i][0]).modulo() + G*m[2]*m[1]/(r[i][1]-r[i][2]).modulo());
        E[i] = U[i]+K[i];
    }
//Stampo su file i tempi e le corrispondenti energie -------------------------------
    fstream file;
    file.open("energia.dat", ios_base::out);
    for(int i=0; i<N_passi; ++i){
        file<< setprecision(6) << static_cast<double>(i)*h << "\t";
        file<< setprecision(6) << K[i] << "\t" << U[i] << "\t" << E[i] << endl;
    }
    file.close();

    return 0;

}