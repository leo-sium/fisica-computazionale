#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"
#include "vector"

/* la ricorsione è una lente di ingrandimento, amplifica l'errore di arrotondamneto, cosa che non succede invece per la 
normale formula esponenziale*/
using namespace std;

int main(int argc, char** argv){
    vector<float> vrf;  //creo il vettore contenente le potenze con la formula ricorsiva in precisione float
    vector<float> vpf;  //creo il vettore contenente le potenze con formula standard in float

    fstream file1;
    file1.open("datif.dat", ios_base::out);

    int N = 101;

    float phi_1f = (sqrt(5)-1)/2; //definisco phi,  il primo termine della formula ricorsiva e inserisco i primi termini
    vrf.push_back(1);
    vrf.push_back(phi_1f);
    vpf.push_back( pow(phi_1f, 0));
    vpf.push_back( pow(phi_1f, 1));

    for(int  i=2; i<N; i++){  // riempio gli array con le potenze nei due metodi 
        vrf.push_back(0.);
        vrf[i] = vrf[i-2] - vrf[i-1];
        vpf.push_back( pow(phi_1f, i));
    }

    for (int i=0; i<vpf.size(); i++){ // faccio la differenza e la stampo sul file 
        float diff_f = abs(vrf[i]- vpf[i]);
        file1 << i << "\t" << setprecision(100) << diff_f << endl;
    }

    file1.close();
//-----------------------------------------------------------------------------------
    vector<double> vrd;//stesso di prima ma con precisione diversa
    vector<double> vpd;
    
    fstream file2;
    file2.open("datid.dat", ios_base::out);

    N =201;
    
    double phi_1d = (sqrt(5)-1)/2;
    vrd.push_back(1);
    vrd.push_back(phi_1d);
    vpd.push_back(pow(phi_1d, 0));
    vpd.push_back(pow(phi_1d, 1));

    for(int  i=2; i<N; i++){
        vrd.push_back(0.);
        vrd[i] = vrd[i-2] - vrd[i-1];
        vpd.push_back( pow(phi_1d, i));
    }

    for (int i=0; i<vpd.size(); i++){
        double diff_d = abs(vrd[i]- vpd[i]);
        file2 << i << "\t" << setprecision(100) << diff_d << endl;
    }

    file2.close();

//-------------------------------------------------------------------------------------

    vector<long double> vrld; //stesso di prima ma con precisione diversa
    vector<long double> vpld;
    
    fstream file3;
    file3.open("datild.dat", ios_base::out);

    N =201;
    
    long double phi_1ld = (sqrtl(5)-1)/2;
    vrld.push_back(1);
    vrld.push_back(phi_1ld);
    vpld.push_back(pow(phi_1ld, 0));
    vpld.push_back(pow(phi_1ld, 1));

    for(int  i=2; i<N; i++){
        vrld.push_back(0.);
        vrld[i] = vrld[i-2] - vrld[i-1];
        vpld.push_back( powl(phi_1ld, i));
    }

    for (int i=0; i<vpld.size(); i++){
        long double diff_ld = abs(vrld[i]- vpld[i]);
        file3 << i << "\t" << setprecision(1000) << diff_ld << endl;
    }

    file3.close();

//-----------------------------------------------------------------------------------

    fstream file4;
    file4.open("ricorsivo.dat", ios_base::out);

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

    for(int i=0; i<v_ric.size(); i++){ //stampo su file e verifico che l'andamento sia come quello ricorsivo del float
        long double diff_ld = abs(v_ric[i]-vpld[i]);
        file4 << i << "\t" << setprecision(100) << diff_ld << endl;
    }

    file4.close();

    fstream file5;
    fstream file6;
    file5.open("chi.dat", ios_base::out);
    file6.open("sing.dat", ios_base::out);

    for(int i=0; i<v_ric.size(); i++){
        file5 << i << "\t" << setprecision(100) << v_ric[i] << endl;
        file6 << i << "\t" << setprecision(100) << vrf[i] << endl;
     }
return 0;
}