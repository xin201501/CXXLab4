#include "Stack.h"
#include "min.h"
#include "studentmanagement/StudentManagement.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
int main() {
    cout << "part 1:testing\"min\"template function\n";
    int a1 = 5, b1 = 3;
    double a2 = 7.0, b2 = -5.5;
    char a3[] = "abc", b3[] = "adf";
    cout << "int type(a=5,b=3):" << minValue(a1, b1)
         << " double type(a=7.0,b=-5.5):" << minValue(a2, b2) << R"( char* type(a="abc",b="adf":)" << minValue(a3, b3) << '\n';
    cout << "part 2:testing Stack\n";
    cout << "creating intStack with 16 int numbers(max size is 10):\n";
    Stack<int> intStack;
    try {
        for (int i = 0; i < 16; i++) {
            intStack.Push(i);
        }
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n';
    }
    cout << "try to pop elements from intStack:\n";
    try {
        size_t popCount = 1;
        while (true) {
            int topElement = intStack.Pop();
            cout << "successfully pop " << popCount++ << " element(s) till now,element:" << topElement << '\n';
        }
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n';
    }
    cout << "creating charStack with 5 char elements(max size is 10):\n";
    Stack<char> charStack;
    try {
        char element = 'a';
        for (int i = 0; i < 5; i++) {
            charStack.Push(element);
            element++;
        }
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n';
    }
    cout << "try to pop elements from charStack:\n";
    try {
        size_t popCount = 1;
        while (true) {
            char topElement = charStack.Pop();
            cout << "successfully pop " << popCount++ << " element(s) till now,element:" << topElement << '\n';
        }
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n';
    }
    cout << "part 3:testing vector\n";
    cout << "testing initialize vector from console input:\n";
    std::vector<int> vector;
    cout << "please input numbers,0 represents end:\n";
    int input;
    while (cin >> input && input != 0) {
        vector.push_back(input);
    }
    std::sort(vector.begin(), vector.end());
    cout << "using member function to print all numbers:\n";
    for (size_t i = 0, size = vector.size(); i < size; i++) {
        cout << vector[i] << ' ';
    }
    cout << "\nusing iterator to print all numbers:\n";
    for (auto i = vector.cbegin(); i != vector.cend(); i++) {
        cout << *i << ' ';
    }
    cout << "\nusing for_each to print all numbers:\n";
    std::for_each(vector.cbegin(), vector.cend(), [](int i) {
        std::cout << i << ' ';
    });
    cout << "\npart 4: testing StudentManagement features\n";
    StudentManagement studentManagement;
    auto s1 = new Student(1, "John", Sex::MALE, 4.0), s2 = new Student(2, "Lily", Sex::FEMALE, 3.8),
         s3 = new Student(6, "Gary", Sex::MALE, 4.1), s4 = new Student(5, "Li Hua", Sex::FEMALE, 3.85);
    cout << "try to find student in empty list.\n";
    Student *student1 = studentManagement.findStudentByID(1);
    cout << "test" << (!student1 ? "succeeded" : "failed") << '\n';
    cout << "try to add student.\n";
    studentManagement.addStudent({s1, s2, s3, s4});
    Student *s5 = studentManagement.addStudent(7, "Betty", Sex::FEMALE, 3.9);
    cout << "student list:";
    studentManagement.printStudents();
    cout << "\ndelete student whose ID=6\n";
    studentManagement.removeStudentByID(6);
    cout << "student list:";
    studentManagement.printStudents();
    cout << "\ndelete student not exist in the list.\n";
    studentManagement.removeStudentByID(3);
    cout << "student list:";
    studentManagement.printStudents();
    cout << "\ntest modify student info:\n";
    s1->setGpa(4.1);
    studentManagement.modifyStudentInfo(*s1);
    cout << "student list:";
    studentManagement.printStudents();
    cout << "\ntest find student function(student \"Betty\" exists):\n";
    Student *student = studentManagement.findStudentByName("Betty");
    cout << "student info:" << student->toString();
    cout << "\nall tests ended.";
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
}