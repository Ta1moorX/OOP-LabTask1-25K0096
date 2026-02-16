#include <iostream>
using namespace std;

void checkPrime() {
    int num;
    cout << "\n=== PRIME NUMBER CHECKER ===" << endl;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) {
        cout << num << " is NOT a prime number." << endl;
        return;
    }

    bool isPrime = true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << num << " is a PRIME number." << endl;
    } else {
        cout << num << " is NOT a prime number." << endl;
    }
}
