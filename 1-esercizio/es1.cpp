#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

/*con N bassi ho poca precisione, con N alti ad una certa raggiunnge un massimo.
 A Gaia con i*i senza static cast esplode ad una certa e diventa prima meno preciso, poi da inf, perchè non si
 fa il cast della i da int a float e con N = 100000 i*i eccede il massimo di un int e va in overflow*/

using namespace std;

// funzione che calcola la sommatoria in float
float singlef (int i){
    float ris = 1/pow(static_cast<float>(i),2);
    return ris;
}

//funzione che calcola la sommatoria sul double
double doublef (int i){
    float ris = 1/pow(static_cast<double>(i),2);
    return ris;
}

int main (int argc, char** argv){
    int N = 10000;
    fstream file1;
    file1.open("datif1.dat", ios_base::out);

    
    float sumf = 0;
    float partsumf;


// calcolo la sommatoria in singola precisione sommando con N crescente e scrivendo un numero ogni 100
// in questo modo la somma è più efficiente perchè sfrutta i numeri già calcolati per quelli successivi, senza far ripartire la somma da 0
    for(int i=1; i<N; i++){
        partsumf = singlef(i);
        sumf+= partsumf;
      
        if (i%100 == 0){
        float diff = abs(sumf - pow(M_PI, 2)/6);

        file1 << i << "\t" << setprecision(100) << diff << endl;
        }
    }
    file1.close();

    fstream file2;
    file2.open("datif2.dat", ios_base::out);


 // calcolo la sommatoria in singola precisione con N decrescente, scrivendo un numero ogni 100   
    for(int i=1; i<N; i+=100){
        sumf = 0;
        partsumf = 0;
        for (int j=N-i; j>0; j-- ){
            partsumf = singlef(j);
            sumf+= partsumf;
        }
        float diff = abs(sumf - pow(M_PI, 2)/6);
        file2 << N-i << "\t" << setprecision(100) << diff << endl;
    }

    file2.close();

    fstream file3;
    file3.open("datid1.dat", ios_base::out);

    double sumd = 0;
    double partsumd = 0;
// calcolo la sommatoria in doppia precisione sommando con N crescente e scrivendo un numero ogni 100
// in questo modo la somma è più efficiente perchè sfrutta i numeri già calcolati per quelli successivi, senza far ripartire la somma da 0
    for(int i=1; i<N; i++){
        partsumd = doublef(i);
        sumd+= partsumd;

        if(i%100 == 0){
            double diff = abs(sumd - pow(M_PI,2)/6);

            file3 << i << "\t" << setprecision(100) << diff << endl;
        }
    }

    file3.close();

    fstream file4;
    file4.open("datid2.dat", ios_base::out);
 // calcolo la sommatoria in doppia precisione con N decrescente, scrivendo un numero ogni 100 
    for(int i=1; i<N; i+=100){
        sumd = 0;
        partsumd = 0;
        for (int j=N-i; j>0; j-- ){
            partsumd = doublef(j);
            sumd+= partsumd;
        }
        double diff = abs(sumd - pow(M_PI, 2)/6);
        file4 << N-i << "\t" << setprecision(100) << diff << endl;
    }

}