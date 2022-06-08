#pragma once
#include "KriteriumUzemnaJednotka.h"

class KriteriumUJNazov : public KriteriumUzemnaJednotka<std::string>
{
public:
	std::string evaluate(UzemnaJednotka* objekt) override { return objekt->getOfficialTitle(); };
};