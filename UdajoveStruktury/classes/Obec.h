#pragma once
#include "UzemnaJednotka.h"

class Obec : public UzemnaJednotka
{
private:
	Vzdelanie* vzdelavanie_;
	Array<int>* vekMuzi_;
	Array<int>* vekZeny_;
public:
	Obec(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka
		,Vzdelanie* vzdelavanie, Array<int>* vekMuzi, Array<int>* vekZeny);
	~Obec();
	Vzdelanie* getVzdelavanie() override { return vzdelavanie_; }
	Array<int>* getVekMuzi() override { return vekMuzi_; }
	Array<int>* getVekZeny() override { return vekZeny_; }
	bool setVekMuzi() override { return true; };
	bool setVekZeny() override { return true; };
    bool setVzdelanie() override { return true; };
};

inline Obec::Obec(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka, Vzdelanie* vzdelavanie, Array<int>* vekMuzi, Array<int>* vekZeny) :
	vzdelavanie_(vzdelavanie), vekMuzi_(new Array<int>(101)), vekZeny_(new Array<int>(101)),
	UzemnaJednotka(code, officialTitle, mediumTitle, shortTitle, note, TypUzemnejJednotky::OBEC, vyssiaUzemnaJednotka) 
{
	if (vekMuzi != nullptr && vekZeny != nullptr)
	{
		vekMuzi_->assign(*vekMuzi);
		vekZeny_->assign(*vekZeny);
	}
	
}

inline Obec::~Obec()
{
	delete vekMuzi_;
	vekMuzi_ = nullptr;
	delete vekZeny_;
	vekZeny_ = nullptr;
	//delete vzdelavanie_;
	vzdelavanie_ = nullptr;
}

