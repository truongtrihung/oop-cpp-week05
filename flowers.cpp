#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};


string toLowercase(string str);
void clearBuffer();

void inputFlowers(Flower flowers[], int &n);
void printTable(const Flower flowers[], int n);
void printBasicStats(const Flower flowers[], int n, int &totalQty, double &avgPrice);
void processGroupByType(const Flower flowers[], int n);
void searchTasks(const Flower flowers[], int n);
void valueAndRangeTasks(const Flower flowers[], int n, double &totalValue);
void sortingTasks(const Flower flowers[], int n);
void printFinalReport(int n, int totalQty, double avgPrice, double totalValue);


int main() {
    int n = 0, totalQty = 0;
    double avgPrice = 0, totalValue = 0;
    Flower flowers[20];

    inputFlowers(flowers, n);
    printTable(flowers, n);
    printBasicStats(flowers, n, totalQty, avgPrice);
    processGroupByType(flowers, n);
    searchTasks(flowers, n);
    valueAndRangeTasks(flowers, n, totalValue);
    sortingTasks(flowers, n);
    printFinalReport(n, totalQty, avgPrice, totalValue);

    return 0;
}


string toLowercase(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') c += 32;
    }
    return str;
}

void clearBuffer() {
    cin.ignore(10000, '\n');
}

void inputFlowers(Flower flowers[], int &n) {
    cout << "How many flowers? ";
    cin >> n;
    while (n < 1 || n > 20) {
        cout << "Invalid! Please enter a number from 1 to 20: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nFlower " << i + 1 << ":\n  Name: ";
        clearBuffer();
        getline(cin, flowers[i].name);

        cout << "  Price: ";
        cin >> flowers[i].price;
        while (flowers[i].price <= 0) {
            cout << "  Invalid price (> 0)! Re-enter: ";
            cin >> flowers[i].price;
        }

        cout << "  Quantity: ";
        cin >> flowers[i].quantity;
        while (flowers[i].quantity < 0) {
            cout << "  Invalid quantity (>= 0)! Re-enter: ";
            cin >> flowers[i].quantity;
        }

        cout << "  Type: ";
        clearBuffer();
        getline(cin, flowers[i].type);
    }
}

// [Task 1]
void printTable(const Flower flowers[], int n) {
    cout << "\n[Task 1] ===== FLOWER SHOP =====\n"
         << left << setw(5) << "No" << setw(15) << "Name" << setw(10) << "Price" << setw(8) << "Qty" << "Type\n"
         << string(50, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1 
             << setw(15) << flowers[i].name 
             << setw(10) << fixed << setprecision(1) << flowers[i].price 
             << setw(8) << flowers[i].quantity 
             << flowers[i].type << endl;
    }
}

// [Task 2 - 6]
void printBasicStats(const Flower flowers[], int n, int &totalQty, double &avgPrice) {
    int maxPIdx = 0, minPIdx = 0, maxQIdx = 0;
    totalQty = 0;
    double totalPrice = 0;

    for (int i = 0; i < n; i++) {
        if (flowers[i].price > flowers[maxPIdx].price) maxPIdx = i;
        if (flowers[i].price < flowers[minPIdx].price) minPIdx = i;
        if (flowers[i].quantity > flowers[maxQIdx].quantity) maxQIdx = i;
        totalQty += flowers[i].quantity;
        totalPrice += flowers[i].price;
    }
    avgPrice = (n > 0) ? (totalPrice / n) : 0;

    cout << "\n[Task 2] Most expensive flower: " << flowers[maxPIdx].name << " (" << flowers[maxPIdx].price << ")"
         << "\n[Task 3] Cheapest flower: " << flowers[minPIdx].name << " (" << flowers[minPIdx].price << ")"
         << "\n[Task 4] Flower with largest quantity: " << flowers[maxQIdx].name << " (" << flowers[maxQIdx].quantity << ")"
         << "\n[Task 5] Total quantity of all flowers: " << totalQty
         << "\n[Task 6] Average price of flowers: " << fixed << setprecision(1) << avgPrice << endl;
}

// [Task 7 & Task 19]
void processGroupByType(const Flower flowers[], int n) {
    cout << "\n[Task 7] --- COUNT BY TYPE ---" << endl;
    string checked[20];
    int checkedCount = 0;

    for (int i = 0; i < n; i++) {
        bool counted = false;
        for (int j = 0; j < checkedCount; j++) {
            if (toLowercase(flowers[i].type) == toLowercase(checked[j])) {
                counted = true; 
                break;
            }
        }
        if (!counted) {
            int count = 0, totalQtyType = 0;
            for (int k = 0; k < n; k++) {
                if (toLowercase(flowers[i].type) == toLowercase(flowers[k].type)) {
                    count++;
                    totalQtyType += flowers[k].quantity;
                }
            }
            cout << flowers[i].type << " : " << count << endl;
            checked[checkedCount++] = flowers[i].type;
        }
    }

    cout << "\n[Task 19] --- AVERAGE QUANTITY BY TYPE ---" << endl;
    for (int i = 0; i < checkedCount; i++) {
        int count = 0, totalQtyType = 0;
        for (int k = 0; k < n; k++) {
            if (toLowercase(checked[i]) == toLowercase(flowers[k].type)) {
                count++;
                totalQtyType += flowers[k].quantity;
            }
        }
        cout << checked[i] << " : Average Qty = " << fixed << setprecision(1) << (double)totalQtyType / count << endl;
    }
}

