#include <cstdio>
#include <cmath>

#define START_POINT 1
#define END_POINT 1.5

long double function(long double x) {
    return x * x * log(x);
}

long double compute(long double start, long double end, int n) {
    long double len = end - start;
    long double sum = end + start;
    long double value = 0;
    if (n == 2) {
        value += function((len * 0.5773502692 + sum) / 2);
        value += function((len * -0.5773502692 + sum) / 2);
    }
    else if (n == 3) {
        value += function((len * 0.7745966692 + sum) / 2) * 5 / 9;
        value += function(sum / 2) * 8 / 9;
        value += function((len * -0.7745966692 + sum) / 2) * 5 / 9;
    }
    else if (n == 4) {
        value += function((len * 0.8611363116 + sum) / 2) * 0.3478548451;
        value += function((len * 0.3399810436 + sum) / 2) * 0.6521451549;
        value += function((len * -0.3399810436 + sum) / 2) * 0.6521451549;
        value += function((len * -0.8611363116 + sum) / 2) * 0.3478548451;
    }
    else if (n == 5) {
        value += function((len * 0.9061798459 + sum) / 2) * 0.2369268850;
        value += function((len * 0.5384693101 + sum) / 2) * 0.4786286705;
        value += function(sum / 2) * 0.5688888889;
        value += function((len * -0.5384693101 + sum) / 2) * 0.4786286705;
        value += function((len * -0.9061798459 + sum) / 2) * 0.2369268850;
    }
    return value * (end - start) / 2;
}

int main()
{
    long double value[4] = { compute(START_POINT, END_POINT, 2) ,compute(START_POINT, END_POINT, 3) ,
        compute(START_POINT, END_POINT, 4) ,compute(START_POINT, END_POINT, 5) };
    printf("\t0.192259357732796\n");
    for (int i = 0; i < 4; i++)
        printf("n=%d\t%.15f\t\tAbsError=%.15f\n", i + 2, value[i], abs(0.192259357732796 - value[i]));
}