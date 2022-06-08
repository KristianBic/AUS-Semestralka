#pragma once
#include "KriteriumUzemnaJednotka.h"

class KriteriumUJNadradena : public KriteriumUzemnaJednotka<UzemnaJednotka*>
{
public:
	UzemnaJednotka* evaluate(UzemnaJednotka* objekt) override { return objekt->getVyssiaUzemnaJednotka(); };
};

