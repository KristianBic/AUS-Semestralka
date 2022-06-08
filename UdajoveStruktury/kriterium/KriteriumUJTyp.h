#pragma once
#include "KriteriumUzemnaJednotka.h"

class KriteriumUJTyp : public KriteriumUzemnaJednotka<TypUzemnejJednotky>
{
public:
	TypUzemnejJednotky evaluate(UzemnaJednotka* objekt) override { return objekt->getTypUzemnehoCelku(); };
};

