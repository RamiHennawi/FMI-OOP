#include <iostream>

namespace GlobalConstants {
    constexpr size_t MAX_NAME_SIZE = 30;

}

enum class Subject {
    Algebra,
    Geometry,
    Calculus,
    OOP,
    Other
};

class Teacher {
    int age;
    int salary;
    Subject subject;
    char name[GlobalConstants::MAX_NAME_SIZE];

public: 
    Teacher() {
        age = 18;
        salary = 500;
        subject = Subject::Other;
        strcpy_s(name, "");
    }

    int getAge() const {
        return age;
    }

    int getSalary() const {
        return salary;
    }

    Subject getSubject() const {
        return subject;
    }

    const char* getName() const {
        return name;
    }

    void setAge(int age) {
        if (age < 18) {
            this->age = 18;
        }
        else if (age > 70) {
            this->age = 70;
        }
        else {
            this->age = age;
        }
    }

    void setSalary(int salary) {
        if (salary < 500) {
            this->salary = 500;
        }
        else {
            this->salary = salary;
        }
    }

    void setSubject(Subject subject) {
        this->subject = subject;
    }

    void setName(const char* name) {
        if (strlen(name) > GlobalConstants::MAX_NAME_SIZE) {
            strcpy_s(this->name, "");
        } 
        else {
            strcpy_s(this->name, name);
        }
    }

    void printTeacher() {
        std::cout << name << ", " << age << ", " << (int)subject << ", " << salary << std::endl;
    }
};

int main()
{
    Teacher teacher;

    teacher.setAge(77);
    teacher.setName("Ivan");
    teacher.setSalary(400);
    teacher.setSubject(Subject::Calculus);

    teacher.printTeacher();
}
