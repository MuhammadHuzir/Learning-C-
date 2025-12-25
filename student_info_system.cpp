//
// Created by mhuzz on 23/12/2025.
//

#include "student_info_system.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

int getMenuChoice() {

    int choice;

    cout << "\n1. Add Student";
    cout << "\n2. View Student";
    cout << "\n3. Update Student";
    cout << "\n4. Delete Student";
    cout << "\n5. Exit";
    cout << "\nEnter Choice: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

void addStudent(vector<Student>& students) {

    Student s;

    cout << "Enter Student ID: ";
    if (!(cin >> s.id)) {
        cout << "\nInvalid Student ID\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();

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

    students.push_back(s);

    cout << "Student added successfully!\n";
}

void viewStudent(const vector<Student>& students) {

    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n-----Student List-----\n";
    for (const Student& s : students) {
        cout << "ID: " << s.id
             << ", Name: " << s.name
             << ", Marks: " << s.marks << endl;
    }
}

void updateStudent(vector<Student>& students) {

    long long id;

    cout << "\nEnter Student ID you wish to edit: ";
    cin >> id;

    Student* s = findStudentByID(students, id);
    if (!s) {
        cout << "\nStudent ID not found.\n";
        return;
    }

    cout << "\nEnter Student Name: ";
    cin.ignore();
    getline(cin, s->name);

    cout << "\nEnter Marks: ";
    cin >> s->marks;

    cout << "\nStudent Updated Successfully!\n";

}

void deleteStudent(vector<Student>& students) {

    long long id;

    cout << "\nEnter Student ID you wish to delete: ";
    cin >> id;

    Student* s = findStudentByID(students, id);
    if (!s) {
        cout << "Student not found.\n";
        return;
    }

    students.erase(remove_if(students.begin(), students.end(),
        [id](const Student& s) { return s.id == id; }), students.end());

    cout << "\nStudent Deleted Successfully!\n";

}

void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error saving file!\n";
        return;
    }

    for (const Student& s : students) {
        file << s.id << "|" << s.name << "|" << s.marks << "\n";
    }
}

void loadFromFile(vector<Student>& students) {
    ifstream file("students.txt");
    if (!file) return; // No file yet

    students.clear(); // start fresh

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.rfind('|');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2)
            continue;

        Student s;
        s.id = stoll(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.marks = stoi(line.substr(pos2 + 1));

        students.push_back(s);
    }
}

Student* findStudentByID(std::vector<Student>& students, long long id) {
    for (Student& s : students) {
        if (s.id == id) return &s;
    }
    return nullptr;
}