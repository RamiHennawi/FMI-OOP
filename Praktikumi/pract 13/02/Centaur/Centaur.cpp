#include "Centaur.h"

bool Centaur::fight(const Monster* other) const {
	return other->fightCentaur(this);
}

bool Centaur::fightMinotaur(const Minotaur* other) const {
	return true;
}

bool Centaur::fightCentaur(const Centaur* other) const {
	return false;
}

bool Centaur::fightSphynx(const Sphynx* other) const {
	return false;
}


void Centaur::printMonster() const {
	std::cout << "Centaur ";
}
