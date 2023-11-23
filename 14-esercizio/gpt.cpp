#include <iostream>
#include <cmath>

double func_x(double x, double y) {
    // Inserisci qui la tua funzione differenziale
    return y;
}

double func_y(double x, double y){
    return -x;
}

double rungeKutta(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; ++i) {
        double k1_x = h * func(x, y);
        double k1_y = h * func(x, y);

        double k2_x = h * func(x+ k1_x*0.5, y + 0.5 * k1_y);
        double k2_y = h * func(x+ k1_x*0.5, y + 0.5 * k1_y);

        double k3_x = h * func(x+ k2_x*0.5, y + 0.5 * k2_y);
        double k3_y = h * func(x+ k2_x*0.5, y + 0.5 * k2_y);

        double k4_x = h * func(x + k3_x, y + k3_y);
        double k4_y = h * func(x + k3_x, y + k3_y);


        y = y + (1.0 / 6.0) * (k1_y + 2 * k2_y + 2 * k3_y + k4_y);
        x = x + (1.0 / 6.0) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x);
    }

    return y;
}

int main() {
    double x0 = 0.0;  // Condizione iniziale x
    double y0 = 1.0;  // Condizione iniziale y
    double h = 0.1;   // Passo di integrazione
    int n = 100;       // Numero di passi

    double result = rungeKutta(x0, y0, h, n);

    std::cout << "Il risultato dell'integrazione numerica è: " << result << std::endl;

    return 0;
}
