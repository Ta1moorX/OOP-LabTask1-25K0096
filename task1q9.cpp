#include <iostream>
using namespace std;


void add(int* a, int* b, int* result) {
    *result = *a + *b;
}

void subtract(int* a, int* b, int* result) {
    *result = *a - *b;
}

void multiply(int* a, int* b, int* result) {
    *result = *a * *b;
}

void divide(int* a, int* b, double* result) {
    if (*b != 0) {
        *result = (double)(*a) / (*b);
    } else {
        *result = 0;
    }
}

void pointerCalculator() {
    cout << "\n=== POINTER-BASED CALCULATOR ===" << endl;

    int num1, num2, intResult;
    double doubleResult;

    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;

    int* ptr1 = &num1;
    int* ptr2 = &num2;
    int* ptrResult = &intResult;
    double* ptrDoubleResult = &doubleResult;

    cout << "\nSelect operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            add(ptr1, ptr2, ptrResult);
            cout << "Result: " << *ptrResult << endl;
            break;
        case 2:
            subtract(ptr1, ptr2, ptrResult);
            cout << "Result: " << *ptrResult << endl;
            break;
        case 3:
            multiply(ptr1, ptr2, ptrResult);
            cout << "Result: " << *ptrResult << endl;
            break;
        case 4:
            divide(ptr1, ptr2, ptrDoubleResult);
            if (*ptr2 == 0) {
                cout << "Error! Division by zero." << endl;
            } else {
                cout << "Result: " << *ptrDoubleResult << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}