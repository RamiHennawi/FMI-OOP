#include <iostream>
#include "Vector.h"

int main() {
    try {
        Vector vector(8);

        vector.push_back(6);
        vector.push_back(3);
        vector.push_back(4);
        vector.pop_back();
        vector.print();
    }
    catch (const std::exception& e) {
        std::cout << e.what();
    }
}
