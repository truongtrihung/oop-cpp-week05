#include <iostream>
using namespace std;

bool checkInputofStudents (int n);

int main(){
    int n;
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
    return 0;
}

bool checkInputofStudents (int n){
    if (n >= 2 && n <= 20){
        return true;
    }
    else return false;
}