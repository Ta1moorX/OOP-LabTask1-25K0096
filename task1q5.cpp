#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void factorialCalculator() {
    cout << "\n=== FACTORIAL CALCULATOR ===" << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = factorial(n);

    if (result == -1) {
        cout << "Factorial is not defined for negative numbers!" << endl;
    } else {
        cout << "Factorial of " << n << " is: " << result << endl;
    }
}
