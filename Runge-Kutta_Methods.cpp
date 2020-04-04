#include <cstdio>
#include <cmath>

void basic_euler(long double* pointer) {
    long double value = 0.5;
    for (int i = 0; i <= 19; i++) {
        long double time = i * 0.025;
        long double lean = value - (time * time) + 1;
        value += 0.025 * lean;
        if (i % 4 == 3)
            pointer[(int)(i / 4) + 1] = value;
    }
}

void modified_euler(long double* pointer) {
    long double value = 0.5;
    for (int i = 0; i <= 9; i++) {
        long double c_time = i * 0.05;
        long double f_time = c_time + 0.05;

        long double c_lean = value - (c_time * c_time) + 1;
        long double tmp = value + 0.05 * c_lean;    //다음 time에서의 예상 위치.
        long double f_lean = tmp - (f_time * f_time) + 1;
        value += (c_lean + f_lean) * 0.025;
        if (i % 2 == 1)
            pointer[(int)(i / 2) + 1] = value;
    }
}

void runge_kutta4(long double* pointer) {
    long double value = 0.5;
    for (int i = 0; i <= 4; i++) {
        long double c_time = i * 0.1;
        long double h_time = c_time + 0.05;
        long double f_time = c_time + 0.1;

        long double k1 = (value - (c_time * c_time) + 1) * 0.1;
        long double tmp = value + 0.5 * k1;
        long double k2 = (tmp - (h_time * h_time) + 1) * 0.1;
        tmp = value + 0.5 * k2;
        long double k3 = (tmp - (h_time * h_time) + 1) * 0.1;
        tmp = value + k3;
        long double k4 = (tmp - (f_time * f_time) + 1) * 0.1;

        value += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        pointer[i + 1] = value;
    }
}

int main()
{
    long double exact[6] = { 0.5, 0.6574145, 0.8292986, 1.0150706, 1.2140877, 1.4256394 };
    long double b_euler[6] = { 0.5, };
    long double m_euler[6] = { 0.5, };
    long double r_kutta[6] = { 0.5, };
    basic_euler(b_euler);
    modified_euler(m_euler);
    runge_kutta4(r_kutta);

    printf("ti\tExact\t\tEuler(h=0.025)\tM_Euler(h=0.05)\tRunge-Kutta(h=0.1)\n");
    for (int i = 0; i < 6; i++) {
        printf("0.%d\t%.7f\t%.7f\t%.7f\t%.7f\n", i, exact[i], b_euler[i], m_euler[i], r_kutta[i]);
    }
}
