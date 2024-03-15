#include <iostream>
#pragma warning(disable: 4996);

//TASK 2
//struct Person
//{
//    bool isStudent;
//    short averageGrade;
//    int age;
//};
//
//void createPerson(Person& p)
//{
//    std::cin >> p.isStudent >> p.averageGrade >> p.age;
//}
//
//void printStudent(const Person& p)
//{
//    std::cout << p.isStudent << p.averageGrade << p.age;
//}

//TASK 3
//struct ComplexNumber {
//    double real;
//    double imaginary;
//};
//
//void printComplexNumber(const ComplexNumber& compNum) {
//    std::cout << compNum.real;
//    if (compNum.imaginary > 0) {
//        std::cout << "+";
//    }
//    std::cout << compNum.imaginary << "i";
//}
//
//ComplexNumber substract(const ComplexNumber& num1, const ComplexNumber& num2) {
//    return { num1.real - num2.real, num1.imaginary - num2.imaginary };
//}

//struct Point {
//    double x;
//    double y;
//};
//
//void initPoint(Point& point) {
//    std::cin >> point.x >> point.y;
//}
//
//void printPoint(const Point& point) {
//    std::cout << "(" << point.x << "," << point.y << ")";
//}
//
//double getDistFromCenter(const Point& point) {
//    return sqrt(point.x * point.x + point.y * point.y);
//}
//
//double getDist(const Point& point1, const Point& point2) {
//    double dx = point1.x - point2.x;
//    double dy = point1.y - point2.y;
//
//    return sqrt(dx * dx + dy * dy);
//}
//
//int getQuadrant(const Point& point) {
//    if (point.x >= 0) {
//        if (point.y >= 0) {
//            return 1;
//        } 
//        else {
//            return 4;
//        }
//    }
//    else {
//        if (point.y >= 0) {
//            return 2;
//        }
//        else {
//            return 3;
//        }
//    }
//}
//
//int isInsideCircle(const double radius, const Point& point) {
//    if (getDistFromCenter(point) < radius) {
//        return 1;
//    }
//    else if (getDistFromCenter(point) == radius) {
//        return 0;
//    }
//    return -1;
//}

//TASK 5
const size_t GROUP_SIZE = 5;
const size_t MAX_NAME_SIZE = 40;

struct Student {
    long facultyNumber;
    char name[MAX_NAME_SIZE];
    double grade;
};

struct StudentGroup {
    Student students[GROUP_SIZE];
    double avaregeGrade;
};

void initStudent(Student& student) {
    std::cin >> student.facultyNumber;
    std::cin.ignore();
    std::cin.getline(student.name, MAX_NAME_SIZE, '\n');
    std::cin >> student.grade;
}

void printStudent(const Student& student) {
    std::cout << student.facultyNumber << ", " << student.name << ", " << student.grade << std::endl;
}

StudentGroup createGroup() {
    StudentGroup group;
    double gradesTotal = 0;

    for (int i = 0; i < GROUP_SIZE; i++) {
        initStudent(group.students[i]);
        gradesTotal += group.students[i].grade;
    }

    group.avaregeGrade = gradesTotal / GROUP_SIZE;

    return group;
}

size_t getNumberOfScholars(const StudentGroup& group, const double minGrade) {
    size_t counter = 0;

    for (int i = 0; i < GROUP_SIZE; i++) {
        if (group.students[i].grade >= minGrade) {
            counter++;
        }
    }

    return counter;
}

void copyStudent(Student& destination, const Student& source) {
    destination.facultyNumber = source.facultyNumber;
    destination.grade = source.grade;
    strcpy(destination.name, source.name);
}

void swapStudents(Student& student1, Student& student2) {
    Student studentCopy;
    copyStudent(studentCopy, student1);
    copyStudent(student1, student2);
    copyStudent(student2, studentCopy);
}

void printScholars(const StudentGroup& group, const double minGrade) {
    StudentGroup copyGroup;

    for (int i = 0; i < GROUP_SIZE; i++) {
        copyStudent(copyGroup.students[i], group.students[i]);
    }

    int maxIndex = 0;

    for (int i = 0; i < GROUP_SIZE - 1; i++) {
        maxIndex = i;

        if (copyGroup.students[i].grade < minGrade) {
            continue;
        }

        for (int j = i + 1; j < GROUP_SIZE; j++) {
            if (copyGroup.students[j].grade > copyGroup.students[maxIndex].grade) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swapStudents(copyGroup.students[maxIndex], copyGroup.students[i]);
        }
    }

    for (int i = 0; i < maxIndex; i++) {
        printStudent(copyGroup.students[i]);
    }
}

int main()
{
    /* TASK 1
    Person p;

    createPerson(p);
    printStudent(p);

    Person* personRef = &p;
    std::cout << (*personRef).age;*/

    StudentGroup group = createGroup();

    printScholars(group, 4.5);
}