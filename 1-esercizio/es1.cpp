#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

/*con N bassi ho poca precisione, con N alti ad una certa raggiunnge un massimo.
 A Gaia con i*i senza static cast esplode ad una certa e diventa prima meno preciso, poi da inf, perchè non si
 fa il cast della i da int a float e con N = 100000 i*i eccede il massimo di un int e va in overflow*/

using namespace std;

// Funzione che calcola la sommatoria con precisione singola
float singlef (int i){
    float ris = 1/pow(static_cast<float>(i),2);
    return ris;
}

// Funzione che calcola la sommatoria con precisione doppia
double doublef (int i){
    float ris = 1/pow(static_cast<double>(i),2);
    return ris;
}

int main (int argc, char** argv){
    int N = 10000;

    float sum_f = 0;
    float temp_f;
    fstream file1;
    file1.open("datif_crescente.dat", ios_base::out);

// Calcolo della sommatoria in singola precisione con N crescente
// Al variare di N viene calcolata la somma in modo da utilizzare i valori di S(N-1) calcolati in precedenza e viene scritta su un file di testo la discrepanza con il valore atteso
    for(int i=1; i<N; i++){
        temp_f = singlef(i);
        sum_f+= temp_f;
        float diff = abs(sum_f - pow(M_PI, 2)/6);
        file1 << i << "\t" << setprecision(100) << diff << endl;

    }
    file1.close();

    fstream file2;
    file2.open("datif_decrescente.dat", ios_base::out);

// Calcolo la sommatoria in singola precisione con N decrescente   
    for(int i=1; i<N; ++i){
        sum_f = 0;
        temp_f = 0;
        for (int j=N-i; j>0; j-- ){
            temp_f = singlef(j);
            sum_f+= temp_f;
        }
        float diff = abs(sum_f - pow(M_PI, 2)/6);
        file2 << N-i << "\t" << setprecision(100) << diff << endl;
    }
    file2.close();

    fstream file3;
    file3.open("datid_crescente.dat", ios_base::out);
    double sum_d = 0;
    double temp_d = 0;

// Calcolo della sommatoria in doppia precisione con N crescente
// Al variare di N viene calcolata la somma in modo da utilizzare i valori di S(N-1) calcolati in precedenza e viene scritta su un file di testo la discrepanza con il valore atteso
    for(int i=1; i<N; i++){
        temp_d = doublef(i);
        sum_d+= temp_d;
        double diff = abs(sum_d - pow(M_PI,2)/6);
        file3 << i << "\t" << setprecision(100) << diff << endl;
    }
    file3.close();

    fstream file4;
    file4.open("datid2.dat", ios_base::out);
 // calcolo la sommatoria in doppia precisione con N decrescente, scrivendo un numero ogni 100 
    for(int i=1; i<N; i+=100){
        sum_d = 0;
        temp_d = 0;
        for (int j=N-i; j>0; j-- ){
            temp_d = doublef(j);
            sum_d+= temp_d;
        }
        double diff = abs(sum_d - pow(M_PI, 2)/6);
        file4 << N-i << "\t" << setprecision(100) << diff << endl;
    }

}