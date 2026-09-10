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


    cout << "\n[Task 7] --- COUNT BY TYPE ---" << endl;
    string checkedTypes[20];
    int checkedCount = 0;
    for (int i = 0; i < n; i++) {
        bool alreadyCounted = false;
        for (int j = 0; j < checkedCount; j++) {
            if (toLowercase(flowers[i].type) == toLowercase(checkedTypes[j])) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            int typeCount = 0;
            for (int k = 0; k < n; k++) {
                if (toLowercase(flowers[i].type) == toLowercase(flowers[k].type)) {
                    typeCount++;
                }
            }
            cout << flowers[i].type << " : " << typeCount << endl;
            checkedTypes[checkedCount++] = flowers[i].type;
        }
    }


    string searchType;
    cout << "\n[Task 8] Enter flower type to filter: ";
    getline(cin, searchType);
    cout << "Flowers of type '" << searchType << "':" << endl;
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].type) == toLowercase(searchType)) {
            cout << "  - " << flowers[i].name << " (" << flowers[i].price << ")" << endl;
        }
    }


    string searchName;
    cout << "\n[Task 9] Enter flower name to search details: ";
    getline(cin, searchName);
    bool nameFound = false;
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].name) == toLowercase(searchName)) {
            cout << "Found!\n  Price: " << flowers[i].price << "\n  Quantity: " << flowers[i].quantity << "\n  Type: " << flowers[i].type << endl;
            nameFound = true;
            break;
        }
    }
    if (!nameFound) cout << "Not found!" << endl;


    string checkName;
    cout << "\n[Task 10] Enter flower name to check existence: ";
    getline(cin, checkName);
    bool exists = false;
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].name) == toLowercase(checkName)) {
            exists = true;
            break;
        }
    }
    cout << "Exists: " << (exists ? "Yes" : "No") << endl;


    int lowQtyCount = 0;
    for (int i = 0; i < n; i++) {
        if (flowers[i].quantity < 5) {
            lowQtyCount++;
        }
    }
    cout << "\n[Task 11] Count of flowers with quantity < 5: " << lowQtyCount << endl;


    double minP, maxP;
    cout << "\n[Task 12] Enter minimum price: "; cin >> minP;
    cout << "Enter maximum price: "; cin >> maxP;
    cin.ignore();
    int rangeCount = 0;
    for (int i = 0; i < n; i++) {
        if (flowers[i].price >= minP && flowers[i].price <= maxP) {
            rangeCount++;
        }
    }
    cout << "Number of flowers in this price range: " << rangeCount << endl;


    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += (flowers[i].price * flowers[i].quantity);
    }
    cout << "\n[Task 13] Total stock value (price * qty) of all flowers: " << totalValue << endl;


    int maxValIdx = 0;
    double maxVal = flowers[0].price * flowers[0].quantity;
    for (int i = 1; i < n; i++) {
        double currentVal = flowers[i].price * flowers[i].quantity;
        if (currentVal > maxVal) {
            maxVal = currentVal;
            maxValIdx = i;
        }
    }
    cout << "[Task 14] Most valuable flower asset: " << flowers[maxValIdx].name << " (Total Value: " << maxVal << ")" << endl;



    // Sao chép mảng gốc ra mảng tạm để tránh thay đổi trật tự gốc nếu cần dùng sau này
    Flower sortedByPrice[20];
    for(int i=0; i<n; i++) sortedByPrice[i] = flowers[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sortedByPrice[i].price > sortedByPrice[j].price) {
                Flower temp = sortedByPrice[i];
                sortedByPrice[i] = sortedByPrice[j];
                sortedByPrice[j] = temp;
            }
        }
    }
    cout << "\n[Task 15] --- FLOWERS SORTED BY PRICE (ASCENDING) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  - " << sortedByPrice[i].name << " : " << sortedByPrice[i].price << endl;
    }


    return 0;
}
