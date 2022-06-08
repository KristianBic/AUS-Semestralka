#pragma once
#include "KriteriumUzemnaJednotka.h"
#include"../classes/TypVekovejSkupiny.h"

class KriteriumUJVekovaSkupinaPodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVekovaSkupinaPodiel(TypVekovejSkupiny typVekovejSkupiny) : typVekovejSkupiny_(typVekovejSkupiny) {}
	double evaluate(UzemnaJednotka* objekt) override;
private:
	TypVekovejSkupiny typVekovejSkupiny_;
};

inline double KriteriumUJVekovaSkupinaPodiel::evaluate(UzemnaJednotka* objekt)
{
	double pocetObyvatelovSkupine = 0;
	double celkovyPocetObyvatelov = 0;

	for (size_t i = 0; i < 101; i++)
	{
		celkovyPocetObyvatelov += objekt->getVekMuzi()->at(i);
		celkovyPocetObyvatelov += objekt->getVekZeny()->at(i);
	}

	switch (typVekovejSkupiny_)
	{
	case TypVekovejSkupiny::PREDPRODUKTIVNY: {
		for (size_t i = 0; i <= 14; i++)
		{
			pocetObyvatelovSkupine += objekt->getVekMuzi()->at(i);
			pocetObyvatelovSkupine += objekt->getVekZeny()->at(i);
		}
		return 100 * pocetObyvatelovSkupine / celkovyPocetObyvatelov;
		break;
	}
	case TypVekovejSkupiny::PRODUKTIVNY: {
		for (size_t i = 15; i <= 64; i++)
		{
			pocetObyvatelovSkupine += objekt->getVekMuzi()->at(i);
			pocetObyvatelovSkupine += objekt->getVekZeny()->at(i);
		}
		return 100 * pocetObyvatelovSkupine / celkovyPocetObyvatelov;
		break;
	}
	case TypVekovejSkupiny::POPRODUKTIVNY: {
		for (size_t i = 65; i <= 100; i++)
		{
			pocetObyvatelovSkupine += objekt->getVekMuzi()->at(i);
			pocetObyvatelovSkupine += objekt->getVekZeny()->at(i);
		}
		return 100 * pocetObyvatelovSkupine / celkovyPocetObyvatelov;
		break;
	}
	default:
		break;
	}
}