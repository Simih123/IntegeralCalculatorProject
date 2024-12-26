#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Trapezoidal rule function
double trapezoidalRule(function<double(double)> func, double a, double b, int n) {
    double h = (b - a) / n; // Interval width
    double sum = 0.5 * (func(a) + func(b)); // Endpoints contribution

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += func(x);
    }

    return sum * h; // Final result
}

// Simpson's rule function
double simpsonsRule(function<double(double)> func, double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Simpson's rule requires an even number of intervals. Incrementing n by 1." << endl;
        n += 1;
    }
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * func(x);
        else
            sum += 4 * func(x);
    }

    return (h / 3) * sum;
}

int main() {
    // Input variables
    double a, b;
    int n;
    int choice;

    cout << "Welcome to the Integral Calculator!" << endl;
    cout << "Choose the numerical integration method:" << endl;
    cout << "1. Trapezoidal Rule" << endl;
    cout << "2. Simpson's Rule" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cout << "Enter the lower limit (a): ";
    cin >> a;

    cout << "Enter the upper limit (b): ";
    cin >> b;

    cout << "Enter the number of intervals (n): ";
    cin >> n;

    // Define the function to integrate (e.g., f(x) = x^2)
    auto func = [](double x) {
        return x * x; // Example: x^2
    };

    double result;
    if (choice == 1) {
        result = trapezoidalRule(func, a, b, n);
        cout << "Using Trapezoidal Rule, the integral is approximately: " << result << endl;
    }
    else if (choice == 2) {
        result = simpsonsRule(func, a, b, n);
        cout << "Using Simpson's Rule, the integral is approximately: " << result << endl;
    }
    else {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }

    return 0;
}

