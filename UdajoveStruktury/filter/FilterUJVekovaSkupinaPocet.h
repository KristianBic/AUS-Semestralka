#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVekovaSkupinaPocet.h"
#include "../classes/TypVzdelavania.h"

class FilterUJVekovaSkupinaPocet : public FilterFII<UzemnaJednotka, int>
{
public:
	FilterUJVekovaSkupinaPocet(int minValue, int maxValue, TypVekovejSkupiny typVekovejSkupiny) :
		FilterFII(new KriteriumUJVekovaSkupinaPocet(typVekovejSkupiny), minValue, maxValue) {}
};
