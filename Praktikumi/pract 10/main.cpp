#include <iostream>
#include "CarPart.h"
#include "FuelTank.h"

int main()
{
    try {
        FuelTank tank(20.0);
        tank.use(21.0);
    }
    catch (const insufficient_fuel_error& e) {
        std::cout << e.what();
    }
}
