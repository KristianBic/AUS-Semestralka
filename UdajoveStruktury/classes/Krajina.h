#pragma once
#include "UzemnaJednotka.h"

class Krajina : public UzemnaJednotka
{
public:
	Krajina(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka);
	Vzdelanie* getVzdelavanie() override { return 0; };
	Array<int>* getVekMuzi() override { return 0; };
	Array<int>* getVekZeny() override { return 0; };
	bool setVekMuzi() override { return true; };
	bool setVekZeny() override { return true; };
	bool setVzdelanie() override { return true; };
};

inline Krajina::Krajina(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka) :
	UzemnaJednotka(code, officialTitle, mediumTitle, shortTitle, note, TypUzemnejJednotky::KRAJINA, vyssiaUzemnaJednotka) {}



