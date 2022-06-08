#pragma once
#include "KriteriumUzemnaJednotka.h"
#include "../classes/TypVzdelavania.h"

class KriteriumUJVzdelaniePodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVzdelaniePodiel(TypVzdelavania typVzdelavania) : typVzdelavania_(typVzdelavania) {}
	double evaluate(UzemnaJednotka* objekt) override;
private:
	TypVzdelavania typVzdelavania_;
};

inline double KriteriumUJVzdelaniePodiel::evaluate(UzemnaJednotka* objekt)
{
	double pocet = 0;
	for (size_t i = 0; i < 101; i++)
	{
		pocet += objekt->getVekMuzi()->at(i);
		pocet += objekt->getVekZeny()->at(i);
	}

	switch (typVzdelavania_)
	{
	case TypVzdelavania::NEZISTENE:
		return 100 * (objekt->getVzdelavanie()->getNezistene() / pocet);
	case TypVzdelavania::BEZ_VZDELAVANIA:
		return 100 * (objekt->getVzdelavanie()->getBezVzdelavania() / pocet);
	case TypVzdelavania::VYSOKOSKOLSKE:
		return 100 * (objekt->getVzdelavanie()->getVysokoskolske() / pocet);
	case TypVzdelavania::VYSSIE:
		return 100 * (objekt->getVzdelavanie()->getVyssie() / pocet);
	case TypVzdelavania::STREDNE:
		return 100 * (objekt->getVzdelavanie()->getStredne() / pocet);
	case TypVzdelavania::UCNOVSKE:
		return 100 * (objekt->getVzdelavanie()->getUcnovske() / pocet);
	case TypVzdelavania::ZAKLADNE:
		return 100 * (objekt->getVzdelavanie()->getZakladne() / pocet);
	case TypVzdelavania::BEZ_UKONCENIA:
		return 100 * (objekt->getVzdelavanie()->getBezUkoncenia() / pocet);
	default:
		break;
	}
}