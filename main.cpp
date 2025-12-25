#include "student_info_system.h"
#include <vector>
#include <iostream>

int main() {

    std::vector<Student> students;
    loadFromFile(students);

    while (true) {
        int choice = getMenuChoice();

        if (choice == 1) {
            addStudent(students);
            saveToFile(students);
        }
        else if (choice == 2) {
            viewStudent(students);
        }
        else if (choice == 3) {
            updateStudent(students);
            saveToFile(students);
        }
        else if (choice == 4) {
            deleteStudent(students);
            saveToFile(students);
        }
        else if (choice == 5) {
            break;
        }
        else { std::cout << "Invalid Choice\n"; }
    }
}