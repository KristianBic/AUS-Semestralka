#pragma once
#include "KriteriumUzemnaJednotka.h"
#include"../classes/TypPohlavia.h"

class KriteriumUJVekPocet : public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVekPocet(int vek, TypPohlavia pohlavie) : pohlavie_(pohlavie), vek_(vek) {}
	int evaluate(UzemnaJednotka* objekt) override;
private:
	TypPohlavia pohlavie_;
	int vek_;
};

inline int KriteriumUJVekPocet::evaluate(UzemnaJednotka* objekt)
{
	if (TypPohlavia::MUZ == pohlavie_)
	{
		return objekt->getVekMuzi()->at(vek_);
	}
	else {
		return objekt->getVekZeny()->at(vek_);
	}
}
