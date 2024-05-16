#pragma once
#include "LoggedPlayer.h"

class PremiumPlayer : public LoggedPlayer {
public:
	PremiumPlayer() = default;
	PremiumPlayer(const char* name);
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other) noexcept;
	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;
	~PremiumPlayer();

	bool levelUp() override;

private:
	char* name = nullptr;

	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other) noexcept;
	void free();
};

