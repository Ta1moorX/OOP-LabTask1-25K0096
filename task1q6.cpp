#include <iostream>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int publicationYear;
    string genre;
};

const int Max_books = 100;
Book library[Max_books];
int bookCount = 0;

void displayBook(const Book& book) {
    cout << "\nBook Details" << endl;
    cout << "ID: " << book.id << endl;
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Publication Year: " << book.publicationYear << endl;
    cout << "Genre: " << book.genre << endl;
}

void addBook() {
    if (bookCount >= Max_books) {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;

    cout << "\nEnter book details:" << endl;
    cout << "Title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Author: ";
    getline(cin, newBook.author);
    cout << "Publication Year: ";
    cin >> newBook.publicationYear;
    cin.ignore();
    cout << "Genre: ";
    getline(cin, newBook.genre);

    library[bookCount++] = newBook;
    cout << "Book added successfully with ID: " << newBook.id << endl;
}

void searchBook() {
    if (bookCount == 0) {
        cout << "No books in the library!" << endl;
        return;
    }

    int choice;
    cout << "\nSearch by:" << endl;
    cout << "1. Title" << endl;
    cout << "2. Author" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    string searchTerm;
    bool found = false;

    if (choice == 1) {
        cout << "Enter title: ";
        getline(cin, searchTerm);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].title.find(searchTerm) != string::npos) {
                displayBook(library[i]);
                found = true;
            }
        }
    } else if (choice == 2) {
        cout << "Enter author: ";
        getline(cin, searchTerm);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].author.find(searchTerm) != string::npos) {
                displayBook(library[i]);
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No books found!" << endl;
    }
}

void updateBook() {
    if (bookCount == 0) {
        cout << "No books in the library!" << endl;
        return;
    }

    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;

    if (id < 1 || id > bookCount) {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    Book& book = library[id - 1];

    cout << "\nUpdating book: " << book.title << endl;
    cout << "Enter new details (press Enter to keep current value):" << endl;

    cin.ignore();
    string input;

    cout << "Title [" << book.title << "]: ";
    getline(cin, input);
    if (!input.empty()) book.title = input;

    cout << "Author [" << book.author << "]: ";
    getline(cin, input);
    if (!input.empty()) book.author = input;

    cout << "Publication Year [" << book.publicationYear << "]: ";
    getline(cin, input);
    if (!input.empty()) book.publicationYear = stoi(input);

    cout << "Genre [" << book.genre << "]: ";
    getline(cin, input);
    if (!input.empty()) book.genre = input;

    cout << "Book updated successfully!" << endl;
}

void displayAllBooks() {
    if (bookCount == 0) {
        cout << "No books in the library!" << endl;
        return;
    }

    cout << "\nALL BOOKS" << endl;
    for (int i = 0; i < bookCount; i++) {
        displayBook(library[i]);
    }
}

void libraryManagement() {
    int choice;

    do {
        cout << "\nLIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                displayAllBooks();
                break;
            case 5:
                cout << "Exiting Library Management System..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
}
