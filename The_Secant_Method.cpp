#include <cstdio>
#include <cmath>

long double f(long double pn) {
    return pn * pn * pn + 4 * pn * pn - 10;
}

void compute() {
    const double TOL = 0.0005;
    long double a = 1, b = 2;
    int n = 20;

    printf(" n\tpn\t\tf(pn)\n");

    for (int i = 0; i < n && TOL < abs(b - a); i++) {
        long double next = b - (f(b) * (b - a) / (f(b) - f(a)));
        printf("%2d\t%.10f\t%.10f\n", i + 2, next, f(next));

        a = b;
        b = next;
    }
}

int main()
{
    compute();
}