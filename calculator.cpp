#include <iostream>
#include <cmath>

using namespace std;

int calculator() {
    double a, b;
    char op;

    while (true) {
        cout << "Enter first number: ";
        cin >> a;

        cout << "Enter operator (+ - * / %5): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> b;

        if (op == '+') {
            cout << "Result = " << a + b;
        } else if (op == '-') {
            cout << "Result = " << a - b;
        } else if (op == '*') {
            cout << "Result = " << a * b;
        } else if (op == '/') {
            if (b == 0) {
                cout << "Error: Division by zero! " << endl;
            } else {
                cout << "Result = " << a / b;
            }
        } else if (op == '%') {
            if (b == 0) {
                cout << "Error: Modulus by zero is not allowed" << endl;
            } else {
                double remainder = fmod(a, b);
                cout << "Result = " << remainder << std::endl;
            }
        } else {
            cout << "Invalid operator" << endl;
        }
        char cont;
        cout << "\nContinue? (y/n): ";
        cin >> cont;
        if (cont == 'n') break;
    }
    return 0;
}
