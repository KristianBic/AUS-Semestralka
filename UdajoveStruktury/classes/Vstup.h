#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../structures/table/sorted_sequence_table.h"
#include "../structures/table/unsorted_sequence_table.h"
#include "../structures/table/sorting/quick_sort.h"
#include "Obec.h"
#include "Okres.h"
#include "Kraj.h"
#include "Krajina.h"

using namespace structures;

class Vstup
{
public:
	Vstup(std::string nazovSuboru1, std::string nazovSuboru2, std::string nazovSuboru3, std::string nazovSuboru4, std::string nazovSuboru5);
	~Vstup();
	void citajSuborVzdelanie();
	void citajSuborVek();
	void citajSuborUzemnaJednotka(std::string nazovSuboru);
	void nacitajSubory();
	void nacitanieVekovVzdelavaie();
	void spracujUdaje(Array<std::string*>* udaje, int spracovaneUdaje);
	SortedSequenceTable<std::string, UzemnaJednotka*>* getVsetkyUzemneJednotky() { return vsetkyUzemneJednotky; };

private:
	std::string nazovSuboru1_;
	std::string nazovSuboru2_;
	std::string nazovSuboru3_;
	std::string nazovSuboru4_;
	std::string nazovSuboru5_;

	SortedSequenceTable<std::string, Vzdelanie*>* zoznamVzdelanie_;
	SortedSequenceTable<std::string, Array<int>*>* zoznamVekMuz_;
	SortedSequenceTable<std::string, Array<int>*>* zoznamVekZena_;
	SortedSequenceTable<std::string, UzemnaJednotka*>* vsetkyUzemneJednotky = new SortedSequenceTable<std::string, UzemnaJednotka*>();
	int pocetUzemnychJednotiek = 1;
	Krajina* krajinaSlovensko;
};

