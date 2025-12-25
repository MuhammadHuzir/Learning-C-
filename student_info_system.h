#pragma once
#include <string>
#include <vector>

struct Student {
    long long id;
    std::string name;
    int marks;
};

void addStudent(std::vector<Student>& student);
void viewStudent(const std::vector<Student>& student);
void updateStudent(std::vector<Student>& student);
void deleteStudent(std::vector<Student>& student);

void saveToFile(const std::vector<Student>& student);
void loadFromFile(std::vector<Student>& student);

int getMenuChoice();

Student* findStudentByID(std::vector<Student>& students, long long id);