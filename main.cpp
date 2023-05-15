#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 2 * x - 5;
}

double df(double x) {
    return 3 * pow(x, 2) - 2;
}

double vegstein(double (*f)(double), double (*df)(double), double x0, double eps) {
    double x1 = x0 - f(x0) / df(x0);
    double x2 = x1 - f(x1) / df(x1);
    while (abs(x2 - x1) > eps) {
        x1 = x2 - (x2 - x1) * f(x2) / (f(x2) - f(x1));
        x2 = x1 - f(x1) / df(x1);
    }
    return x2;
}

int main() {
    cout << "Enter x0" << endl;
    int x0;
    std::cin >> x0;
    double eps = 0.0001;
    double root = vegstein(f, df, x0, eps);
    cout << "answer: " << root << endl;
    return 0;
}
