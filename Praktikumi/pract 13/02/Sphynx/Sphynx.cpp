#include "Sphynx.h"

bool Sphynx::fight(const Monster* other) const {
	return other->fightSphynx(this);
}

bool Sphynx::fightMinotaur(const Minotaur* other) const {
	return false;
}

bool Sphynx::fightCentaur(const Centaur* other) const {
	return true;
}

bool Sphynx::fightSphynx(const Sphynx* other) const {
	return false;
}

void Sphynx::printMonster() const {
	std::cout << "Sphynx ";
}
