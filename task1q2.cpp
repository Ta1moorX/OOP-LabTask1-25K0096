#include <iostream>
using namespace std;


void studentMarksManagement() {
    cout << "\n=== STUDENT MARKS MANAGEMENT ===" << endl;

    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        string name;
        float pf, oop, dld, ict;

        cout << "\nStudent " << (i + 1) << ":" << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter marks for PF: ";
        cin >> pf;
        cout << "Enter marks for OOP: ";
        cin >> oop;
        cout << "Enter marks for DLD: ";
        cin >> dld;
        cout << "Enter marks for ICT: ";
        cin >> ict;

        float total = pf + oop + dld + ict;
        float average = total / 4.0;

        char grade;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        cout << "\n--- Results for " << name << " ---" << endl;
        cout << "Total Marks: " << total << "/400" << endl;
        cout << "Average: " << average << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
}
