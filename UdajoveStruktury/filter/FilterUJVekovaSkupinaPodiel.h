#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVekovaSkupinaPodiel.h"
#include "../classes/TypVzdelavania.h"

class FilterUJVekovaSkupinaPodiel : public FilterFII<UzemnaJednotka, double>
{
public:
	FilterUJVekovaSkupinaPodiel(double minValue, double maxValue, TypVekovejSkupiny typVekovejSkupiny) :
		FilterFII(new KriteriumUJVekovaSkupinaPodiel(typVekovejSkupiny), minValue, maxValue) {}
};

