#pragma once

constexpr size_t MAX_BRAND_SIZE = 20;

class Waffle {
private:
	double priceClient = 0;
	double priceWholesale = 0;
	double grammage = 0;
	char brand[MAX_BRAND_SIZE] = "Unknown";

public:
	Waffle();

	Waffle(double priceClient, double priceWholesale, double grammage, const char* brand);

	double getPriceClient() const;
	double getPriceWholesale() const;
	double getGrammage() const;
	const char* getBrand() const;

	void setPriceClient(double priceClient);
	void setPriceWholesale(double priceWholesale);
	void setGrammage(double grammage);
	void setBrand(const char* brand);

	void print();
};