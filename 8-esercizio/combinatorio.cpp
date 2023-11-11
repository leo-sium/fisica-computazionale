#include <iostream>
#include <vector>

using namespace std;

void Genera_punti(vector<double>& coord, vector<double>& p, vector<vector<double>> punti, int k, int start) {
    if (k == 0) {
        double sum = 0;
        for (int j=0; j< p.size(); j++) {
            
        }
        cout << endl;
        return;
    }

    for (int i = start; i < coord.size(); i++) {
        p.push_back(coord[i]);
        Genera_punti(coord, p, punti, k - 1, i);
        p.pop_back();
    }
}

int main() {
    vector<double> coord = {1, 3, 5};
    int M = 4;
    int k = M-1; // La lunghezza delle combinazioni desiderate

    vector<vector<double>> punti;

    vector<double> p;

    Genera_punti(coord, p, punti, k, 0);

    return 0;
}
