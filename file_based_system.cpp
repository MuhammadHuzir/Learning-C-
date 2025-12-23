//
// Created by mhuzz on 23/12/2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Student";
        cout << "\n2. View Student";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream file("student.txt", ios::app);

            long long id;
            std::string name;
            int marks;

            cout << "Enter Student ID: ";
            if (!(cin >> id)) {
                cout << "\nInvalid Student ID\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(); // consume leftover newline

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Marks: ";
            if (!(cin >> marks)) {
                cout << "\nInvalid Marks\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            file << id << "|" << name << "|" << marks << endl;
            file.close();

            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            ifstream file("student.txt");
            if (!file.is_open()) {
                cout << "No student records found.\n";
                continue;
            }

            cout << "\n-----Student List-----\n";
            string line;
            while (getline(file, line)) {
                size_t pos1 = line.find('|');
                size_t pos2 = line.rfind('|');

                if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) continue;

                long long id = stoll(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int marks = stoi(line.substr(pos2 + 1));

                cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "\nInvalid Choice";
        }
    }

    return 0;
}