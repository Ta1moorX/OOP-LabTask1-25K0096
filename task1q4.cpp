#include <iostream>
using namespace std;

void countEvenOdd() {
    cout << "\n=== EVEN AND ODD COUNTER ===" << endl;

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "\nEven numbers count: " << evenCount << endl;
    cout << "Odd numbers count: " << oddCount << endl;
}