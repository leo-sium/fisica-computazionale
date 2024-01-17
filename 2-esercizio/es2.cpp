#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"
#include "vector"

/* la ricorsione è una lente di ingrandimento, amplifica l'errore di arrotondamneto, cosa che non succede invece per la 
normale formula esponenziale*/
using namespace std;

int main(int argc, char** argv){
    vector<float> ric_float;  //creo il vettore contenente le potenze con la formula ricorsiva in precisione float
    vector<float> std_float;  //creo il vettore contenente le potenze con formula standard in float

    int N = 101;

    float phi_1f = (sqrt(5)-1)/2; //definisco phi,  il primo termine della formula ricorsiva e inserisco i primi termini
    ric_float.push_back(1);
    ric_float.push_back(phi_1f);
    std_float.push_back( pow(phi_1f, 0));
    std_float.push_back( pow(phi_1f, 1));

    for(int  i=2; i<N; i++){  // riempio gli array con le potenze nei due metodi 
        ric_float.push_back(ric_float[i-2] - ric_float[i-1]);
        std_float.push_back( pow(phi_1f, i));
    }

    fstream file1;
    file1.open("datif.dat", ios_base::out);
    for (int i=0; i<std_float.size(); i++){ // faccio la differenza e la stampo sul file 
        float diff_f = abs(ric_float[i]- std_float[i]);
        file1 << i << "\t" << setprecision(100) << diff_f << endl;
    }

    file1.close();
//-----------------------------------------------------------------------------------
    //eseguo gli stessi passaggi di prima ma con precisione doppia
    vector<double> ric_double;
    vector<double> std_double;
    
    N =201;
    
    double phi_1d = (sqrt(5)-1)/2;
    ric_double.push_back(1);
    ric_double.push_back(phi_1d);
    std_double.push_back(pow(phi_1d, 0));
    std_double.push_back(pow(phi_1d, 1));

    for(int  i=2; i<N; i++){
        ric_double.push_back(0.);
        ric_double[i] = ric_double[i-2] - ric_double[i-1];
        std_double.push_back( pow(phi_1d, i));
    }

    fstream file2;
    file2.open("datid.dat", ios_base::out);
    for (int i=0; i<std_double.size(); i++){
        double diff_d = abs(ric_double[i]- std_double[i]);
        file2 << i << "\t" << setprecision(100) << diff_d << endl;
    }

    file2.close();

//-------------------------------------------------------------------------------------
    //eseguo gli stessi passaggi di prima ma con precisione quadrupla
    vector<long double> ric_longdouble; 
    vector<long double> std_longdouble;
    
    N =201;
    
    long double phi_1ld = (sqrtl(5)-1)/2;
    ric_longdouble.push_back(1);
    ric_longdouble.push_back(phi_1ld);
    std_longdouble.push_back(pow(phi_1ld, 0));
    std_longdouble.push_back(pow(phi_1ld, 1));

    for(int  i=2; i<N; i++){
        ric_longdouble.push_back(0.);
        ric_longdouble[i] = ric_longdouble[i-2] - ric_longdouble[i-1];
        std_longdouble.push_back( powl(phi_1ld, i));
    }

    fstream file3;
    file3.open("datild.dat", ios_base::out);
    for (int i=0; i<std_longdouble.size(); i++){
        long double diff_ld = abs(ric_longdouble[i]- std_longdouble[i]);
        file3 << i << "\t" << setprecision(1000) << diff_ld << endl;
    }

    file3.close();
//-----------------------------------------------------------------------------------
//in questa fase introduco manualmente l'errore e MI RICORDO COSA HO FATTO E LO SCRIVO E CREO I PLOT

    N=101;

    vector<long double> v_ric;
    long double eps = powl(10, -8);
    long double phi_2 = -(sqrtl(5)-1)/2;
    long double phi_1_corr = phi_1ld + eps*phi_2; //inserisco manualmente l'errore 

    v_ric.push_back(1);
    v_ric.push_back ( phi_1_corr);

    for(int i=2; i<N;i++){ //riempio gli  array
        v_ric.push_back(0.);
        v_ric[i] = v_ric[i-2] - v_ric[i-1];
    }
    fstream file4;
    file4.open("ricorsivo.dat", ios_base::out);
    for(int i=0; i<v_ric.size(); i++){ //stampo su file e verifico che l'andamento sia come quello ricorsivo del float
        long double diff_ld = abs(v_ric[i]-std_longdouble[i]);
        file4 << i << "\t" << setprecision(100) << diff_ld << endl;
    }

    file4.close();

    fstream file5;
    fstream file6;
    file5.open("chi.dat", ios_base::out);
    file6.open("sing.dat", ios_base::out);

    for(int i=0; i<v_ric.size(); i++){
        file5 << i << "\t" << setprecision(100) << v_ric[i] << endl;
        file6 << i << "\t" << setprecision(100) << ric_float[i] << endl;
     }
return 0;
}