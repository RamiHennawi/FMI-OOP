#include <iostream>
#include <fstream>
#include <sstream>

namespace GlobalConstants {
    constexpr size_t PHONE_NUMBER_SIZE = 10;
    constexpr size_t MAX_ADDITIONAL_ITEMS = 10;
    constexpr size_t MAX_CUSTOMER_NAME = 20;
    constexpr size_t MAX_ORDER_SIZE = 20;
    constexpr size_t MAX_ADDRESS_SIZE = 40;
    
    constexpr size_t MAX_ORDERS = 40;

    constexpr char OUTPUT_FILE[] = "output.dat";
    constexpr char INPUT_FILE[] = "input.dat";
}

enum class PizzaType {
    Margherita,
    Pepperoni,
    Hawaiian,
    Supreme,
    MeatLover,
    Vegetarian,
    BBQChicken,
    BuffaloChicken
};

enum class AdditionalItems {
    Water,
    CocaCola,
    Pepsi,
    Sauce
};

struct PizzaDelivery {
    size_t additionsCount = 0;
    size_t pizzasCount = 0;
    double price = 0;
    char phone[GlobalConstants::PHONE_NUMBER_SIZE + 1];
    AdditionalItems additions[GlobalConstants::MAX_ADDITIONAL_ITEMS];
    PizzaType pizzas[GlobalConstants::MAX_ORDER_SIZE];
    char customerName[GlobalConstants::MAX_CUSTOMER_NAME + 1];
    char address[GlobalConstants::MAX_ADDRESS_SIZE + 1];
};

size_t getFileSize(std::ifstream& in) {
    size_t currentPos = in.tellg();
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();

    in.seekg(currentPos);
    return size;
}

void readOrdersFromFile(const char* file, PizzaDelivery*& orders, size_t& ordersCount) {
    std::ifstream in(file, std::ios::binary);

    if (!in.is_open()) {
        return;
    }

    size_t fileSize = getFileSize(in);
    ordersCount = fileSize / sizeof(PizzaDelivery);

    orders = new PizzaDelivery[ordersCount];
    size_t currentOrder = 0;

    in.read((char*)orders, fileSize);

    in.close();
}

void writeOrdersInFile(const char* file, const PizzaDelivery* orders, const size_t ordersCount) {
    std::ofstream out(file, std::ios::binary);

    if (!out.is_open()) {
        return;
    }

    out.write((const char*)orders, ordersCount * sizeof(PizzaDelivery));

    out.close();
}

void initDelivery(PizzaDelivery& order, const double price, const char* phone, const size_t additionsCount, const AdditionalItems* additions, 
    const size_t pizzasCount, const PizzaType* pizzas, const char* customerName, const char* address) {

    order.price = price;
    strcpy_s(order.phone, phone);

    order.additionsCount = additionsCount;
    for (int i = 0; i < additionsCount; i++) {
        order.additions[i] = additions[i];
    }

    order.pizzasCount = pizzasCount;
    for (int i = 0; i < pizzasCount; i++) {
        order.pizzas[i] = pizzas[i];
    }

    strcpy_s(order.customerName, customerName);
    strcpy_s(order.address, address);
}

const char* getPizzaType(const PizzaType type) {
    switch (type) {
    case PizzaType::Margherita: return "Beauty";
    case PizzaType::Pepperoni: return "Pepperoni";
    case PizzaType::Hawaiian: return "Hawaiian";
    case PizzaType::Supreme: return "Supreme";
    case PizzaType::MeatLover: return "MeatLover";
    case PizzaType::Vegetarian: return "Vegetarian";
    case PizzaType::BBQChicken: return "BBQChicken";
    case PizzaType::BuffaloChicken: return "BuffaloChicken";
    default: return "Unknown";
    }
}

const char* getAdditionalItem(const AdditionalItems item) {
    switch (item) {
    case AdditionalItems::Water: return "Water";
    case AdditionalItems::CocaCola: return "CocaCola";
    case AdditionalItems::Pepsi: return "Pepsi";
    case AdditionalItems::Sauce: return "Sauce";
    default: return "Unknown";
    }
}

void printDelivery(const PizzaDelivery& order) {
    std::cout << order.customerName << ", " << order.phone << ", " << order.address << std::endl;
    for (int i = 0; i < order.pizzasCount; i++) {
        std::cout << getPizzaType(order.pizzas[i]);
        if (i != order.pizzasCount - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < order.additionsCount; i++) {
        std::cout << getAdditionalItem(order.additions[i]);
        if (i != order.additionsCount - 1) {
            std::cout << ", ";
        }
    }
    if (order.additionsCount == 0) {
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << order.price << std::endl << std::endl;
}

void printDeliveries(const PizzaDelivery* orders, const size_t ordersCount) {
    for (int i = 0; i < ordersCount; i++) {
        printDelivery(orders[i]);
    }
}

void swapOrders(PizzaDelivery& order1, PizzaDelivery& order2) {
    PizzaDelivery temp = order1;
    order1 = order2;
    order2 = temp;
}

void sortByAddress(PizzaDelivery* orders, const size_t ordersCount) {
    for (size_t i = 0; i < ordersCount - 1; i++) {
        for (size_t j = 0; j < ordersCount - i - 1; j++) {
            if (strcmp(orders[j].address, orders[j + 1].address) > 0) {
                swapOrders(orders[j], orders[j + 1]);
            }
        }
    }
}

int main()
{
    PizzaDelivery* orders = new PizzaDelivery[3];

    AdditionalItems additions1[] = { AdditionalItems::Water, AdditionalItems::Sauce };
    PizzaType pizzas1[] = { PizzaType::Pepperoni, PizzaType::Vegetarian };

    initDelivery(orders[0], 200.33, "0899332211", 2, additions1, 2, pizzas1, "Ivan Ivanov", "BLulin");

    AdditionalItems additions2[] = { AdditionalItems::Water };
    PizzaType pizzas2[] = { PizzaType::Hawaiian, PizzaType::BBQChicken, PizzaType::BuffaloChicken };

    initDelivery(orders[1], 40.32, "0890228833", 1, additions2, 3, pizzas2, "Az azov", "CMladost");

    PizzaType pizzas3[] = { PizzaType::Margherita, PizzaType::MeatLover };

    initDelivery(orders[2], 20, "0881227766", 0, nullptr, 2, pizzas3, "Alo balo", "ALozence");

    size_t ordersCount;
    PizzaDelivery* orders2;

    readOrdersFromFile(GlobalConstants::INPUT_FILE, orders2, ordersCount);

    sortByAddress(orders, 3);
    printDeliveries(orders, 3);

    delete[] orders;
}
