#include <iostream>
#include <fstream>
#include <sstream>

namespace GlobalConstants {
    constexpr size_t MAX_NAME_SIZE = 16;
    constexpr size_t MAX_FACULTY_NUMBER_SIZE = 5;
    constexpr size_t GRADE_SIZE = 5;
    constexpr size_t MAX_STUDENTS = 10;
    constexpr size_t BUFFER_SIZE = 100;
    constexpr size_t BUFFER_NUMBER_SIZE = 5;
    constexpr char SEP = ',';
}

constexpr char inputFile[] = "input.csv";
constexpr char outputFile[] = "output.csv";

enum class HairColor {
    Brown,
    Black,
    Blonde,
    Red,
    White
};

struct Student {
    char firstName[GlobalConstants::MAX_NAME_SIZE] = {};
    char secondName[GlobalConstants::MAX_NAME_SIZE] = {};
    int facultyNumber;
    double averageGrade = 0; // assume it is of form N.NN, where N is a digit
    HairColor hairColor;
};

struct StudentsTable {
    Student students[GlobalConstants::MAX_STUDENTS];
    size_t rowsCount = 0;
};

//const char* hairColorToString(const HairColor hairColor) {
//    switch (hairColor) {
//    case HairColor::Brown: return "Brown";
//    case HairColor::Black: return "Black";
//    case HairColor::Blonde: return "Blonde";
//    case HairColor::Red: return "Red";
//    case HairColor::White: return "White";
//    default: return "Unknown";
//    }
//}

int getFacultyNumber(const char* fnString) {
    int number = 0;

    for (int i = 0; fnString[i] != '\0'; i++) {
        number = number * 10 + (fnString[i] - '0');
    }

    return number;
}

double getAverageGrade(const char* averageGrade) {
    double grade = (averageGrade[0] - '0');

    for (int i = 2; averageGrade[i] != '\0'; i++) {
        grade = grade + pow(0.1, i - 1) * (averageGrade[i] - '0');
    }
    
    return grade;
}

void printStudent(std::ofstream& out, const Student& student) {
    out << student.firstName << GlobalConstants::SEP << student.secondName << GlobalConstants::SEP
        << student.facultyNumber << GlobalConstants::SEP << student.averageGrade << GlobalConstants::SEP
        << (int)student.hairColor;
}

void printStudentsTable(std::ofstream& out, const StudentsTable& studentsTable){
    for (int i = 0; i < studentsTable.rowsCount; i++) {
        printStudent(out, studentsTable.students[i]);

        if (i != studentsTable.rowsCount - 1) {
            out << std::endl;
        }
    }
}

void parseStudent(const char* studentRow, Student& student) {
    std::stringstream row(studentRow);
    row.clear();
    
    char buffer[GlobalConstants::BUFFER_NUMBER_SIZE + 1];

    while (!row.eof()) {
        row.getline(student.firstName, GlobalConstants::MAX_NAME_SIZE, GlobalConstants::SEP);
        row.getline(student.secondName, GlobalConstants::MAX_NAME_SIZE, GlobalConstants::SEP);
        
        row.getline(buffer, GlobalConstants::MAX_FACULTY_NUMBER_SIZE + 1, GlobalConstants::SEP);
        student.facultyNumber = getFacultyNumber(buffer);

        row.getline(buffer, GlobalConstants::GRADE_SIZE + 1, GlobalConstants::SEP);
        student.averageGrade = getAverageGrade(buffer);
        
        char hairColorNumber;
        row.get(hairColorNumber);
        student.hairColor = (HairColor)(hairColorNumber - '0');

        row.ignore();
    }
}

StudentsTable parseStudentsTable(std::ifstream& in) {
    StudentsTable studentsTable;
    char buffer[GlobalConstants::BUFFER_SIZE];
    size_t numberOfStudents = 0;

    while (!in.eof()) {
        in.getline(buffer, GlobalConstants::BUFFER_SIZE);
        parseStudent(buffer, studentsTable.students[numberOfStudents++]);
    }

    studentsTable.rowsCount = numberOfStudents;

    return studentsTable;
}

int main()
{
    std::ofstream out(outputFile, std::ios::out);

    if (!out.is_open()) {
        return -1;
    }

    std::ifstream in(inputFile, std::ios::in);

    if (!in.is_open()) {
        out.close();
        return -1;
    }

    //Student students[] = { { "Ivan", "Ivanov", 43132, 4.50, HairColor::Black },
    //                       { "AZ", "AZov", 4323, 5.50, HairColor::Blonde },
    //                       { "Haha", "Petrov", 5357, 3.00, HairColor::Red }};
    //
    //StudentsTable studentsTable;
    //
    //for (int i = 0; i < 3; i++) {
    //    studentsTable.students[i] = students[i];
    //}
    //
    //studentsTable.rowsCount = 3;
    //
    //printStudentsTable(out, studentsTable);

    StudentsTable studentsTable;
    studentsTable = parseStudentsTable(in);

    printStudentsTable(out, studentsTable);

    out.close();
    in.close();
}
