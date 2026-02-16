#include <iostream>
using namespace std;


int* allocateArray(int size) {
    int* arr = new int[size];
    return arr;
}

void dynamicArrayDemo() {
    cout << "\nDYNAMIC ARRAY ALLOCATION" << endl;

    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* dynamicArray = allocateArray(size);

    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> dynamicArray[i];
    }

    cout << "\nArray elements: ";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;


    delete[] dynamicArray;
    cout << "Memory deallocated successfully!" << endl;
}