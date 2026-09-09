#include <iostream>
using namespace std;

bool checkInputofStudents (int n);


int main(){
    int n;
    float score[20];
    cout << "How many students? ";
    cin >> n;

    if (checkInputofStudents(n) == true){
        cout << n << endl;
    }

    else if (checkInputofStudents(n) == false){
        cout << "Invalid input: " << endl; 
        cout << "Invalid number of students!" << endl;
        cout << "Please enter a number from 2 to 20" << endl;
    }

    for (int i = 0; i < n; i++){
        cout << "Enter score for student " << i + 1 << ": ";
        cin >> score[i];

        while (score[i] < 0 || score[i] > 10){
            cout << "Invalid input: " << endl;
            cout << "Invalid score! Please enter a value from 0 to 10: ";
            cin >> score[i];
        }
    }
    return 0;
}

bool checkInputofStudents (int n){
    if (n >= 2 && n <= 20){
        return true;
    }
    else return false;
}

