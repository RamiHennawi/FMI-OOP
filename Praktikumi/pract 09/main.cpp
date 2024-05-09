#include <iostream>
#include "Foodpanda.h"

int main()
{
    try {
        Restaurant restaurant("GyroLand");
        restaurant.addProduct("gyros");

        Foodpanda foodpanda;
        foodpanda.addRestaurant(restaurant);
       
        Order order("GyroLand");
        order.addProduct("salata");

        foodpanda.addOrder(order);
    }
    catch (const std::logic_error& e) {
        std::cout << e.what();
    }

}

