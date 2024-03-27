#include <iostream>
#include "WaffleShop.h";

int main()
{
    Waffle waffle1(0.79, 0.49, 60, "Borovets");
    Waffle waffle2(1.09, 0.69, 100, "Chudo");
    Waffle waffle3(0.69, 0.49, 50, "Mura");

    Waffle waffles[] = { waffle1, waffle2, waffle3, waffle3, waffle3, waffle1, waffle2, waffle2 };

    WaffleShop shop(20, 0.0, 0.0, 8, waffles);

    shop.print();
    shop.sellWaffle("Chudo");

    shop.print();
    shop.buyWaffles(2, waffle2);

    shop.print();
    std::cout << shop.getWafflesFromBrandCount("Chudo") << std::endl;
}
