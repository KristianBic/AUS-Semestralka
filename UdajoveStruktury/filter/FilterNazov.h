#pragma once
#include "FilterFi.h"
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJNazov.h"

class FilterNazov : public FilterFi<UzemnaJednotka, std::string>
{
public:
	FilterNazov(std::string nazov) : FilterFi(new KriteriumUJNazov(), nazov) {}
};

