#pragma once
#include "UzemnaJednotka.h"

class Okres : public UzemnaJednotka
{
private:
	Array<int>* vekMuzi_ = new Array<int>(101);
	Array<int>* vekZeny_ = new Array<int>(101);
	Vzdelanie* vzdelavanie_ = new Vzdelanie(0, 0, 0, 0, 0, 0, 0, 0);
public:
	Okres(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka);
	~Okres();
	Vzdelanie* getVzdelavanie() override;
	Array<int>* getVekMuzi() override;
	Array<int>* getVekZeny() override;
	bool setVekMuzi() override;
	bool setVekZeny() override;
	bool setVzdelanie() override;
};

inline Okres::Okres(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka) :
	UzemnaJednotka(code, officialTitle, mediumTitle, shortTitle, note, TypUzemnejJednotky::OKRES, vyssiaUzemnaJednotka) {}

inline Okres::~Okres()
{
	delete vekMuzi_;
	vekMuzi_ = nullptr;
	delete vekZeny_;
	vekZeny_ = nullptr;
	delete vzdelavanie_;
	vzdelavanie_ = nullptr;
}

inline Vzdelanie* Okres::getVzdelavanie()
{
	return vzdelavanie_;
}
inline bool Okres::setVzdelanie()
{
	int getBezUkoncenia = 0;
	int getBezVzdelavania = 0;
	int getNezistene = 0;
	int getStredne = 0;
	int getUcnovske = 0;
	int getVysokoskolske = 0;
	int getVyssie = 0;
	int getZakladne = 0;

	for (auto item : *nizsieUzemneJednotky_) {
		Obec* o = dynamic_cast<Obec*>(item->accessData());
		if (o->getVzdelavanie() != nullptr)
		{
			getBezUkoncenia += o->getVzdelavanie()->getBezUkoncenia();
			getBezVzdelavania += o->getVzdelavanie()->getBezVzdelavania();
			getNezistene += o->getVzdelavanie()->getNezistene();
			getStredne += o->getVzdelavanie()->getStredne();
			getUcnovske += o->getVzdelavanie()->getUcnovske();
			getVysokoskolske += o->getVzdelavanie()->getVysokoskolske();
			getVyssie += o->getVzdelavanie()->getVyssie();
			getZakladne += o->getVzdelavanie()->getZakladne();
		}
	}
	vzdelavanie_->setBezUkoncenia(getBezUkoncenia);
	vzdelavanie_->setBezVzdelavania(getBezVzdelavania);
	vzdelavanie_->setNezistene(getNezistene);
	vzdelavanie_->setStredne(getStredne);
	vzdelavanie_->setUcnovske(getUcnovske);
	vzdelavanie_->setVysokoskolske(getVysokoskolske);
	vzdelavanie_->setVyssie(getVyssie);
	vzdelavanie_->setZakladne(getZakladne);
	return true;
}

inline Array<int>* Okres::getVekMuzi()
{
	return vekMuzi_;
}

inline Array<int>* Okres::getVekZeny()
{
	return vekZeny_;
}

inline bool Okres::setVekMuzi()
{
	for (auto item : *nizsieUzemneJednotky_) {
		for (size_t i = 0; i < vekMuzi_->size(); i++)
		{
			Obec* o = dynamic_cast<Obec*>(item->accessData());
			vekMuzi_->at(i) += o->getVekMuzi()->at(i);
		}
	}
	return true;
}

inline bool Okres::setVekZeny()
{
	for (auto item : *nizsieUzemneJednotky_) {
		for (size_t i = 0; i < vekZeny_->size(); i++)
		{
			Obec* o = dynamic_cast<Obec*>(item->accessData());
			vekZeny_->at(i) += o->getVekZeny()->at(i);
		}
	}
	return true;
}



