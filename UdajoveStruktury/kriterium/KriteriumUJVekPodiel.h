#pragma once
#include "KriteriumUzemnaJednotka.h"
#include"../classes/TypPohlavia.h"

class KriteriumUJVekPodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVekPodiel(int vek, TypPohlavia pohlavie) : pohlavie_(pohlavie), vek_(vek) {}
	double evaluate(UzemnaJednotka* objekt) override;
private:
	TypPohlavia pohlavie_;
	int vek_;
};

inline double KriteriumUJVekPodiel::evaluate(UzemnaJednotka* objekt)
{
	double pocet = 0;
	for (size_t i = 0; i < 101; i++)
	{
		if (objekt->getVekMuzi() != nullptr && objekt->getVekZeny() != nullptr)
		{
			pocet += objekt->getVekMuzi()->at(i);
			pocet += objekt->getVekZeny()->at(i);
		}	
	}
	if (TypPohlavia::MUZ == pohlavie_)
	{
		return 100 * (objekt->getVekMuzi()->at(vek_) / pocet);
	}
	else {
		return 100 * (objekt->getVekZeny()->at(vek_) / pocet);
	}
}