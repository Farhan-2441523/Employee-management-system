#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Employee {
private:
    int empId;
    string name, department;
public:
    Employee() : empId(0), name("Unknown"), department("Unknown") {}
    void setEmployeeData(int id, const string &empName, const string &dep) {
        empId = id; name = empName; department = dep;
    }
    void displayEmployeeData() const {
        cout << "Employee ID: " << empId << "\nName: " << name << "\nDepartment: " << department << endl;
    }
    int getEmpId() const { return empId; }
};

class EmployeeManager {
private:
    Employee employees[100];
    int employeeCount;
public:
    EmployeeManager() : employeeCount(0) {}
    void clearInput() {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    void addEmployee() {
        if (employeeCount < 100) {
            int id; string name, department;
            cout << "Enter Employee ID (integer): ";
            while (!(cin >> id)) { cout << "Invalid input. Enter a valid integer for Employee ID: "; clearInput(); }
            clearInput();
            cout << "Enter Employee Name: "; getline(cin, name);
            cout << "Enter Department: "; getline(cin, department);
            employees[employeeCount].setEmployeeData(id, name, department);
            employeeCount++;
            cout << "Employee added successfully.\n";
        } else cout << "Error: Employee list is full. Cannot add more employees.\n";
    }
    void displayAllEmployees() const {
        if (employeeCount == 0) cout << "No employees to display.\n";
        else {
            cout << "\nDisplaying all employees:\n";
            for (int i = 0; i < employeeCount; i++) {
                cout << "\nEmployee " << (i + 1) << " Details:\n";
                employees[i].displayEmployeeData();
                cout << "-----------------------\n";
            }
        }
    }
    void searchEmployeeById() const {
        int id;
        cout << "Enter Employee ID to search: ";
        while (!(cin >> id)) { cout << "Invalid input. Enter a valid integer for Employee ID: "; clearInput(); }
        bool found = false;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getEmpId() == id) {
                cout << "\nEmployee found:\n";
                employees[i].displayEmployeeData();
                found = true;
                break;
            }
        }
        if (!found) cout << "Employee with ID " << id << " not found.\n";
    }
    void deleteEmployeeById() {
        int id;
        cout << "Enter Employee ID to delete: ";
        while (!(cin >> id)) { cout << "Invalid input. Enter a valid integer for Employee ID: "; clearInput(); }
        bool found = false;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getEmpId() == id) {
                for (int j = i; j < employeeCount - 1; j++) employees[j] = employees[j + 1];
                employeeCount--;
                cout << "Employee with ID " << id << " deleted successfully.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Employee with ID " << id << " not found.\n";
    }
};

int main() {
    EmployeeManager manager;
    int choice;
    do {
        cout << "\nEmployee Management System\n1. Add Employee\n2. Display All Employees\n3. Search Employee by ID\n4. Delete Employee by ID\n5. Exit\nEnter your choice: ";
        while (!(cin >> choice)) { cout << "Invalid input. Enter a valid integer for choice: "; manager.clearInput(); }
        switch (choice) {
            case 1: manager.addEmployee(); break;
            case 2: manager.displayAllEmployees(); break;
            case 3: manager.searchEmployeeById(); break;
            case 4: manager.deleteEmployeeById(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Please select a valid option (1-5).\n";
        }
    } while (choice != 5);
    return 0;
}

