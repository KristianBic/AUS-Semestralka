#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVzdelaniePocet.h"
#include "../classes/TypVzdelavania.h"

class FilterUJVzdelaniePocet : public FilterFII<UzemnaJednotka, int>
{
public:
	FilterUJVzdelaniePocet(int minValue, int maxValue, TypVzdelavania typVzdelavania) : 
		FilterFII(new KriteriumUJVzdelaniePocet(typVzdelavania), minValue, maxValue) {}
};
