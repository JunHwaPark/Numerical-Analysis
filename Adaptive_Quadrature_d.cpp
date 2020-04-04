#include <cstdio>
#include <cmath>

long double function(long double x) {
    return 4 * x * cos(2 * x) - pow(x - 2, 2);
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
    long double value = compute(0, 5);
    printf("%.15f\n%.15f\tAbsError=%.15f", -18.94594930463682, value, abs(-18.94594930463682 - value));
}
