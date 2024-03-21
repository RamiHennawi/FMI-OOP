#include <iostream>
#include <fstream>
#pragma warning(disable: 4996);

namespace GlobalConstants {
    constexpr size_t MAX_PROBLEM_SIZE = 400;
    constexpr size_t MAX_TEST_PROBLEMS = 30;
    constexpr size_t MAX_PASSWORD_SIZE = 30;
}

class Problem {
    char answer;
    int points;
    char password[GlobalConstants::MAX_PASSWORD_SIZE];
    char text[GlobalConstants::MAX_PROBLEM_SIZE];

public: 
    Problem() {
        answer = 'a';
        points = 0;
        strcpy(password, "1234");
        strcpy(text, "");
    }

    Problem(char answer, int points, const char* password, const char* text): Problem() {
        this->answer = answer;
        this->points = points;
        if (password != nullptr) strcpy(this->password, password);
        if (text != nullptr) strcpy(this->text, text);
    }

    const char* getText() const {
        return text;
    }

    char getAnswer() const {
        return answer;
    }

    int getPoints() const {
        return points;
    }
    
    void changeText(const char* password, const char* newText) {
        if (strcmp(this->password, password) == 0) {
            strcpy(text, newText);
        }
        else {
            std::cout << "Invalid password!";
        }
    }

    void changeAnswer(const char* password, char newAnswer) {
        if (strcmp(this->password, password) == 0) {
            this->answer = newAnswer;
        }
        else {
            std::cout << "Invalid password!";
        }
    }

    void changePoints(const char* password, int newPoints) {
        if (strcmp(this->password, password) == 0) {
            this->points = newPoints;
        }
        else {
            std::cout << "Invalid password!";
        }
    }
};

class Test {
    size_t problemsCount = 0;
    Problem problems[GlobalConstants::MAX_TEST_PROBLEMS];
public:
    size_t getProblemsCount() const {
        return problemsCount;
    }

    void setProblemsCount(size_t newProblemsCount) {
        problemsCount = newProblemsCount;
    }

    Problem& getProblemAtIndex(size_t index) {
        return problems[index];
    }

    const Problem& getProblemAtIndexValue(size_t index) const {
        return problems[index];
    }

    void setProblemAtIndex(size_t index, const Problem& newProblem) {
        problems[index] = newProblem;
    }
};

size_t getFileSize(std::ifstream& in) {
    size_t current = in.tellg();
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    in.seekg(current, std::ios::beg);

    return size;
}

Test readTest(const char* filename) {
    std::ifstream in(filename, std::ios::binary | std::ios::in);

    if (!in.is_open()) {
        return {};
    }

    Test test;
    size_t problemsCount = getFileSize(in) / sizeof(Problem);
    test.setProblemsCount(problemsCount);

    for (size_t i = 0; i < problemsCount; i++) {
        in.read((char*)&test.getProblemAtIndex(i), sizeof(Problem));
    }

    return test;

    in.close();
}

void writeTest(const char* filename, const Test& test) {
    std::ofstream out(filename, std::ios::binary | std::ios::out);

    if (!out.is_open()) {
        return;
    }

    for (size_t i = 0; i < test.getProblemsCount(); i++) {
        out.write((const char*)&test.getProblemAtIndexValue(i), sizeof(Problem));
    }

    out.close();
}

int getTestMaxScore(const Test& test) {
    int totalPoints = 0;

    for (size_t i = 0; i < test.getProblemsCount(); i++) {
        totalPoints += test.getProblemAtIndexValue(i).getPoints();
    }

    return totalPoints;
}

void printProblem(const Problem& problem) {
    std::cout << problem.getText();
}

void printTest(const Test& test) {
    for (int i = 0; i < test.getProblemsCount(); i++) {
        printProblem(test.getProblemAtIndexValue(i));
        std::cout << std::endl;
    }
}

void simulateTest(const Test& test) {
    int totalPoints = 0;

    for (int i = 0; i < test.getProblemsCount(); i++) {
        std::cout << "PROBLEM " << i + 1 << ":\n";
        printProblem(test.getProblemAtIndexValue(i));
        std::cout << std::endl;

        char answer;
        std::cin >> answer;
        if (answer == test.getProblemAtIndexValue(i).getAnswer()) {
            totalPoints += test.getProblemAtIndexValue(i).getPoints();
        }

        std::cout << std::endl;
    }

    std::cout << "TOTAL: " << totalPoints << "/" << getTestMaxScore(test);
}

int main()
{
    /*test.setProblemsCount(3);
    test.setProblemAtIndex(0, { 'a', 4, "123", "Da se nameri D." });
    test.setProblemAtIndex(1, { 'b', 14, "1234", "Da se nameri D1." });
    test.setProblemAtIndex(2, { 'c', 24, "12345", "Da se nameri D2." });*/

    Test test = readTest("file.dat");

    simulateTest(test);
}
