#pragma once
#include "UzemnaJednotka.h"

class Kraj : public UzemnaJednotka
{
private:
	Array<int>* vekMuzi_ = new Array<int>(101);
	Array<int>* vekZeny_ = new Array<int>(101);
	Vzdelanie* vzdelavanie_ = new Vzdelanie(0, 0, 0, 0, 0, 0, 0, 0);
public:
	Kraj(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka);
	~Kraj();
	Vzdelanie* getVzdelavanie() override;
	Array<int>* getVekMuzi() override;
	Array<int>* getVekZeny() override;
	bool setVekMuzi() override;
	bool setVekZeny() override;
	bool setVzdelanie() override;
};

inline Kraj::Kraj(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, UzemnaJednotka* vyssiaUzemnaJednotka) :
	UzemnaJednotka(code, officialTitle, mediumTitle, shortTitle, note, TypUzemnejJednotky::KRAJ, vyssiaUzemnaJednotka) {}

inline Kraj::~Kraj()
{
	delete vekMuzi_;
	vekMuzi_ = nullptr;
	delete vekZeny_;
	vekZeny_ = nullptr;
	delete vzdelavanie_;
	vzdelavanie_ = nullptr;
}

inline Vzdelanie* Kraj::getVzdelavanie()
{
	return vzdelavanie_;
}
inline bool Kraj::setVzdelanie()
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
		Okres* o = dynamic_cast<Okres*>(item->accessData());
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


inline Array<int>* Kraj::getVekMuzi()
{
	return vekMuzi_;
}

inline Array<int>* Kraj::getVekZeny()
{
	return vekZeny_;
}

inline bool Kraj::setVekMuzi()
{
	for (auto item : *nizsieUzemneJednotky_) {
		for (size_t i = 0; i < vekMuzi_->size(); i++)
		{
			Okres* o = dynamic_cast<Okres*>(item->accessData());
			vekMuzi_->at(i) += o->getVekMuzi()->at(i);
		}
	}
	return true;
}

inline bool Kraj::setVekZeny()
{
	for (auto item : *nizsieUzemneJednotky_) {
		for (size_t i = 0; i < vekZeny_->size(); i++)
		{
			Okres* o = dynamic_cast<Okres*>(item->accessData());
			vekZeny_->at(i) += o->getVekZeny()->at(i);
		}
	}
	return true;
}

