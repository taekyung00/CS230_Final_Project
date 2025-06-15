#pragma once
#include <random>
#include <vector>

#include "../Engine/Engine.h"
#include "../Engine/Component.h"

class Random : public CS230::Component {
public:
	Random() :gen(rd()){}

	int PickRandomIndex(int amount, bool same_probability, const std::vector<double>& probability_array = {});

private:
	std::random_device rd;
	std::mt19937 gen;
};

