#pragma once
#include "Waffle.h"

class WaffleShop {
private: 
	size_t maxWaffles = 0;
	size_t wafflesCount = 0;
	double currentProfit = 0;
	double currentLoss = 0;
	Waffle* waffles = nullptr;

	void clearWaffle(size_t index);
	void removeWaffle(size_t index);

public:
	WaffleShop();

	WaffleShop(size_t maxWaffles, double currentProfit, double currentLoss, size_t wafflesCount, const Waffle* waffles);

	~WaffleShop();

	double getCurrentProfit() const;
	double getCurrentLoss() const;
	size_t getWafflesCount() const;
	size_t getMaxWaffles() const;

	void setWaffles(size_t wafflesCount, const Waffle* waffles);

	void sellWaffle(const char* brand);
	void buyWaffles(size_t count, const Waffle& waffle);
	size_t getWafflesFromBrandCount(const char* brand);

	void print();
};
