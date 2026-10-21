#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string department;
    double salary;

    Employee(int empId, string empName, string empDept, double empSalary)
        : id(empId), name(empName), department(empDept), salary(empSalary) {}

    void display() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(15) << department 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;
    string fileName = "employee_records.txt";

public:
    EmployeeManager() {
        loadFromFile();
    }

    void addEmployee(int id, string name, string dept, double salary) {
        employees.push_back(Employee(id, name, dept, salary));
        saveToFile();
        cout << "✅ Employee record added and saved successfully!" << endl;
    }

    void displayAll() const {
        if (employees.empty()) {
            cout << "No records available." << endl;
            return;
        }

        cout << "\n=======================================================\n";
        cout << "              EMPLOYEE RECORDS (STL + FILE)            \n";
        cout << "=======================================================\n";
        cout << left << setw(10) << "ID" 
             << setw(20) << "Name" 
             << setw(15) << "Department" 
             << "Salary" << endl;
        cout << "-------------------------------------------------------\n";

        for (const auto& emp : employees) {
            emp.display();
        }
        cout << "=======================================================\n";
    }

    void saveToFile() {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "Error writing to file!" << endl;
            return;
        }

        for (const auto& emp : employees) {
            outFile << emp.id << "," << emp.name << "," << emp.department << "," << emp.salary << endl;
        }
        outFile.close();
    }

    void loadFromFile() {
        ifstream inFile(fileName);
        if (!inFile) return; // File doesn't exist yet

        employees.clear();
        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                int id = stoi(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string dept = line.substr(pos2 + 1, pos3 - pos2 - 1);
                double salary = stod(line.substr(pos3 + 1));

                employees.push_back(Employee(id, name, dept, salary));
            }
        }
        inFile.close();
    }
};

int main() {
    EmployeeManager manager;
    int choice, id;
    string name, dept;
    double salary;

    do {
        cout << "\n==========================================\n";
        cout << "     EMPLOYEE RECORD SAVER (STL + FILE)   \n";
        cout << "==========================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Exit\n";
        cout << "==========================================\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, dept);
                cout << "Enter Salary: ";
                cin >> salary;
                manager.addEmployee(id, name, dept, salary);
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                cout << "Exiting system. Goodbye! 👋" << endl;
                break;
            default:
                cout << "❌ Invalid choice! Select 1-3." << endl;
        }
    } while (choice != 3);

    return 0;
}
