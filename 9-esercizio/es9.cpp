#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <ostream>
#include "time.h"
#include "vector"

using namespace std;

//nella moneta ovviamente i risultati che posso ottenere della media sono discreti, non continui
//quindi devo stare attento a mettere un numero di bin tale che la "grana" sia abbastanza grossolana
//da non distinguere i casi in cui possono o non possono cadere i bin.

int main(){

    //uso N come numero totale di punti, e M come numero di punti in ogni pacchetto
    //che poi andra a comporre 1 punto tramite la media
    //successivamente dovrò studiare gli andamenti tenendo fisso N e variando M
    int N = pow(10, 5);
    int M = pow(10, 2);

    srand(time(0));
    double x=0.;
    double y=0.;
    double z;
    vector<double> punti_unif;
    vector<double> punti_mon;

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            x += rand_range(-1., 1.);
        }
        x= x/static_cast<double>(M);
        punti_unif.push_back(x);
        x=0.;
    }

    double med_unif = media(punti_unif);
    cout << med_unif << endl;
    double var_unif = momento(punti_unif, 2);
    cout << var_unif << endl;
    double sk_unif = momento(punti_unif, 3);
    cout << sk_unif << endl;
    //FACCIO ANCHE SKEWNESS E CURTOSI E VERIFICO LE FORMULE SIANO GUSTE CON PYTHON

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            x += moneta();
        }
        x= x/static_cast<double>(M);
        punti_mon.push_back(x);
        x=0.;
    }

    double med_mon = media(punti_mon);
    cout << med_mon << endl;
    double var_mon = momento(punti_mon, 2);
    cout << var_mon << endl;
    double sk_mon = momento(punti_unif, 3);
    cout << sk_mon << endl;


    fstream file;
    file.open("punti.dat", ios_base::out);

    for(int i=0; i<punti_unif.size(); i++){
        file << setprecision(10)<< punti_unif[i] << "\t" << punti_mon[i] << endl;
    }
    file.close();


    return 0;
}