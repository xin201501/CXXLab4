#pragma once
#include <string>
#include <string_view>
enum class Sex {
    MALE,
    FEMALE
};
class Student {
private:
    size_t ID;
    std::string name;
    Sex sex;
    double GPA;

public:
    Student() = default;
    Student(size_t id, std::string_view name, Sex sex, double gpa) : ID(id), name(name.data()), sex(sex), GPA(gpa) {}
    size_t getId() const {
        return ID;
    }
    const std::string &getName() const {
        return name;
    }
    void setName(const std::string &name) {
        Student::name = name;
    }
    std::string getSex() const {
        return sex == Sex::MALE ? "male" : "female";
    }
    void setSex(Sex sex) {
        Student::sex = sex;
    }
    double getGpa() const {
        return GPA;
    }
    void setGpa(double gpa) {
        GPA = gpa;
    }
    std::string toString() const {
        return "Student{ID:" + std::to_string(getId()) + ",name:" + getName() + ",sex:" + getSex() + ",GPA:" + std::to_string(GPA) + '}';
    }
    bool operator==(const Student &another) const = default;
    bool operator!=(const Student &another) const = default;
};