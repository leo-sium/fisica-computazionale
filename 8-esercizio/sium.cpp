#include <iostream>
#include <vector>

using namespace std;

void Genera_punti(vector<int>& coord,vector<int>& p, int k,  int indice) {
    if (indice == k) {
        for (int i = 0; i < k; i++) {
            cout << p[i];
            if (i < k - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < coord.size(); i++) {
        p[indice] = coord[i];
        Genera_punti(coord, p, k,indice + 1);
    }
}

int main() {
    vector<int> coord = {1, 2, 3};
    int k = 3; // Lunghezza desiderata della combinazione

    vector<int> p(k);

    Genera_punti(coord,p, k,  0);

    return 0;
}
