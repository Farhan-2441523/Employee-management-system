#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name, department;
    void setData(int empId, string empName, string empDept) {
        id = empId; name = empName; department = empDept;
    }
    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Department: " << department << endl;
    }
};

class EmployeeManager {
    Employee employees[100];
    int count = 0;
public:
    void addEmployee() {
        if (count < 100) {
            int id; string name, dept;
            cout << "Enter ID, Name, Department: ";
            cin >> id >> name >> dept;
            employees[count++].setData(id, name, dept);
            cout << "Employee added!\n";
        } else cout << "Employee list full!\n";
    }
    void displayAll() {
        if (count == 0) cout << "No employees found!\n";
        else for (int i = 0; i < count; i++) employees[i].display();
    }
    void searchById() {
        int id; cout << "Enter ID: "; cin >> id;
        for (int i = 0; i < count; i++) if (employees[i].id == id) { employees[i].display(); return; }
        cout << "Employee not found!\n";
    }
    void deleteById() {
        int id; cout << "Enter ID: "; cin >> id;
        for (int i = 0; i < count; i++) {
            if (employees[i].id == id) {
                employees[i] = employees[--count];
                cout << "Employee deleted!\n";
                return;
            }
        }
        cout << "Employee not found!\n";
    }
};

int main() {
    EmployeeManager manager;
    int choice;
    do {
        cout << "\n1. Add\n2. Display\n3. Search\n4. Delete\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: manager.addEmployee(); break;
            case
