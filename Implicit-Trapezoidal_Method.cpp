#include <cstdio>
#include <cmath>

long double f(long double time, long double pos) {
    return 5 * exp(5 * time) * (pos - time) * (pos - time) + 1;
}

long double realf(long double t) {
    return t - exp(t * (-5));
}

long double get_next_w(long double pre_w, long double w0, long double interval, int n, int loop = 1) {

    long double value = pre_w
        - (pre_w - w0 - (interval / 2) * (f(interval * n, w0) + f(interval * (n + 1), pre_w)))
        / (1 - (interval / 2) * f(interval * (n + 1), pre_w));

    if (abs(value - pre_w) < 0.000001 || loop > 10)
        return value;
    return get_next_w(value, w0, interval, n, loop + 1);
}

void imp_trape(long double* pointer, long double interval, int loop) {
    //long double value = pointer[0];
    for (int i = 0; i < loop; i++) {
        pointer[i + 1] = get_next_w(pointer[i], pointer[i], interval, i);
    }
}

void runge_kutta4(long double* pointer, long double interval, int loop) {
    long double value = -1;
    for (int i = 0; i < loop; i++) {
        long double c_time = i * interval;
        long double h_time = c_time + (interval / 2);
        long double f_time = c_time + interval;

        long double k1 = f(c_time, value) * interval;
        long double tmp = value + 0.5 * k1;
        long double k2 = f(h_time, tmp) * interval;
        tmp = value + 0.5 * k2;
        long double k3 = f(h_time, tmp) * interval;
        tmp = value + k3;
        long double k4 = f(f_time, tmp) * interval;
        value += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        pointer[i + 1] = value;
    }
}

int main()
{
    long double runge_2_5[5] = { -1, };
    long double runge_2[6] = { -1, };
    long double trape_2_5[5] = { -1, };
    long double trape_2[6] = { -1, };
    runge_kutta4(runge_2_5, 0.25, 4);
    runge_kutta4(runge_2, 0.2, 5);
    imp_trape(trape_2_5, 0.25, 4);
    imp_trape(trape_2, 0.2, 5);

    printf("runge_kutta\t\t\t\ttrapezoidal\n");
    printf("ti\twi\t\terror\t\tti\twi\t\terror\n");
    
    for (int i = 0; i < 6; i++) {
        printf("%.2f\t%3.7f\t%3.7f\t", i * 0.2, runge_2[i], abs(runge_2[i] - realf(i * 0.2)));
        printf("%.2f\t%3.7f\t%3.7f\n", i * 0.2, trape_2[i], abs(trape_2[i] - realf(i * 0.2)));
    }

    printf("\nti\twi\t\terror\t\tti\twi\t\terror\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f\t%3.7f\t%3.7f\t", i * 0.2, runge_2_5[i], abs(runge_2_5[i] - realf(i * 0.2)));
        printf("%.2f\t%3.7f\t%3.7f\n", i * 0.2, trape_2_5[i], abs(trape_2_5[i] - realf(i * 0.2)));
    }

    return 0;
}
