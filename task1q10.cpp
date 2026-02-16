#include <iostream>
using namespace std;




int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int** matrix, int rows, int cols, string name) {
    cout << "\nEnter elements for " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols, string name) {
    cout << "\n" << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrices(int** A, int** B, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int** A, int** B, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int** A, int** B, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void matrixWizard() {
    cout << "\n=== MATRIX WIZARD ===" << endl;

    int rows1, cols1, rows2, cols2;

    cout << "Enter rows for Matrix A: ";
    cin >> rows1;
    cout << "Enter columns for Matrix A: ";
    cin >> cols1;

    int** matrixA = allocateMatrix(rows1, cols1);
    inputMatrix(matrixA, rows1, cols1, "Matrix A");
    displayMatrix(matrixA, rows1, cols1, "Matrix A");

    cout << "\nEnter rows for Matrix B: ";
    cin >> rows2;
    cout << "Enter columns for Matrix B: ";
    cin >> cols2;

    int** matrixB = allocateMatrix(rows2, cols2);
    inputMatrix(matrixB, rows2, cols2, "Matrix B");
    displayMatrix(matrixB, rows2, cols2, "Matrix B");


    if (rows1 == rows2 && cols1 == cols2) {
        int** result = allocateMatrix(rows1, cols1);

        addMatrices(matrixA, matrixB, result, rows1, cols1);
        displayMatrix(result, rows1, cols1, "A + B");

        subtractMatrices(matrixA, matrixB, result, rows1, cols1);
        displayMatrix(result, rows1, cols1, "A - B");

        deallocateMatrix(result, rows1);
    } else {
        cout << "\nMatrices cannot be added/subtracted (different dimensions)" << endl;
    }


    if (cols1 == rows2) {
        int** result = allocateMatrix(rows1, cols2);

        multiplyMatrices(matrixA, matrixB, result, rows1, cols1, cols2);
        displayMatrix(result, rows1, cols2, "A * B");

        deallocateMatrix(result, rows1);
    } else {
        cout << "\nMatrices cannot be multiplied (incompatible dimensions)" << endl;
        cout << "For multiplication: columns of A must equal rows of B" << endl;
    }


    deallocateMatrix(matrixA, rows1);
    deallocateMatrix(matrixB, rows2);

    cout << "\nMemory cleaned up successfully!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n";
        cout << "========================================" << endl;
        cout << "    C++ PROGRAMMING SOLUTIONS MENU" << endl;
        cout << "========================================" << endl;
        cout << "1.  Prime Number Checker" << endl;
        cout << "2.  Student Marks Management" << endl;
        cout << "3.  Simple Calculator" << endl;
        cout << "4.  Count Even and Odd Numbers" << endl;
        cout << "5.  Factorial Calculator" << endl;
        cout << "6.  Library Management System" << endl;
        cout << "7.  Product Management System" << endl;
        cout << "8.  Dynamic Array Allocation" << endl;
        cout << "9.  Pointer-Based Calculator" << endl;
        cout << "10. Matrix Wizard" << endl;
        cout << "0.  Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                checkPrime();
                break;
            case 2:
                studentMarksManagement();
                break;
            case 3:
                simpleCalculator();
                break;
            case 4:
                countEvenOdd();
                break;
            case 5:
                factorialCalculator();
                break;
            case 6:
                libraryManagement();
                break;
            case 7:
                productManagement();
                break;
            case 8:
                dynamicArrayDemo();
                break;
            case 9:
                pointerCalculator();
                break;
            case 10:
                matrixWizard();
                break;
            case 0:
                cout << "\nThank you for using the program! Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}