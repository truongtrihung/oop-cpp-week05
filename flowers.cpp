#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

string toLowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

int main() {
    int n;
    Flower flowers[20];

    cout << "How many flowers? ";
    cin >> n;
    while (n < 1 || n > 20) {
        cout << "Invalid number of flowers! Please enter a number from 1 to 20: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nFlower " << i + 1 << ":" << endl;
        cout << "  Name: ";
        cin.ignore();
        getline(cin, flowers[i].name);

        cout << "  Price: ";
        cin >> flowers[i].price;
        while (flowers[i].price <= 0) {
            cout << "  Invalid price! Price must be > 0. Re-enter: ";
            cin >> flowers[i].price;
        }

        cout << "  Quantity: ";
        cin >> flowers[i].quantity;
        while (flowers[i].quantity < 0) {
            cout << "  Invalid quantity! Quantity must be >= 0. Re-enter: ";
            cin >> flowers[i].quantity;
        }

        cout << "  Type: ";
        cin.ignore();
        getline(cin, flowers[i].type);
    }

    cout << "\n[Task 1] ===== FLOWER SHOP =====" << endl;
    cout << left << setw(5) << "No" << setw(15) << "Name" << setw(10) << "Price" << setw(8) << "Qty" << "Type" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1 
        << setw(15) << flowers[i].name 
        << setw(10) << fixed << setprecision(1) << flowers[i].price 
        << setw(8) << flowers[i].quantity 
        << flowers[i].type << endl;
    }

    int maxPriceIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxPriceIdx].price) {
            maxPriceIdx = i;
        }
    }
        
    cout << "\n[Task 2] Most expensive flower: " << flowers[maxPriceIdx].name << " (" << flowers[maxPriceIdx].price << ")" << endl;

    
    int maxPriceIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxPriceIdx].price) {
            maxPriceIdx = i;
        }
    }
    cout << "\n[Task 2] Most expensive flower: " << flowers[maxPriceIdx].name << " (" << flowers[maxPriceIdx].price << ")" << endl;


    int minPriceIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price < flowers[minPriceIdx].price) {
            minPriceIdx = i;
        }
    }
    cout << "[Task 3] Cheapest flower: " << flowers[minPriceIdx].name << " (" << flowers[minPriceIdx].price << ")" << endl;


    int maxQtyIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].quantity > flowers[maxQtyIdx].quantity) {
            maxQtyIdx = i;
        }
    }
    cout << "[Task 4] Flower with largest quantity: " << flowers[maxQtyIdx].name << " (" << flowers[maxQtyIdx].quantity << ")" << endl;


    int totalQty = 0;
    for (int i = 0; i < n; i++) {
        totalQty += flowers[i].quantity;
    }
    cout << "[Task 5] Total quantity of all flowers: " << totalQty << endl;


    double totalPrice = 0;
    for (int i = 0; i < n; i++) {
        totalPrice += flowers[i].price;
    }
    double avgPrice = (n > 0) ? (totalPrice / n) : 0;
    cout << "[Task 6] Average price of flowers: " << fixed << setprecision(1) << avgPrice << endl;


    
    return 0;
}
