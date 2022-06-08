#pragma once
#include "FilterFi.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJTyp.h"

class FilterUJTyp : public FilterFi<UzemnaJednotka, TypUzemnejJednotky>
{
public:
	FilterUJTyp(TypUzemnejJednotky typ) : FilterFi(new KriteriumUJTyp(), typ) {}
};

