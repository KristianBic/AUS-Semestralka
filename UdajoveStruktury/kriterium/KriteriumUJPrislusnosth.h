#pragma once
#include "KriteriumUzemnaJednotka.h"

class KriteriumUJPrislusnost : public KriteriumUzemnaJednotka<bool>
{
public:
	KriteriumUJPrislusnost(UzemnaJednotka* vyssiCelok) : vyssiCelok_(vyssiCelok) {}
	bool evaluate(UzemnaJednotka* objekt) override { return objekt->getVyssiaUzemnaJednotka() == vyssiCelok_; };
private:
	UzemnaJednotka* vyssiCelok_;
};

