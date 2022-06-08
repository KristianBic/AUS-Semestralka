#pragma once
#include "FilterFi.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJPrislusnosth.h"

class FilterUJPrislusnost : public FilterFi<UzemnaJednotka, bool>
{
public:
	FilterUJPrislusnost(UzemnaJednotka* vyssiCelok) : FilterFi(new KriteriumUJPrislusnost(vyssiCelok), vyssiCelok) {}
};

