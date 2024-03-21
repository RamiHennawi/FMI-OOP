#include <iostream>

namespace GlobalConstants {
    constexpr size_t MAX_NAME_SIZE = 30;

}

struct Student {
    size_t age;
    long long facultyNumber;
    char name[GlobalConstants::MAX_NAME_SIZE];

    Student() {
        age = 0;
        facultyNumber = 0;
        strcpy(name, "");
    }

    Student(const char* name, const size_t age, const long long fn) {
        strcpy(this->name, name);
        this->age = age;
        this->facultyNumber = fn;
    }
};

int main()
{
    
}
