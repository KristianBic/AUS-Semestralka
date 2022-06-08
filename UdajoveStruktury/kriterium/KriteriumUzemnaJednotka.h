#pragma once

#include "../classes/UzemnaJednotka.h"
#include "Kriterium.h"

template<typename R>
class KriteriumUzemnaJednotka : public Kriterium<UzemnaJednotka, R>
{
public:
	virtual R evaluate(UzemnaJednotka* objekt) override = 0;
};