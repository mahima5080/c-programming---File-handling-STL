#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> studentMap;
    int n, rollNo;
    string name;

    cout << "Enter number of student records: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        studentMap[rollNo] = name;
    }

    cout << "\n==========================================\n";
    cout << "           STUDENT DIRECTORY (MAP)         \n";
    cout << "==========================================\n";
    for (const auto& pair : studentMap) {
        cout << "Roll No: " << pair.first << " | Name: " << pair.second << endl;
    }
    cout << "==========================================\n";

    // Lookup Query
    cout << "\nEnter Roll Number to search: ";
    cin >> rollNo;
    if (studentMap.find(rollNo) != studentMap.end()) {
        cout << "✅ Found: " << studentMap[rollNo] << endl;
    } else {
        cout << "❌ Roll Number not found." << endl;
    }

    return 0;
}
