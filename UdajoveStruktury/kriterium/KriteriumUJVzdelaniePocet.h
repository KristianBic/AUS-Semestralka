#pragma once
#include "KriteriumUzemnaJednotka.h"
#include"../classes/TypVzdelavania.h"

class KriteriumUJVzdelaniePocet : public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVzdelaniePocet(TypVzdelavania typVzdelavania) : typVzdelavania_(typVzdelavania) {}
	int evaluate(UzemnaJednotka* objekt) override;
private:
	TypVzdelavania typVzdelavania_;
};

inline int KriteriumUJVzdelaniePocet::evaluate(UzemnaJednotka* objekt)
{
	if (objekt->getVzdelavanie() != nullptr)
	{
		switch (typVzdelavania_)
		{
		case TypVzdelavania::NEZISTENE:
			return objekt->getVzdelavanie()->getNezistene();
		case TypVzdelavania::BEZ_VZDELAVANIA:
			return objekt->getVzdelavanie()->getBezVzdelavania();
		case TypVzdelavania::VYSOKOSKOLSKE:
			return objekt->getVzdelavanie()->getVysokoskolske();
		case TypVzdelavania::VYSSIE:
			return objekt->getVzdelavanie()->getVyssie();
		case TypVzdelavania::STREDNE:
			return objekt->getVzdelavanie()->getStredne();
		case TypVzdelavania::UCNOVSKE:
			return objekt->getVzdelavanie()->getUcnovske();
		case TypVzdelavania::ZAKLADNE:
			return objekt->getVzdelavanie()->getZakladne();
		case TypVzdelavania::BEZ_UKONCENIA:
			return objekt->getVzdelavanie()->getBezUkoncenia();
		default:
			break;
		}
	}
	return 0;
}