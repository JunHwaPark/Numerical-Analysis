#include <cstdio>
#include <cmath>

long double function(long double x) {
    return exp(2 * x) * sin(3 * x);
}

long double simpson(long double start, long double end) {
    return (end - start) * (function(start) + 4 * function((start + end) / 2) + function(end)) / 6;
}

long double compute(long double start, long double end) {
    long double single = simpson(start, end);
    long double comp = simpson(start, (start + end) / 2) + simpson((start + end) / 2, end);

    if (abs(single - comp) < 0.00001)
        return comp;
    else
        return compute(start, (start + end) / 2) + compute((start + end) / 2, end);
}

int main()
{
    long double value = compute(1, 3);
    printf("%.15f\n%.15f\tAbsError=%.15f", 108.5552812121278, value, abs(108.5552812121278-value));
}