#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

const int Max_prod = 100;
Product inventory[Max_prod];
int productCount = 0;

void addProduct() {
    if (productCount >= Max_prod) {
        cout << "Inventory is full!" << endl;
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    cout << "\nEnter product details:" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newProduct.name);
    cout << "Price: $";
    cin >> newProduct.price;
    cout << "Quantity: ";
    cin >> newProduct.quantity;

    inventory[productCount++] = newProduct;
    cout << "Product added successfully with ID: " << newProduct.id << endl;
}

void displayProduct(int id) {
    if (id < 1 || id > productCount) {
        cout << "Product not found!" << endl;
        return;
    }

    Product& product = inventory[id - 1];
    cout << "\n--- Product Details ---" << endl;
    cout << "ID: " << product.id << endl;
    cout << "Name: " << product.name << endl;
    cout << "Price: $" << product.price << endl;
    cout << "Quantity in Stock: " << product.quantity << endl;
}

void updateProduct(int id) {
    if (id < 1 || id > productCount) {
        cout << "Product not found!" << endl;
        return;
    }

    Product& product = inventory[id - 1];

    cout << "\nUpdating product: " << product.name << endl;
    cout << "Enter new price (current: $" << product.price << "): $";
    cin >> product.price;
    cout << "Enter new quantity (current: " << product.quantity << "): ";
    cin >> product.quantity;

    cout << "Product updated successfully!" << endl;
}

void removeProduct(int id) {
    if (id < 1 || id > productCount) {
        cout << "Product not found!" << endl;
        return;
    }

    // Shift all products after the removed one
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
        inventory[i].id = i + 1; // Update IDs
    }

    productCount--;
    cout << "Product removed successfully!" << endl;
}

void productManagement() {
    int choice;

    do {
        cout << "\n=== PRODUCT MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. Display Product Details" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Remove Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        int id;

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                cout << "Enter Product ID: ";
                cin >> id;
                displayProduct(id);
                break;
            case 3:
                cout << "Enter Product ID: ";
                cin >> id;
                updateProduct(id);
                break;
            case 4:
                cout << "Enter Product ID: ";
                cin >> id;
                removeProduct(id);
                break;
            case 5:
                cout << "Exiting Product Management System..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
}