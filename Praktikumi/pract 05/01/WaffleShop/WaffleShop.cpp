#include "WaffleShop.h"

#include <iostream>

WaffleShop::WaffleShop() {
	maxWaffles = 0;
	currentProfit = 0;
	currentLoss = 0;
	waffles = nullptr;
	wafflesCount = 0;
}

WaffleShop::WaffleShop(size_t maxWaffles, double currentProfit, double currentLoss, size_t wafflesCount, const Waffle* waffles) :
	maxWaffles(maxWaffles), currentProfit(currentProfit), currentLoss(currentLoss) {

	setWaffles(wafflesCount, waffles);
}

WaffleShop::~WaffleShop() {
	delete[] waffles;
}

double WaffleShop::getCurrentProfit() const {
	return currentProfit;
}

double WaffleShop::getCurrentLoss() const {
	return currentLoss;
}

size_t WaffleShop::getWafflesCount() const {
	return wafflesCount;
}

size_t WaffleShop::getMaxWaffles() const {
	return maxWaffles;
}

void WaffleShop::setWaffles(size_t wafflesCount, const Waffle* waffles) {
	if (wafflesCount > maxWaffles) {
		return;
	}

	if (waffles != nullptr) {
		this->wafflesCount = wafflesCount;

		this->waffles = new Waffle[maxWaffles];
		for (int i = 0; i < wafflesCount; i++) {
			this->waffles[i] = waffles[i];
		}
	}
}

void WaffleShop::clearWaffle(size_t index) {
	waffles[index].setPriceClient(0);
	waffles[index].setPriceWholesale(0);
	waffles[index].setGrammage(0);
	waffles[index].setBrand("Unknown");
}

void WaffleShop::removeWaffle(size_t index) {
	for (int i = index; i < wafflesCount; i++) {
		waffles[i] = waffles[i + 1];
	}

	clearWaffle(wafflesCount);
	wafflesCount--;
}

void WaffleShop::sellWaffle(const char* waffleBrand) {
	for (int i = 0; i < wafflesCount; i++) {
		if (strcmp(waffles[i].getBrand(), waffleBrand) == 0) {
			removeWaffle(i);

			currentProfit += waffles[i].getPriceClient();
			return;
		}
	}

	std::cout << "No waffles of this brand.\n";
}

void WaffleShop::buyWaffles(size_t count, const Waffle& waffle) {
	if ((wafflesCount + count) > maxWaffles) {
		return;
	}
	
	for (int i = wafflesCount; i < wafflesCount + count; i++) {
		waffles[i] = waffle;
	}

	wafflesCount += count;
	currentLoss += count * waffle.getPriceWholesale();
}

size_t WaffleShop::getWafflesFromBrandCount(const char* brand) {
	size_t count = 0; 

	for (int i = 0; i < wafflesCount; i++) {
		if (strcmp(waffles[i].getBrand(), brand) == 0) {
			count++;
		}
	}

	return count;
}

void WaffleShop::print() {
	for (int i = 0; i < wafflesCount; i++) {
		waffles[i].print();
	}
	
	std::cout << std::endl;
}
