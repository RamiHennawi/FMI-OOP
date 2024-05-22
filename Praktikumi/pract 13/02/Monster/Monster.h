#pragma once
#include <iostream>

class Minotaur;
class Centaur;
class Sphynx;

class Monster {
public:
	virtual bool fight(const Monster* other) const = 0;
	virtual bool fightMinotaur(const Minotaur* other) const = 0;
	virtual bool fightCentaur(const Centaur* other) const = 0;
	virtual bool fightSphynx(const Sphynx* other) const = 0;

	virtual void printMonster() const = 0;
};
