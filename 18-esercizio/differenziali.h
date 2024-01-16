#ifndef differenziali_h
#define differenziali_h

#include "cmath"
#include "math.h"
#include "iostream"
#include "vector"
#include "fstream"
#include "iomanip"
#include <cstdlib>

using namespace std;

class vettore {
private:
    double x, y, z;

public:
    // Costruttore per inizializzare un vettore con le sue tre componenti
    vettore(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

    vettore() : x(0), y(0), z(0) {}

    // Funzione per calcolare il modulo del vettore
    double modulo() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    double X(){
        return x;
    }
    double Y(){
        return y;
    }
    double Z(){
        return x;
    }

    // Operazione di somma tra vettori
    vettore operator+(const vettore& other) const {
        return vettore(x + other.x, y + other.y, z + other.z);
    }

    // Operazione di sottrazione tra vettori
    vettore operator-(const vettore& other) const {
        return vettore(x - other.x, y - other.y, z - other.z);
    }

    // Operazione di moltiplicazione per uno scalare
    vettore operator*(double scalare) const {
        return vettore(x * scalare, y * scalare, z * scalare);
    }

    // Operazione di divisione per uno scalare
    vettore operator/(double scalare) const {
        // Verifica se lo scalare è diverso da zero prima di eseguire la divisione
        if (scalare != 0.0) {
            return vettore(x / scalare, y / scalare, z / scalare);
        } else {
            std::cerr << "Errore: divisione per zero" << std::endl;
            // In caso di divisione per zero, restituisci un vettore nullo
            return vettore(0.0, 0.0, 0.0);
        }
    }

    // Funzione per stampare le componenti del vettore
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

vector<vettore> somma_vector(vector<vettore>& v1, vector<vettore>& v2){

    if(v1.size() != v2.size()) {
        cout << "i vettori hanno dimensione diversa"<< endl;
        exit(EXIT_FAILURE);
    }

    vector<vettore> v3 (v1.size());

    for(int i=0; i<v1.size(); ++i){
        v3[i] = v1[i] + v2[i];
    }
    return v3;
} 

vector<vettore> calcola_k(vector<vettore>& v1, vector<vettore>& v2){

    vector<vettore> temp (v2.size());
    for (int i=0; i<v2.size(); ++i){
        temp[i] = v2[i]/2.;
    }
    return somma_vector(v1 , temp);
}

//ragiono sul numero dei passi, che di sicuro così mi fermo probabilmente un passo prima rispetto all'effettivo tempo finale


vector<vector<vector<vettore>>> runge_kutta_4 ( vector<vettore>& r_iniziale, vector<vettore>& v_iniziale, double tmax, int N_passi, vettore (*f[])(vector<vettore>&)){

    double h = tmax/static_cast<double>(N_passi);
    double t=h;
    int  n = r_iniziale.size();

    vector<vector<vettore>> r (N_passi, vector<vettore>(n) );
    vector<vector<vettore>> v (N_passi, vector<vettore>(n) );
    vector<vector<vector<vettore>>> risultati;

    vector<vector<vettore>> k_r (4, vector<vettore>(n));
    vector<vector<vettore>> k_v (4, vector<vettore>(n));
    vector<vettore> temp_r(n);
    vector<vettore> temp_v(n);

// calcolo dell'evoluzione temporale---------------------------

    for(int i=0; i<n; i++){
        r[0][i] = r_iniziale[i];
        v[0][i] = v_iniziale[i];
    }

    for (int i=0; i<N_passi-1; ++i){

        for (int j=0; j<n; ++j) {
            k_r[0][j] = (f[j])(v[i])*h;
            k_v[0][j] = (f[j+3])(r[i])*h;
        }
        temp_r = calcola_k(r[i], k_r[0]);
        temp_v = calcola_k(v[i], k_r[0]);

        for (int j=0; j<n; ++j){
            k_r[1][j] = (f[j])(temp_v)*h;
            k_v[1][j] = (f[j+3])(temp_r)*h;
        } 

        temp_r = calcola_k(r[i], k_r[1]);
        temp_v = calcola_k(v[i], k_r[1]);

        for (int j=0; j<n; ++j) {
            k_r[2][j] = (f[j])(temp_v)*h;
            k_v[2][j] = (f[j+3])(temp_r)*h;
        }

        temp_r = calcola_k(r[i], k_r[2]);
        temp_v = calcola_k(v[i], k_r[2]);

        for (int j=0; j<n; ++j){
            k_r[3][j] = (f[j])(temp_v)*h;
            k_v[3][j] = (f[j+3])(temp_r)*h;
        }
        for (int j=0; j<n; ++j) {
            r[i+1][j] = r[i][j] + (k_r[0][j] + k_r[1][j]*2 + k_r[2][j]*2 + k_r[3][j])/6.;
            v[i+1][j] = v[i][j] + (k_v[0][j] + k_v[1][j]*2 + k_v[2][j]*2 + k_v[3][j])/6.;

        }
        t+=h;
    }

    //stampa su file delle coordinate per l'animazione----------------------
    //SISTEMO LE PRECISIONI
    fstream file;
    file.open("animazione.dat", ios_base::out);
    for(int i=0; i<N_passi; i+=1000){
        file<< setprecision(3) << static_cast<double>(i)*h << "\t";
        for (int j=0; j<n; ++j){
            file<< setprecision(3) << r[i][j].X() << " " << r[i][j].Y()<< " " << r[i][j].Z()<< "\t"; 
        }
        file<< endl;
    }
    file.close();

    risultati.push_back(r);
    risultati.push_back(v);

    return risultati;

}



#endif