#include <stdio.h>
#include <math.h>

double H(double T) {
    return 32 - 20 * T * sinh(3 / (2 * T));
}

double H_prime(double T) {
    return 30 * cosh(3 / (2 * T)) / T - 20 * sinh(3 / (2 * T));
}

double bisection(double a, double b, double tol) {
    int counter = 0;
    double m;
    if (H(a) * H(b) < 0) {
        printf("Existe uma ou mais raízes no intervalo [%f, %f].", a, b);
        m = (a + b) / 2;
        while (fabs(H(m)) > tol) {
            if (H(m) > 0) {
                b = m;
                m = (a + b) / 2;
            } else {
                a = m;
                m = (a + b) / 2;
            }
            counter++;
        }
        printf("\nBisecção:       Valor de T = %f | Encontrado em %d iterações.", m, counter);
    }
}

double newton_raphson(double x, double tol) {
    int counter = 0;
    while (fabs(H(x)) > tol) {
        x = x - H(x) / H_prime(x);
        counter++;
    }
    printf("\nNewton Raphson: Valor de T = %f | Encontrado em %d iterações.", x, counter);
    return 0;
}

int main() {

    double a, b, x0, tol;
    tol = 1e-9;

    // Bisection Method
    a = 2;
    b = 3;
    bisection(a, b, tol);

    // Newton-Raphson Method
    x0 = 2;
    newton_raphson(x0, tol);

    printf("\n");
    return 0;
}
