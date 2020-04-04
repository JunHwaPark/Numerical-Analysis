#include <cstdio>
#include <cmath>

long double f(long double pn) {
    return pn - pow(3, -pn);
}
long double fp(long double pn) {
    return 1 + pow(3, -pn) * log(3);
}

void compute() {
    const double TOL = sqrt(0.00000001);
    long double a = 0.5, b = 0.5, error = 1;

    printf("n\tp(n)\t\t|p(n) - p(n - 1)|\n");
    printf("0\t%.10f\n", b);
    for (int i = 1; error > TOL; i++) {
        b = a - f(a) / fp(a);
        error = abs(b - a);
        printf("%d\t%.10f\t%.10f\n", i, b, error);

        a = b;
    }
}

int main()
{
    compute();
}
