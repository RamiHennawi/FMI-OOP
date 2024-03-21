#include <iostream>
#include <fstream>
#pragma warning(disable: 4996);

namespace GlobalConstants {
    constexpr size_t MAX_TITLE_SIZE = 64;
    constexpr size_t MAX_GAMES = 100;
}

class Game {
    char title[GlobalConstants::MAX_TITLE_SIZE];
    double price;
    bool isAvailable;
public: 
    Game() {
        strcpy(title, "Unknown");
        price = 0;
        isAvailable = false;
    }

    Game(const char* title, double price, bool isAvailable) {
        strcpy(this->title, title);
        this->price = price;
        this->isAvailable = isAvailable;
    }

    const char* getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    double getAvailability() const {
        return isAvailable;
    }

    void setTitle(const char* newTitle) {
        if (newTitle != nullptr && strlen(newTitle) < GlobalConstants::MAX_TITLE_SIZE) {
            strcpy(title, newTitle);
        }
    }

    void setPrice(double newPrice) {
        if (price > 0) {
            this->price = newPrice;
        }
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

    bool isFree() const {
        return price == 0;
    }

    void print() const {
        std::cout << title << ", " << price << ", " << (isAvailable ? "available" : "not available");
    }

    void clearGame() {
        strcpy(title, "Unknown");
        price = 0;
        isAvailable = false;
    }
};

class GamePlatform {
    size_t gamesCount = 0;
    Game games[GlobalConstants::MAX_GAMES];
public:
    void setGamesCount(size_t count) {
        gamesCount = count;
    }

    void addGame(const Game& game) {
        if (gamesCount >= GlobalConstants::MAX_GAMES) {
            return;
        }
        else {
            games[gamesCount++] = game;
        }
    }

    void printGameAtIndex(size_t index) {
        games[index].print();
        std::cout << std::endl;
    }

    void printAllGames() {
        for (size_t i = 0; i < gamesCount; i++) {
            games[i].print();
            std::cout << std::endl;
        }
    }

    void printCheapestGame() {
        size_t wantedIndex = 0;

        for (int i = 1; i < gamesCount; i++) {
            if (games[i].getPrice() < games[wantedIndex].getPrice()) {
                wantedIndex = i;
            }
        }

        games[wantedIndex].print();
        std::cout << std::endl;
    }

    void printMostExpensiveGame() {
        size_t wantedIndex = 0;

        for (int i = 1; i < gamesCount; i++) {
            if (games[i].getPrice() > games[wantedIndex].getPrice()) {
                wantedIndex = i;
            }
        }

        games[wantedIndex].print();
        std::cout << std::endl;
    }

    void printFreeGames() {
        for (int i = 0; i < gamesCount; i++) {
            if (games[i].isFree()) {
                games[i].print();
                std::cout << std::endl;
            }
        }
    }

    void removeGame(const char* title) {
        for (int i = 0; i < gamesCount; i++) {
            if (strcmp(title, games[i].getTitle()) == 0) {
                for (int j = i; j < gamesCount - 1; j++) {
                    games[j] = games[j + 1];
                }

                games[gamesCount].clearGame();

                gamesCount--;
                break;
            }
        }
    }
};

int main()
{
    Game game1("Title1", 10.0, true);
    Game game2("Title2", 20.0, false);
    Game game3("Title3", 0.0, true);

    GamePlatform platform;

    platform.addGame(game1);
    platform.addGame(game2);
    platform.addGame(game3);

    platform.printGameAtIndex(1);
    platform.printCheapestGame();
    platform.printMostExpensiveGame();
    platform.printFreeGames();

    platform.printAllGames();
    platform.removeGame("Title1");
    platform.printAllGames();
}
