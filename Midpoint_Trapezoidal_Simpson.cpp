#include <cstdio>
#include <cmath>

#define length 0.8
#define start 3.12014
#define mid 6.04241
#define end 10.46675

long double midpoint(double midpoint) {
    return length * midpoint;
}

long double trapezoidal(double s, double e) {
    return length * (s + e) * 0.5;
}

long double simpson(double s, double m, double e) {
    return length * (s + 4 * m + e) / 6;
}

int main()
{
    printf("Midpoint = %.10f\n", midpoint(mid));
    printf("Trapezoidal = %.10f\n", trapezoidal(start, end));
    printf("Simpson = %.10f\n", simpson(start, mid, end));
}