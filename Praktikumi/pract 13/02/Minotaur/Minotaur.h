#pragma once
#include "Monster.h"

class Minotaur : public Monster {
public:
	virtual bool fight(const Monster* other) const override;
	virtual bool fightMinotaur(const Minotaur* other) const override;
	virtual bool fightCentaur(const Centaur* other) const override;
	virtual bool fightSphynx(const Sphynx* other) const override;

	virtual void printMonster() const override;
};
