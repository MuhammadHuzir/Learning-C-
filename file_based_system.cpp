//
// Created by mhuzz on 23/12/2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

struct Student {
    long long id;
    string name;
    int marks;
};

void addStudent() {

    Student s;

    ofstream file("student.txt", ios::app);
    if (!file) {
        cout << "Error opening file\n";
        return;
    }

    cout << "Enter Student ID: ";
    if (!(cin >> s.id)) {
        cout << "\nInvalid Student ID\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(); // consume leftover newline

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    while (true) {
        cout << "Enter Marks: ";
        if (!(cin >> s.marks)) {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (s.marks < 0 || s.marks > 100) {
            cout << "Marks must be between 0 and 100.\n";
            continue;
        }

        break;
    }

    file << s.id << "|" << s.name << "|" << s.marks << endl;
    file.close();

    cout << "Student added successfully!\n";
}

void viewStudent() {

    Student s;

    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n-----Student List-----\n";
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.rfind('|');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) continue;

        s.id = stoll(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.marks = stoi(line.substr(pos2 + 1));

        cout << "ID: " << s.id << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }
}

int getMenuChoice() {

    int choice;

    cout << "\n1. Add Student";
    cout << "\n2. View Student";
    cout << "\n3. Exit";
    cout << "\nEnter Choice: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

int main() {

    while (true) {
        int choice = getMenuChoice();
        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            viewStudent();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "\nInvalid Choice";
        }
    }
}