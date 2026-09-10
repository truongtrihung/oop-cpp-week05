#include <iostream>
using namespace std;

bool checkInputofStudents(int n);

int main() {
    int n;
    float score[20];
    float sum = 0; 
    
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
        sum += score[i]; 
    }

    cout << endl;

    int pass = 0;
    int fail = 0;
    int excellent = 0;
    
    float max_score = score[0];
    float second_max = -1; 
    float min_score = score[0];

    cout << "===== CLASSIFICATION =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << score[i] << " -> ";
        
        if (score[i] >= 9 && score[i] <= 10) {
            cout << "Excellent" << endl;
            pass++;
            excellent++;
        }
        else if (score[i] >= 8 && score[i] < 9) {
            cout << "Very Good" << endl;
            pass++;
        }
        else if (score[i] >= 6.5 && score[i] < 8) {
            cout << "Good" << endl;
            pass++;
        }
        else if (score[i] >= 5 && score[i] < 6.5) {
            cout << "Average" << endl;
            pass++;
        }
        else { 
            cout << "Fail" << endl;
            fail++;
        }

        if (score[i] > max_score) {
            second_max = max_score; 
            max_score = score[i];   
        }
        else if (score[i] < max_score && score[i] > second_max) {
            second_max = score[i];   
        }

        if (score[i] < min_score) {
            min_score = score[i];
        }
    }

    cout << endl;

    cout << "=== STATISTIC ===" << endl;
    cout << "Passed: " << pass << " students" << endl;
    cout << "Failed: " << fail << " students" << endl;
    cout << "Excellent students: " << excellent << endl;
    cout << "Highest score: " << max_score << endl;
    
    if (second_max != -1) {
        cout << "Second highest score: " << second_max << endl;
    } else {
        cout << "Second highest score: N/A" << endl;
    }
    cout << "Lowest score : " << min_score << endl;
    
    cout << endl;

    // === PHẦN BÀI 2: ĐẾM HỌC SINH TRONG KHOẢNG ĐIỂM [a, b] ===
    float a, b;
    int count_in_range = 0;
    cout << "Enter minimum score: ";
    cin >> a;
    cout << "Enter maximum score: ";
    cin >> b;

    for (int i = 0; i < n; i++) {
        if (score[i] >= a && score[i] <= b) {
            count_in_range++;
        }
    }
    cout << "Students in range: " << count_in_range << endl;
    
    cout << endl;

    // === PHẦN BÀI 3: TÌM HỌC SINH TRÊN TRUNG BÌNH ===
    float average = sum / n; 
    cout << "Average score: " << average << endl;
    cout << endl;

    cout << "Students above average:" << endl;
    for (int i = 0; i < n; i++) {
        if (score[i] > average) { 
            cout << "Student " << i + 1 << ": " << score[i] << endl;
        }
    }
    
    cout << endl;

    // === PHẦN BÀI 5: TÌM KIẾM ĐIỂM SỐ ===
    float score_to_search;
    bool found = false;

    cout << "Enter score to search: ";
    cin >> score_to_search;
    cout << endl;

    cout << "Found at:" << endl;
    for (int i = 0; i < n; i++) {
        if (score[i] == score_to_search) {
            cout << "Student " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No student has this score." << endl;
    }

    cout << endl;

    // === PHẦN BÀI 6: ĐẾM TẦN SUẤT XUẤT HIỆN ===
    float x;
    int frequency = 0;

    cout << "Enter score: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (score[i] == x) {
            frequency++;
        }
    }
    cout << "Score " << x << " appears " << frequency << " times." << endl;
        
    cout << endl;

    // === PHẦN BÀI 7: TÌM HỌC SINH TRƯỢT ĐẦU TIÊN ===
    bool has_failing = false;

    for (int i = 0; i < n; i++) {
        if (score[i] < 5) {
            cout << "First failing student:" << endl;
            cout << "Student " << i + 1 << ": " << score[i] << endl;
            has_failing = true;
            break; 
        }
    }

    if (has_failing == false) {
        cout << "All students pass!" << endl;
    }

    cout << endl;

    // === PHẦN BỔ SUNG BÀI 8: SO SÁNH CÁC HỌC SINH KẾ CẬN ===
    cout << "=== ADJACENT COMPARISON ===" << endl;
    bool has_improvement = false;
    for (int i = 1; i < n; i++) {
        if (score[i] > score[i - 1]) {
            cout << "Student " << i + 1 << " improved compared to Student " << i << endl;
            has_improvement = true;
        }
    }
    
    if (!has_improvement) {
        cout << "No student has a higher score than the previous one." << endl;
    }

    return 0;
}

bool checkInputofStudents(int n) {
    if (n >= 2 && n <= 20) {
        return true;
    }
    return false;
}
