#include "Minotaur.h"

bool Minotaur::fight(const Monster* other) const {
	return other->fightMinotaur(this);
}

bool Minotaur::fightMinotaur(const Minotaur* other) const {
	return false;
}

bool Minotaur::fightCentaur(const Centaur* other) const {
	return false;
}

bool Minotaur::fightSphynx(const Sphynx* other) const {
	return true;
}

void Minotaur::printMonster() const {
	std::cout << "Minotaur ";
}
