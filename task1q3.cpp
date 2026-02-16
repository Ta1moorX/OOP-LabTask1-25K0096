#include <iostream>
using namespace std;

void simpleCalculator() {
    cout << "\nSIMPLE CALCULATOR" << endl;
    cout << "Select operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;

    int choice;
    double num1, num2;

    cout << "Enter choice (1-4): ";
    cin >> choice;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nResult: ";

    switch(choice) {
        case 1:

            num1 -= (-num2);
            cout << num1 << endl;
            break;
        case 2:
            cout << (num1 - num2) << endl;
            break;
        case 3:
            cout << (num1 * num2) << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << (num1 / num2) << endl;
            } else {
                cout << "Error! Division by zero." << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}