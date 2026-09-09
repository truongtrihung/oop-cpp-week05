#include <iostream>
using namespace std;

bool checkInputofStudents(int n);

int main() {
    int n;
    float score[20];
    
    cout << "How many students? ";
    cin >> n;
    
    while (checkInputofStudents(n) == false) {
        cout << "Invalid input: " << endl; 
        cout << "Invalid number of students!" << endl;
        cout << "Please enter a number from 2 to 20" << endl;
        cout << "How many students? ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter score for student " << i + 1 << ": ";
        cin >> score[i];

        while (score[i] < 0 || score[i] > 10) {
            cout << "Invalid input: " << endl;
            cout << "Invalid score! Please enter a value from 0 to 10: ";
            cin >> score[i];
        }
    }

    cout << endl;

    int pass = 0;
    int fail = 0;

    cout << "===== STUDENT SCORES =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << score[i];
        if (score[i] >= 5){
            cout << " --> PASS" << endl;
            pass++;
        }
        else if (score[i] < 5){
            cout << " --> FAIL" << endl;
            fail++;
        }
    }
        cout << "===STATISTIC===" << endl;
        cout << "Passed: " << pass << " students" << endl;
        cout << "Failed: " << fail << " students" << endl;
        
    return 0;
}

bool checkInputofStudents(int n) {
    if (n >= 2 && n <= 20) {
        return true;
    }
    return false;
}
