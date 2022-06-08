#pragma once
#include <iostream>
#include "TypUzemnejJednotky.h"
#include "../structures/table/sorted_sequence_table.h"
#include "Vzdelanie.h"
#include "../structures/array/array.h"
using namespace structures;

class UzemnaJednotka
{
protected:
	UzemnaJednotka(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, TypUzemnejJednotky typUzemnehoCelku, UzemnaJednotka* vyssiaUzemnaJednotka);
	std::string code_;
	std::string officialTitle_;
	std::string mediumTitle_;
	std::string shortTitle_;
	std::string note_;
	TypUzemnejJednotky typUzemnehoCelku_;
	UzemnaJednotka* vyssiaUzemnaJednotka_;
	SortedSequenceTable<std::string, UzemnaJednotka*>* nizsieUzemneJednotky_;
public:
	virtual ~UzemnaJednotka();
	virtual Vzdelanie* getVzdelavanie() = 0;
	virtual Array<int>* getVekMuzi() = 0;
	virtual Array<int>* getVekZeny() = 0;
	virtual bool setVekMuzi() = 0;
	virtual bool setVekZeny() = 0;
	virtual bool setVzdelanie() = 0;
	void pridajUzemnuJednotkuDoZoznamu(UzemnaJednotka* nizsiaUzemnaJednotka);
	std::string getCode() { return code_; }
	std::string getOfficialTitle() { return officialTitle_; }
	std::string getMediumTitle() { return mediumTitle_; }
	std::string getShortTitle() { return shortTitle_; }
	std::string getNote() { return note_; }
	TypUzemnejJednotky getTypUzemnehoCelku() { return typUzemnehoCelku_; }
	UzemnaJednotka* getVyssiaUzemnaJednotka() { return vyssiaUzemnaJednotka_; }
	SortedSequenceTable<std::string, UzemnaJednotka*>* getNizsieUzemneCelky() { return nizsieUzemneJednotky_; }
};



inline UzemnaJednotka::UzemnaJednotka(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note, TypUzemnejJednotky typUzemnehoCelku, UzemnaJednotka* vyssiaUzemnaJednotka) :
	code_(code), officialTitle_(officialTitle), mediumTitle_(mediumTitle), shortTitle_(shortTitle), note_(note), vyssiaUzemnaJednotka_(vyssiaUzemnaJednotka), typUzemnehoCelku_(typUzemnehoCelku),
	nizsieUzemneJednotky_(new SortedSequenceTable<std::string, UzemnaJednotka*>()) {}

inline UzemnaJednotka::~UzemnaJednotka()
{
	for (auto item : *nizsieUzemneJednotky_) {
		delete item->accessData();
	}
	
	delete nizsieUzemneJednotky_;
	nizsieUzemneJednotky_ = nullptr;
}

inline void UzemnaJednotka::pridajUzemnuJednotkuDoZoznamu(UzemnaJednotka* nizsiaUzemnaJednotka)
{
	nizsieUzemneJednotky_->insert(nizsiaUzemnaJednotka->getCode(), nizsiaUzemnaJednotka);
}
