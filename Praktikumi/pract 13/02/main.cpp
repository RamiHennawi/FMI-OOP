#include <iostream>
#include <time.h>
#include "Monster.h"
#include "Minotaur.h"
#include "Centaur.h"
#include "Sphynx.h"

int main() {
	srand(time(NULL));

	Monster** monsters = new Monster*[15];

	for (int i = 0; i < 15; i++) {
		int n = std::rand();

		if (n % 3 == 0) {
			monsters[i] = new Minotaur();
		}
		else if (n % 3 == 1) {
			monsters[i] = new Centaur();
		}
		else if (n % 3 == 2) {
			monsters[i] = new Sphynx();
		}
	}

	int n;
	std::cin >> n;

	size_t winsCount = 0;
	for (int i = 0; i < 15; i++) {
		monsters[i]->printMonster();

		if (monsters[n]->fight(monsters[i])) {
			winsCount++;
		}
	}

	std::cout << "\nYour monster will win " << winsCount << " times.";

	for (int i = 0; i < 15; i++) {
		delete monsters[i];
	}

	delete[] monsters;
}
