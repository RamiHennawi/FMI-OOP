#include <iostream>
#include <fstream>
#include <sstream>

namespace GlobalConstants {
    constexpr size_t MAX_FIRM_SIZE = 25;
}

constexpr char inputFile[] = "input.dat";
constexpr char outputFile[] = "output.dat";

struct JobRequest {
    size_t colleagues = 0;
    size_t daysOff = 0;
    long long profit = 0;
    char firm[GlobalConstants::MAX_FIRM_SIZE] = {};
};

void printJobRequest(const JobRequest& request) {
    std::cout << request.firm << ", " << request.colleagues << ", " << request.daysOff << ", " << request.profit << std::endl;
}

void printJobRequestInFile(const JobRequest& request, std::ofstream& out) {
    out.write((const char*)&request, sizeof(request));
}

void inputRequestToFile(std::ofstream& out) { // da se razdeli - purvo samo input, posle output => ABSTRAKCIQ!!!
    JobRequest request;

    std::cin.ignore();
    std::cin.getline(request.firm, GlobalConstants::MAX_FIRM_SIZE);
    std::cin >> request.colleagues;
    std::cin >> request.daysOff;
    std::cin >> request.profit;

    out.write((const char*)&request, sizeof(request));
}

void inputManyRequestsToFile(const size_t numberOfOffers, std::ofstream& out) {
    for (int i = 0; i < numberOfOffers; i++) {
        inputRequestToFile(out);
    }
}

void filterOffers(const char* filePath, long long minSalary) {
    std::ifstream in(filePath);

    if (!in.is_open()) {
        std::cout << "Error opening file!";
        return;
    }

    while (!in.eof()) {
        JobRequest request;

        in.read((char*)&request, sizeof(request));

        if (request.profit > minSalary) {
            printJobRequest(request);
        }
    }

    in.close();
}

bool existOffer(const char* filePath, const char* name) {
    std::ifstream in(filePath);

    if (!in.is_open()) {
        std::cout << "Error opening file!";
        return false;
    }

    while (!in.eof()) {
        JobRequest request;

        in.read((char*)&request, sizeof(request));

        if (strcmp(request.firm, name) == 0) {
            in.close();
            return true;
        }
    }

    in.close();
    return false;
}

void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "Error opening file!";
        return;
    }

    while (!in.eof()) {
        JobRequest request;

        in.read((char*)&request, sizeof(request));

        if (maxCoworkers >= request.colleagues && minVacancyDays <= request.daysOff && minSalary <= request.profit) {
            std::ofstream out(outputFile, std::ios::binary | std::ios::app);

            if (!in.is_open()) {
                std::cout << "Error opening file!";
                in.close();
                return;
            }

            printJobRequestInFile(request, out);

            out.close();
        }
    }

    in.close();
}

int main()
{
    filterOffers("input.dat", 1);
    perfectOffer("input.dat", 4, 5, 6);
}
