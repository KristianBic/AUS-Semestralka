#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVzdelaniePodiel.h"
#include "../classes/TypVzdelavania.h"

class FilterUJVzdelaniePodiel : public FilterFII<UzemnaJednotka, double>
{
public:
	FilterUJVzdelaniePodiel(double minValue, double maxValue, TypVzdelavania typVzdelavania) :
		FilterFII(new KriteriumUJVzdelaniePodiel(typVzdelavania), minValue, maxValue) {}
};
