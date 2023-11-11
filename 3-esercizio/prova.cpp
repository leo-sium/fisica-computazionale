#include "iostream"
#include "fstream"
#include "iomanip"
#include "cmath"
#include "integrali.h"
#include "string.h"

using namespace std;


int main()
{
    string nomefile = "Legendre";
    int i= 2;
    nomefile += to_string(i);

    cout  <<  nomefile << endl ;


    return 0;
}