// [Task 8 - 10, Task 18]
void searchTasks(const Flower flowers[], int n) {
    string searchStr;

    // Task 8
    cout << "\n[Task 8] Enter flower type to filter: ";
    clearBuffer(); 
    getline(cin, searchStr);
    cout << "Flowers of type '" << searchStr << "':\n";
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].type) == toLowercase(searchStr))
            cout << "  - " << flowers[i].name << " (" << flowers[i].price << ")\n";
    }

    // Task 9
    cout << "\n[Task 9] Enter flower name to search details: ";
    getline(cin, searchStr);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].name) == toLowercase(searchStr)) {
            cout << "Found!\n  Price: " << flowers[i].price << "\n  Quantity: " << flowers[i].quantity << "\n  Type: " << flowers[i].type << endl;
            found = true; 
            break;
        }
    }
    if (!found) cout << "Not found!\n";

    // Task 10
    cout << "\n[Task 10] Enter flower name to check existence: ";
    getline(cin, searchStr);
    found = false;
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].name) == toLowercase(searchStr)) {
            found = true; 
            break;
        }
    }
    cout << "Exists: " << (found ? "Yes" : "No") << endl;

    // Task 18
    cout << "\n[Task 18] Enter keyword to look up names: ";
    getline(cin, searchStr);
    cout << "Flowers containing keyword '" << searchStr << "':\n";
    for (int i = 0; i < n; i++) {
        if (toLowercase(flowers[i].name).find(toLowercase(searchStr)) != string::npos)
            cout << "  - " << flowers[i].name << endl;
    }
}

// [Task 11 - 14]
void valueAndRangeTasks(const Flower flowers[], int n, double &totalValue) {
    int lowQty = 0, rangeCount = 0, maxValIdx = 0;
    double minP, maxP, maxVal = flowers[0].price * flowers[0].quantity;
    totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (flowers[i].quantity < 5) lowQty++;
        
        double currentVal = flowers[i].price * flowers[i].quantity;
        totalValue += currentVal;
        if (currentVal > maxVal) {
            maxVal = currentVal;
            maxValIdx = i;
        }
    }

    cout << "\n[Task 11] Count of flowers with quantity < 5: " << lowQty << endl;

    // Task 12
    cout << "\n[Task 12] Enter minimum price: "; cin >> minP;
    cout << "Enter maximum price: "; cin >> maxP;
    for (int i = 0; i < n; i++) {
        if (flowers[i].price >= minP && flowers[i].price <= maxP) rangeCount++;
    }
    cout << "Number of flowers in this price range: " << rangeCount << endl;

    cout << "\n[Task 13] Total stock value (price * qty): " << totalValue
         << "\n[Task 14] Most valuable flower asset: " << flowers[maxValIdx].name << " (Total Value: " << maxVal << ")" << endl;
}

// [Task 15 - 17]
void sortingTasks(const Flower flowers[], int n) {
    Flower sorted[20];

    // Task 15 & 17: Sắp xếp theo giá tăng dần
    for (int i = 0; i < n; i++) sorted[i] = flowers[i];
    sort(sorted, sorted + n, [](const Flower &a, const Flower &b) { return a.price < b.price; });

    cout << "\n[Task 15] --- FLOWERS SORTED BY PRICE (ASCENDING) ---" << endl;
    for (int i = 0; i < n; i++) cout << "  - " << sorted[i].name << " : " << sorted[i].price << endl;

    cout << "\n[Task 17] --- TOP 3 MOST EXPENSIVE FLOWERS ---" << endl;
    int limit = min(n, 3);
    for (int i = 0; i < limit; i++) {
        cout << "  " << i + 1 << ". " << sorted[n - 1 - i].name << " (" << sorted[n - 1 - i].price << ")" << endl;
    }

    // Task 16: Sắp xếp theo tên A-Z
    for (int i = 0; i < n; i++) sorted[i] = flowers[i];
    sort(sorted, sorted + n, [](const Flower &a, const Flower &b) {
        return toLowercase(a.name) < toLowercase(b.name);
    });

    cout << "\n[Task 16] --- FLOWERS SORTED BY NAME (A -> Z) ---" << endl;
    for (int i = 0; i < n; i++) cout << "  - " << sorted[i].name << endl;
}

// [Task 20]
void printFinalReport(int n, int totalQty, double avgPrice, double totalValue) {
    cout << "\n[Task 20] ===== FINAL SIMPLE REPORT ====="
         << "\nTotal flower categories : " << n
         << "\nTotal physical quantity  : " << totalQty << " items"
         << "\nAverage stock price      : $" << fixed << setprecision(2) << avgPrice
         << "\nTotal inventory value    : $" << totalValue
         << "\n=========================================" << endl;
}