#pragma once
#include "List.h"
#include "Student.h"
#include <initializer_list>
class StudentManagement {
private:
    List<Student> students;
    size_t studentNum = 0;

public:
    StudentManagement() = default;
    StudentManagement(std::initializer_list<Student *> studentList) {
        addStudent(studentList);
    }
    size_t getStudentNum() const {
        return studentNum;
    }
    Student *addStudent(size_t ID, std::string_view name, Sex sex, double GPA) {
        if (findStudentByID(ID)) {
            return nullptr;
        }
        auto newStudent = new Student(ID, name.data(), sex, GPA);
        students.Add(*newStudent);
        return newStudent;
    }
    void addStudent(std::initializer_list<Student *> studentList) {
        for (auto student : studentList) {
            students.Add(*student);
            studentNum++;
        }
    }
    bool removeStudentByID(size_t ID) {
        Student *student = findStudentByID(ID);
        if (student == nullptr) {
            return false;
        }
        students.Remove(*student);
        return true;
    }
    bool removeStudentByName(std::string_view name) {
        Student *student = findStudentByName(name);
        if (student == nullptr) {
            return false;
        }
        students.Remove(*student);
        return true;
    }
    bool modifyStudentInfo(Student &newInfo) {
        if (!removeStudentByID(newInfo.getId())) {
            return false;
        }
        students.Add(newInfo);
        return true;
    }
    Student *findStudentByID(size_t ID) {
        for (auto cur = students.pFirst->pNext; cur; cur = cur->pNext) {
            if (cur->pT->getId() == ID) {
                return cur->pT;
            }
        }
        return nullptr;
    }
    Student *findStudentByName(std::string_view name) {
        for (auto cur = students.pFirst->pNext; cur; cur = cur->pNext) {
            if (cur->pT->getName() == name) {
                return cur->pT;
            }
        }
        return nullptr;
    }
    void printStudents() {
        students.PrintList();
    }
    ~StudentManagement() = default;
};