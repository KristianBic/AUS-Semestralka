#pragma once
#include "FilterFII.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVekPodiel.h"
#include "../classes/TypPohlavia.h"

class FilterUJVekPodiel : public FilterFII<UzemnaJednotka, double>
{
public:
	FilterUJVekPodiel(double minValue, double maxValue, TypPohlavia typPohlavia, int vek) :
		FilterFII(new KriteriumUJVekPodiel(vek, typPohlavia), minValue, maxValue) {}
};

