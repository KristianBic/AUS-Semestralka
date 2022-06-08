#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVekPocet.h"
#include "../classes/TypPohlavia.h"

class FilterUJVekPocet : public FilterFII<UzemnaJednotka, int>
{
public:
	FilterUJVekPocet(int minValue, int maxValue, TypPohlavia typPohlavia, int vek) :
		FilterFII(new KriteriumUJVekPocet(vek, typPohlavia), minValue, maxValue) {}
};
