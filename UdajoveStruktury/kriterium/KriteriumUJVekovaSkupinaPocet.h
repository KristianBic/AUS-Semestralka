#pragma once
#include "KriteriumUzemnaJednotka.h"
#include"../classes/TypVekovejSkupiny.h"

class KriteriumUJVekovaSkupinaPocet : public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVekovaSkupinaPocet(TypVekovejSkupiny typVekovejSkupiny) : typVekovejSkupiny_(typVekovejSkupiny) {}
	int evaluate(UzemnaJednotka* objekt) override;
private:
	TypVekovejSkupiny typVekovejSkupiny_;
};

inline int KriteriumUJVekovaSkupinaPocet::evaluate(UzemnaJednotka* objekt)
{
	int pocetObyvatelov = 0;
	switch (typVekovejSkupiny_)
	{
	case TypVekovejSkupiny::PREDPRODUKTIVNY: {
		for (size_t i = 0; i <= 14; i++)
		{
			pocetObyvatelov += objekt->getVekMuzi()->at(i);
			pocetObyvatelov += objekt->getVekZeny()->at(i);
		}
		return pocetObyvatelov;
		break;
	}
	case TypVekovejSkupiny::PRODUKTIVNY: {
		for (size_t i = 15; i <= 64; i++)
		{
			pocetObyvatelov += objekt->getVekMuzi()->at(i);
			pocetObyvatelov += objekt->getVekZeny()->at(i);
		}
		return pocetObyvatelov;
		break;
	}
	case TypVekovejSkupiny::POPRODUKTIVNY: {
		for (size_t i = 65; i <= 100; i++)
		{
			pocetObyvatelov += objekt->getVekMuzi()->at(i);
			pocetObyvatelov += objekt->getVekZeny()->at(i);
		}
		return pocetObyvatelov;
		break;
	}
	default:
		break;
	}
}
