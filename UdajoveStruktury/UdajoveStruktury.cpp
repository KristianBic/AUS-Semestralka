#pragma once
#include <iostream>
#include <string>
#include "classes/Vstup.h"
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorting/quick_sort.h"
#include <windows.h>
#include "structures/heap_monitor.h"


#include "kriterium/KriteriumUJNazov.h"
#include "kriterium/KriteriumUJTyp.h"
#include "kriterium/KriteriumUJPrislusnosth.h"
#include "kriterium/KriteriumUJVzdelaniePocet.h"
#include "kriterium/KriteriumUJVzdelaniePodiel.h"
#include "kriterium/KriteriumUJVekPocet.h"
#include "kriterium/KriteriumUJVekPodiel.h"
#include "kriterium/KriteriumUJVekovaSkupinaPocet.h"
#include "kriterium/KriteriumUJVekovaSkupinaPodiel.h"
#include "kriterium/KriteriumUJNadradena.h"

#include "filter/FilterNazov.h"
#include "filter/FilterUJTyp.h"
#include "filter/FilterUJPrislusnost.h"
#include "filter/FilterUJVzdelaniePocet.h"
#include "filter/FilterUJVzdelaniePodiel.h"
#include "filter/FilterUJVekPocet.h"
#include "filter/FilterUJVekPodiel.h"
#include "filter//FilterUJVekovaSkupinaPocet.h"
#include "filter//FilterUJVekovaSkupinaPodiel.h"
#include "filter/FilterOR.h"
#include "filter/FilterAND.h"
#include "filter/Filter.h"
#include "filter/SelectionKriteriumMinimum.h"
#include "filter/SelectionKriteriumMaximum.h"
#include "structures/table/sorting/quick_sort_VekSkup.h"

SortedSequenceTable<std::string, UzemnaJednotka*>* vsetkyUzemneJednotky = new SortedSequenceTable<std::string, UzemnaJednotka*>();

TypPohlavia getTypPohlaviaIndex(int index) {
    switch (index)
    {
    case 1: {
        return TypPohlavia::MUZ;
    }
    case 2: {
        return TypPohlavia::ZENA;
    }
    default:
        break;
    }
}

TypUzemnejJednotky getTypUzemnejJednotkyIndex(int index) {
    switch (index)
    {
    case 1: {
        return TypUzemnejJednotky::KRAJ;
        break;
    }
    case 2: {
        return TypUzemnejJednotky::OKRES;
        break;
    }
    case 3: {
        return TypUzemnejJednotky::OBEC;
        break;
    }
    default:
        break;
    }
}

TypVekovejSkupiny getTypVekovejSkupinyIndex(int index) {
    switch (index)
    {
    case 1: {
        return TypVekovejSkupiny::PREDPRODUKTIVNY;
    }
    case 2: {
        return TypVekovejSkupiny::PRODUKTIVNY;
    }
    case 3: {
        return TypVekovejSkupiny::POPRODUKTIVNY;
    }
    default:
        break;
    }
}

TypVzdelavania getTypVzdelavaniaIndex(int index) {

    switch (index)
    {
    case 1: {
        return TypVzdelavania::NEZISTENE;
    }
    case 2: {
        return TypVzdelavania::BEZ_VZDELAVANIA;
    }
    case 3: {
        return TypVzdelavania::VYSOKOSKOLSKE;
    }
    case 4: {
        return TypVzdelavania::VYSSIE;
    }
    case 5: {
        return TypVzdelavania::STREDNE;
    }
    case 6: {
        return TypVzdelavania::UCNOVSKE;
    }
    case 7: {
        return TypVzdelavania::ZAKLADNE;
    }
    case 8: {
        return TypVzdelavania::BEZ_UKONCENIA;
    }
    default:
        break;
    }
}

void testKriteria()
{
    
    system("CLS");
    std::cout << " *** Test Kriterii *** " << std::endl;

    KriteriumUJNazov* kriteriumNazov = new KriteriumUJNazov();
    std::string nazov = kriteriumNazov->evaluate(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    std::cout << "kriteriumNazov: " << nazov << std::endl;

    
    KriteriumUJTyp* kriteriumTyp = new KriteriumUJTyp();
    TypUzemnejJednotky typ = kriteriumTyp->evaluate(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    if (typ == TypUzemnejJednotky::KRAJ) { std::cout << "kriteriumTyp: " << "kraj" << std::endl; }

   
    KriteriumUJPrislusnost* kriteriumPrislusnost = new KriteriumUJPrislusnost(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    bool prislinost = kriteriumPrislusnost->evaluate(vsetkyUzemneJednotky->find("Bratislavský kraj")->getNizsieUzemneCelky()->find("SK0101"));
    std::cout << "kriteriumPrislusnost: " << prislinost << std::endl;
    
    
    KriteriumUJVzdelaniePocet* kriteriumUJVzdelaniePocet = new KriteriumUJVzdelaniePocet(TypVzdelavania::NEZISTENE);
    int pocetVzdel = kriteriumUJVzdelaniePocet->evaluate(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    std::cout << "kriteriumUJVzdelaniePocet: " << pocetVzdel << std::endl;
    

    KriteriumUJVzdelaniePodiel* kriteriumUJVzdelaniePodiel = new KriteriumUJVzdelaniePodiel(TypVzdelavania::STREDNE);
    double podielpocet = kriteriumUJVzdelaniePodiel->evaluate(vsetkyUzemneJednotky->find("Okres Bratislava I"));
    std::cout << "kriteriumUJVzdelaniePodiel: " << podielpocet << std::endl;


    KriteriumUJVekPocet* kriteriumUJVekPocet = new KriteriumUJVekPocet(5, TypPohlavia::MUZ);
    int pocetVek = kriteriumUJVekPocet->evaluate(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    std::cout << "kriteriumUJVekPocet: " << pocetVek << std::endl;

    
    KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(10, TypPohlavia::MUZ);
    double podielVek = kriteriumUJVekPodiel->evaluate(vsetkyUzemneJednotky->find("Okres Bratislava I"));
    std::cout << "kriteriumUJVekPodiel: " << podielVek << std::endl;
    
   
    KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(TypVekovejSkupiny::POPRODUKTIVNY);
    int vekovaSkupPocet = kriteriumUJVekovaSkupinaPocet->evaluate(vsetkyUzemneJednotky->find("Okres Bratislava I"));
    std::cout << "kriteriumUJVekovaSkupinaPocet: " << vekovaSkupPocet << std::endl;


    KriteriumUJVekovaSkupinaPodiel* kriteriumUJVekovaSkupinaPodiel = new KriteriumUJVekovaSkupinaPodiel(TypVekovejSkupiny::POPRODUKTIVNY);
    double vekovaSkupPodiel = kriteriumUJVekovaSkupinaPodiel->evaluate(vsetkyUzemneJednotky->find("Okres Bratislava I"));
    std::cout << "kriteriumUJVekovaSkupinaPodiel: " << vekovaSkupPodiel << std::endl;


    KriteriumUJNadradena* kriteriumUJNadradena = new KriteriumUJNadradena();
    UzemnaJednotka* nadradenaJednotka = kriteriumUJNadradena->evaluate(vsetkyUzemneJednotky->find("Okres Bratislava I"));
    std::cout << "kriteriumUJNadradena: " << nadradenaJednotka->getOfficialTitle() << std::endl;
   
    delete kriteriumNazov;
    delete kriteriumTyp;
    delete kriteriumPrislusnost;    
    delete kriteriumUJVzdelaniePocet;
    delete kriteriumUJVzdelaniePodiel;
    delete kriteriumUJVekPocet;
    delete kriteriumUJVekPodiel;
    delete kriteriumUJVekovaSkupinaPocet;
    delete kriteriumUJVekovaSkupinaPodiel;
    delete kriteriumUJNadradena;
    
    
}

void testFiltre() {
    
    system("CLS");
    std::cout << " *** Test Filtre *** " << std::endl;

    FilterNazov* filterNazov = new FilterNazov("Bratislavský kraj");
    std::cout << "filterNazov: " << filterNazov->pass(vsetkyUzemneJednotky->find("Bratislavský kraj")) << std::endl;

    FilterUJTyp* filterUJTyp = new FilterUJTyp(TypUzemnejJednotky::KRAJ);
    std::cout << "filterUJTyp: " << filterNazov->pass(vsetkyUzemneJednotky->find("Bratislavský kraj")) << std::endl;
  
    FilterUJPrislusnost* filterUJPrislusnost = new FilterUJPrislusnost(vsetkyUzemneJednotky->find("Bratislavský kraj"));
    std::cout << "filterUJPrislusnost: " << filterUJPrislusnost->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;
    
    FilterUJVzdelaniePocet* filterUJVzdelaniePocet = new FilterUJVzdelaniePocet(0, 10000, TypVzdelavania::BEZ_UKONCENIA);
    std::cout << "filterUJVzdelaniePocet: " << filterUJVzdelaniePocet->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;
    
    FilterUJVzdelaniePodiel* filterUJVzdelaniePodiel = new FilterUJVzdelaniePodiel(0, 10000, TypVzdelavania::BEZ_UKONCENIA);
    std::cout << "filterUJVzdelaniePodiel: " << filterUJVzdelaniePodiel->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;

    FilterUJVekPocet* filterUJVekPocet = new FilterUJVekPocet(0, 100000, TypPohlavia::MUZ, 10);
    std::cout << "filterUJVekPocet: " << filterUJVekPocet->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;
    
    FilterUJVekPodiel* filterUJVekPodiel = new FilterUJVekPodiel(0, 10000, TypPohlavia::MUZ, 10);
    std::cout << "filterUJVekPodiel: " << filterUJVekPodiel->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;
   
    FilterUJVekovaSkupinaPocet* filterUJVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(0, 10000000, TypVekovejSkupiny::POPRODUKTIVNY);
    std::cout << "filterUJVekovaSkupinaPocet: " << filterUJVekovaSkupinaPocet->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;

    FilterUJVekovaSkupinaPodiel* filterUJVekovaSkupinaPodiel = new FilterUJVekovaSkupinaPodiel(0, 10000, TypVekovejSkupiny::POPRODUKTIVNY);
    std::cout << "filterUJVekovaSkupinaPodiel: " << filterUJVekovaSkupinaPodiel->pass(vsetkyUzemneJednotky->find("Okres Bratislava I")) << std::endl;
    
    //////////CompositeFilter////////////

    FilterOR<UzemnaJednotka>* filterOR = new FilterOR<UzemnaJednotka>();
    filterOR->registeredFilter((Filter<UzemnaJednotka>*)filterNazov);
    std::cout << "filterOR: " << filterOR->pass(vsetkyUzemneJednotky->find("Bratislavský kraj")) << std::endl;
    
    FilterAND<UzemnaJednotka>* filterAND = new FilterAND<UzemnaJednotka>();
    filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterNazov);
    filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterNazov);
    std::cout << "filterAND: " << filterAND->pass(vsetkyUzemneJednotky->find("Bratislavský kraj")) << std::endl;
   
    
    //////////SelectionKriterium////////////

    UnsortedSequenceTable<int, UzemnaJednotka*>* tabulkaVyberove = new UnsortedSequenceTable<int, UzemnaJednotka*>();
    tabulkaVyberove->insert(1, vsetkyUzemneJednotky->find("Ve¾ké Orvište"));
    tabulkaVyberove->insert(2, vsetkyUzemneJednotky->find("Hubina"));
    tabulkaVyberove->insert(3, vsetkyUzemneJednotky->find("Ducové"));
    tabulkaVyberove->insert(4, vsetkyUzemneJednotky->find("Bašovce"));
    SelectionKriteriumMinimum* najmensiaVS = new SelectionKriteriumMinimum(TypVekovejSkupiny::POPRODUKTIVNY);
    UzemnaJednotka* jednotka =  najmensiaVS->selectBest(tabulkaVyberove); 
    std::cout << jednotka->getOfficialTitle() << std::endl; 

    UnsortedSequenceTable<int, UzemnaJednotka*>* tabulkaVyberove2 = new UnsortedSequenceTable<int, UzemnaJednotka*>();
    tabulkaVyberove2->insert(1, vsetkyUzemneJednotky->find("Ve¾ké Orvište"));
    tabulkaVyberove2->insert(2, vsetkyUzemneJednotky->find("Hubina"));
    tabulkaVyberove2->insert(3, vsetkyUzemneJednotky->find("Ducové"));
    tabulkaVyberove2->insert(4, vsetkyUzemneJednotky->find("Bašovce"));
    SelectionKriteriumMaximum* najvacsiVS = new SelectionKriteriumMaximum(TypVekovejSkupiny::POPRODUKTIVNY);
    UzemnaJednotka* jednotka2 = najvacsiVS->selectBest(tabulkaVyberove2);
    std::cout << jednotka2->getOfficialTitle() << std::endl;
    
    
    delete filterNazov;
    delete filterUJTyp;
    delete filterUJPrislusnost;
    delete filterUJVzdelaniePocet;
    delete filterUJVzdelaniePodiel;
    delete filterUJVekPocet;
    delete filterUJVekPodiel;
    delete filterUJVekovaSkupinaPocet;
    delete filterUJVekovaSkupinaPodiel;
    
    delete filterOR;
    delete filterAND;
    
    delete tabulkaVyberove;
    delete najmensiaVS;
    delete tabulkaVyberove2;
    delete najvacsiVS;
    }

void bodoveVyhladavanie() {
    system("CLS");
    std::string inputNazov;
    int vzdelanie;
    int evs;

    std::cout << " Zadajte názov územnej jednotky pre bodove vyhladávanie" << inputNazov << std::endl;
    std::cout << "Odpoved: ";
    std::cin.ignore();
    std::getline(std::cin, inputNazov);

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte typVzdelania (1-8)" << std::endl;
    std::cout << "  1.NEZISTENE" <<  std::endl;
    std::cout << "  2.BEZ_VZDELAVANIA" <<  std::endl;
    std::cout << "  3.VYSOKOSKOLSKE" <<  std::endl;
    std::cout << "  4.VYSSIE" <<  std::endl;
    std::cout << "  5.STREDNE" <<  std::endl;
    std::cout << "  6.UCNOVSKE" <<  std::endl;
    std::cout << "  7.ZAKLADNE" <<  std::endl;
    std::cout << "  8.BEZ_UKONCENIA" <<  std::endl;
    std::cout << "Odpoved: ";
    std::cin >> vzdelanie;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
    std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
    std::cout << "  2.PRODUKTIVNY" << std::endl;
    std::cout << "  3.POPRODUKTIVNY" << std::endl;
    std::cout << "Odpoved: ";
    std::cin >> evs;

    system("CLS");
    
    
   
    KriteriumUJNazov* kriteriumNazov = new KriteriumUJNazov();
    std::string nazov = kriteriumNazov->evaluate(vsetkyUzemneJednotky->find(inputNazov));
    KriteriumUJTyp* kriteriumTyp = new KriteriumUJTyp();
    TypUzemnejJednotky typ = kriteriumTyp->evaluate(vsetkyUzemneJednotky->find(inputNazov));
    if (typ == TypUzemnejJednotky::KRAJ) { 
        std::cout << "kriteriumNazov: " << nazov << std::endl;
        std::cout << "kriteriumTyp: " << "KRAJ" << std::endl;
        std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
    }
    else if (typ == TypUzemnejJednotky::OKRES) { 
        std::cout << "kriteriumNazov: " << nazov << std::endl;
        std::cout << "kriteriumTyp: " << "OKRES" << std::endl; 
        std::cout << "patriDoUzemnejJednotky ->KRAJ: " << vsetkyUzemneJednotky->find(inputNazov)->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
        std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
    }
    else if (typ == TypUzemnejJednotky::OBEC) { 
        std::cout << "kriteriumNazov: " << nazov << std::endl;
        std::cout << "kriteriumTyp: " << "OBEC" << std::endl; 
        std::cout << "patriDoUzemnejJednotky ->OKRES: " << vsetkyUzemneJednotky->find(inputNazov)->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
        std::cout << "patriDoUzemnejJednotky ->KRAJ: " << vsetkyUzemneJednotky->find(inputNazov)->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
        std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
    }
    else { 
        std::cout << "kriteriumNazov: " << "Slovakia" << std::endl;
        std::cout << "kriteriumTyp: " << "KRAJINA" << std::endl; 
    }
    
    KriteriumUJVzdelaniePocet* kriteriumUJVzdelaniePocet = new KriteriumUJVzdelaniePocet(getTypVzdelavaniaIndex(vzdelanie));
    int pocetVzdel = kriteriumUJVzdelaniePocet->evaluate(vsetkyUzemneJednotky->find(inputNazov));
    std::cout << "kriteriumUJVzdelaniePocet: " << pocetVzdel << std::endl;

    KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(evs));
    int vekovaSkupPocet = kriteriumUJVekovaSkupinaPocet->evaluate(vsetkyUzemneJednotky->find(inputNazov));
    std::cout << "kriteriumUJVekovaSkupinaPocet: " << vekovaSkupPocet << std::endl;


    delete kriteriumNazov;
    delete kriteriumTyp;
    delete kriteriumUJVzdelaniePocet;
    delete kriteriumUJVekovaSkupinaPocet;
    
}

void aplikaciaFiltrov() {
    bool FilterUJTypPassed = false;
    bool FilterUJPrislusnostPassed = false;
    bool FilterUJVzdelaniePocetPassed = false;
    bool FilterUJVzdelaniePodielPassed = false;
    bool FilterUJVekPocetPassed = false;
    bool FilterUJVekPodielPassed = false;
    bool FilterUJVekovaSkupinaPocetPassed = false;
    bool FilterUJVekovaSkupinaPodielPassed = false;

    
    FilterAND<UzemnaJednotka>* filterAND = new FilterAND<UzemnaJednotka>();
    FilterUJTyp* filterUJTyp = nullptr;
    FilterUJPrislusnost* filterUJPrislusnost = nullptr;
    FilterUJVzdelaniePocet* filterUJVzdelaniePocet = nullptr;
    FilterUJVzdelaniePodiel* filterUJVzdelaniePodiel = nullptr;
    FilterUJVekPocet* filterUJVekPocet = nullptr;
    FilterUJVekPodiel* filterUJVekPodiel = nullptr;
    FilterUJVekovaSkupinaPocet* filterUJVekovaSkupinaPocet = nullptr;
    FilterUJVekovaSkupinaPodiel* filterUJVekovaSkupinaPodiel = nullptr;

    KriteriumUJVzdelaniePocet* kriteriumUJVzdelaniePocet = nullptr;
    KriteriumUJVzdelaniePodiel* kriteriumUJVzdelaniePodiel = nullptr;
    KriteriumUJVekPocet* kriteriumUJVekPocet = nullptr;
    KriteriumUJVekPodiel* kriteriumUJVekPodiel = nullptr;
    KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = nullptr;
    KriteriumUJVekovaSkupinaPodiel* kriteriumUJVekovaSkupinaPodiel = nullptr;

    bool ukoncenie = true;
    while (ukoncenie)
    {
    system("CLS");
    int filter;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte filter, ktorý chcete aplikovat (1-8)" << std::endl;
    if (FilterUJTypPassed == true) { std::cout << "*"; }
    std::cout << "  1.FilterUJTyp" << std::endl; 
    if (FilterUJPrislusnostPassed == true) { std::cout << "*"; }
    std::cout << "  2.FilterUJPrislusnost" << std::endl;
    if (FilterUJVzdelaniePocetPassed == true) { std::cout << "*"; }
    std::cout << "  3.FilterUJVzdelaniePocet" << std::endl;
    if (FilterUJVzdelaniePodielPassed == true) { std::cout << "*"; }
    std::cout << "  4.FilterUJVzdelaniePodiel" << std::endl;
    if (FilterUJVekPocetPassed == true) { std::cout << "*"; }
    std::cout << "  5.FilterUJVekPocet" << std::endl;
    if (FilterUJVekPodielPassed == true) { std::cout << "*"; }
    std::cout << "  6.FilterUJVekPodiel" << std::endl;
    if (FilterUJVekovaSkupinaPocetPassed == true) { std::cout << "*"; }
    std::cout << "  7.FilterUJVekovaSkupinaPocet" << std::endl;
    if (FilterUJVekovaSkupinaPodielPassed == true) { std::cout << "*"; }
    std::cout << "  8.FilterUJVekovaSkupinaPodiel" << std::endl;
    std::cout << "  9.Spustit" << std::endl;
    std::cout << "Odpoved: ";
    std::cin >> filter;
    
    std::cout << "-----------------------------------------------------" << std::endl;

    

    switch (filter)
    {
    case 1: {
        if (FilterUJTypPassed == true)
        {
            std::cout << " FilterUJTyp je uz uplatneny" << std::endl;
            break;
        }
        int filterUJTypChoice;
        std::cout << " Zadajte TypUzemnejJednotky pre filter: filterUJTyp" << std::endl;
        std::cout << "  1.KRAJ" << std::endl;
        std::cout << "  2.OKRES" << std::endl;
        std::cout << "  3.OBEC" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterUJTypChoice;
        std::cout << "-----------------------------------------------------" << std::endl;
        filterUJTyp = new FilterUJTyp(getTypUzemnejJednotkyIndex(filterUJTypChoice));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJTyp);
        FilterUJTypPassed = true;
        break;
    }
    case 2: {
        if (FilterUJPrislusnostPassed == true)
        {
            std::cout << " filterUJPrislusnost je uz uplatneny" << std::endl;
            break;
        }
        std::string nazovUzemnejJednotky;
        std::cout << " Zadajte nazov uzemnejJednotka pre filter: filterUJPrislusnost" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nazovUzemnejJednotky);
        filterUJPrislusnost = new FilterUJPrislusnost(vsetkyUzemneJednotky->find(nazovUzemnejJednotky));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJPrislusnost);

        FilterUJPrislusnostPassed = true;
        break;
    }
    case 3: {
        if (FilterUJVzdelaniePocetPassed == true)
        {
            std::cout << " filterUJVzdelaniePocet je uz uplatneny" << std::endl;
            break;
        }

        int filterTypVzdelavanieVzelavaniePocet;
        int filterDolnaHranicaVzdelavaiePocet;
        int filterHornaHranicaVzdelavaiePocet;
        std::cout << " Zadajte typVzdelania (1-8)" << std::endl;
        std::cout << "  1.NEZISTENE" << std::endl;
        std::cout << "  2.BEZ_VZDELAVANIA" << std::endl;
        std::cout << "  3.VYSOKOSKOLSKE" << std::endl;
        std::cout << "  4.VYSSIE" << std::endl;
        std::cout << "  5.STREDNE" << std::endl;
        std::cout << "  6.UCNOVSKE" << std::endl;
        std::cout << "  7.ZAKLADNE" << std::endl;
        std::cout << "  8.BEZ_UKONCENIA" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVzdelavanieVzelavaniePocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVzdelaniePocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVzdelavaiePocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVzdelaniePocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVzdelavaiePocet;

        filterUJVzdelaniePocet = new FilterUJVzdelaniePocet(filterDolnaHranicaVzdelavaiePocet, filterHornaHranicaVzdelavaiePocet, getTypVzdelavaniaIndex(filterTypVzdelavanieVzelavaniePocet));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVzdelaniePocet);
        kriteriumUJVzdelaniePocet = new KriteriumUJVzdelaniePocet(getTypVzdelavaniaIndex(filterTypVzdelavanieVzelavaniePocet));
        FilterUJVzdelaniePocetPassed = true;
        break;
    }
    case 4: {
        if (FilterUJVzdelaniePodielPassed == true)
        {
            std::cout << " filterUJVzdelaniePodiel je uz uplatneny" << std::endl;
            break;
        }
        int filterTypVzdelavanieVzelavaniePodiel;
        int filterDolnaHranicaVzdelavaiePodiel;
        int filterHornaHranicaVzdelavaiePodiel;
        std::cout << " Zadajte typVzdelania (1-8)" << std::endl;
        std::cout << "  1.NEZISTENE" << std::endl;
        std::cout << "  2.BEZ_VZDELAVANIA" << std::endl;
        std::cout << "  3.VYSOKOSKOLSKE" << std::endl;
        std::cout << "  4.VYSSIE" << std::endl;
        std::cout << "  5.STREDNE" << std::endl;
        std::cout << "  6.UCNOVSKE" << std::endl;
        std::cout << "  7.ZAKLADNE" << std::endl;
        std::cout << "  8.BEZ_UKONCENIA" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVzdelavanieVzelavaniePodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVzdelaniePodiel" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVzdelavaiePodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVzdelaniePodiel" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVzdelavaiePodiel;

        filterUJVzdelaniePodiel = new FilterUJVzdelaniePodiel(filterDolnaHranicaVzdelavaiePodiel, filterHornaHranicaVzdelavaiePodiel, getTypVzdelavaniaIndex(filterTypVzdelavanieVzelavaniePodiel));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVzdelaniePodiel);
        kriteriumUJVzdelaniePodiel =  new KriteriumUJVzdelaniePodiel(getTypVzdelavaniaIndex(filterTypVzdelavanieVzelavaniePodiel));
        FilterUJVzdelaniePodielPassed = false;
        break;
    }
    case 5: {
        if (FilterUJVekPocetPassed == true)
        {
            std::cout << " FilterUJVekPocetPassed je uz uplatneny" << std::endl;
            break;
        }
        int filterTypVzdelavanieVekPocet;
        int filterDolnaHranicaVekPocet;
        int filterHornaHranicaVekPocet;
        int filterVekPocetVek;
        std::cout << " Zadajte typPohlavia (1-2)" << std::endl;
        std::cout << "  1.MUZ" << std::endl;
        std::cout << "  2.ZENA" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVzdelavanieVekPocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVekPocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVekPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVekPocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte vek filter: filterUJVekPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterVekPocetVek;

        filterUJVekPocet = new FilterUJVekPocet(filterDolnaHranicaVekPocet, filterHornaHranicaVekPocet, getTypPohlaviaIndex(filterTypVzdelavanieVekPocet), filterVekPocetVek);
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekPocet);
        kriteriumUJVekPocet = new KriteriumUJVekPocet(filterVekPocetVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPocet));
        FilterUJVekPocetPassed = true;
        break;
    }
    case 6: {
        if (FilterUJVekPodielPassed == true)
        {
            std::cout << " filterUJVekPodiel je uz uplatneny" << std::endl;
            break;
        }
        int filterTypVzdelavanieVekPodiel;
        double filterDolnaHranicaVekPodiel;
        double filterHornaHranicaVekPodiel;
        int filterVekPodielVek;
        std::cout << " Zadajte typPohlavia (1-2)" << std::endl;
        std::cout << "  1.MUZ" << std::endl;
        std::cout << "  2.ZENA" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVzdelavanieVekPodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekPodiel" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVekPodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVekPodiel" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVekPodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte vek filter: filterUJVekPodiel" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterVekPodielVek;

        filterUJVekPodiel = new FilterUJVekPodiel(filterDolnaHranicaVekPodiel, filterHornaHranicaVekPodiel, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel), filterVekPodielVek);
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekPodiel);
        kriteriumUJVekPodiel = new KriteriumUJVekPodiel(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
        FilterUJVekPodielPassed = true;
        break;
    }
    case 7: { 
        if (FilterUJVekovaSkupinaPocetPassed == true)
        {
            std::cout << " filterUJVekovaSkupinaPocet je uz uplatneny" << std::endl;
            break;
        }
        int filterTypVekovaSkupinaPocet;
        int filterDolnaHranicaVekovaSkupinaPocet;
        int filterHornaHranicaVekovaSkupinaPocet;
        std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
        std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
        std::cout << "  2.PRODUKTIVNY" << std::endl;
        std::cout << "  3.POPRODUKTIVNY" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVekovaSkupinaPocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVekovaSkupinaPocet;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVekovaSkupinaPocet;
        filterUJVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(filterDolnaHranicaVekovaSkupinaPocet, filterHornaHranicaVekovaSkupinaPocet, getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekovaSkupinaPocet);
        kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
        FilterUJVekovaSkupinaPocetPassed = true;
        break;
    }
    case 8: {
        if (FilterUJVekovaSkupinaPodielPassed == true)
        {
            std::cout << " filterUJVekovaSkupinaPodiel je uz uplatneny" << std::endl;
            break;
        }
        int filterTypVekovaSkupinaPodiel;
        int filterDolnaHranicaVekovaSkupinaPodiel;
        int filterHornaHranicaVekovaSkupinaPodiel;
        std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
        std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
        std::cout << "  2.PRODUKTIVNY" << std::endl;
        std::cout << "  3.POPRODUKTIVNY" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterTypVekovaSkupinaPodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterDolnaHranicaVekovaSkupinaPodiel;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Zadajte hornu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterHornaHranicaVekovaSkupinaPodiel;
        filterUJVekovaSkupinaPodiel = new FilterUJVekovaSkupinaPodiel(filterDolnaHranicaVekovaSkupinaPodiel, filterHornaHranicaVekovaSkupinaPodiel, getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPodiel));
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekovaSkupinaPodiel);
        kriteriumUJVekovaSkupinaPodiel = new KriteriumUJVekovaSkupinaPodiel(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPodiel));
        FilterUJVekovaSkupinaPodielPassed = true;
        break;
    }
    default:
        ukoncenie = false;
        break;
    }
    }
    for (auto item : *vsetkyUzemneJednotky)
    {
        if (filterAND->pass(item->accessData()))
        {
            std::cout << item->accessData()->getOfficialTitle() << " ---> ";
            if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ)
            {
                std::cout << "TypUJ: KRAJ" << " || ";
            } 
             if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES)
            {
                std::cout << "TypUJ: OKRES" << " || ";
            }
             if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC)
            {
                std::cout << "TypUJ: OBEC" << " || ";
            }
             if (kriteriumUJVzdelaniePocet != nullptr) {
                std::cout << "VzdelaniePocet: " << kriteriumUJVzdelaniePocet->evaluate(item->accessData()) << " || ";
            }
             if (kriteriumUJVzdelaniePodiel != nullptr){
                std::cout << "VzdelaniePodiel: " << kriteriumUJVzdelaniePodiel->evaluate(item->accessData()) << " || ";
            }
             if (kriteriumUJVekPocet != nullptr) {
                std::cout << "VekPocet: " << kriteriumUJVekPocet->evaluate(item->accessData()) << " || ";
            }
             if (kriteriumUJVekPodiel != nullptr) {
                std::cout << "VekPodiel: " << kriteriumUJVekPodiel->evaluate(item->accessData()) << " || ";
            }
             if (kriteriumUJVekovaSkupinaPocet != nullptr) {
                std::cout << "VekovaSkupinaPocet: " << kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData()) << " || ";
            }
             if (kriteriumUJVekovaSkupinaPodiel != nullptr) {
                std::cout << "VekovaSkupinaPodiel: " << kriteriumUJVekovaSkupinaPodiel->evaluate(item->accessData()) << " || ";
            }
            std::cout << " " << std::endl;
            if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ) {
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES) {
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << item->accessData()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC) {
                std::cout << "patriDoUzemnejJednotky ->OKRES: " << item->accessData()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << item->accessData()->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }            
            std::cout << "-----------------------------------------------------" << std::endl;
        }
    }
    delete filterAND;
    delete filterUJTyp;
    delete filterUJPrislusnost;
    delete filterUJVzdelaniePocet;
    delete filterUJVzdelaniePodiel;
    delete filterUJVekPocet;
    delete filterUJVekPodiel;
    delete filterUJVekovaSkupinaPocet;
    delete filterUJVekovaSkupinaPodiel;

    delete kriteriumUJVzdelaniePocet;
    delete kriteriumUJVzdelaniePodiel;
    delete kriteriumUJVekPocet;
    delete kriteriumUJVekPodiel;
    delete kriteriumUJVekovaSkupinaPocet;
    delete kriteriumUJVekovaSkupinaPodiel;
}

void triedenie() {
    system("CLS");
    std::string inputNazov;
    int stylSortovania;
    int filter;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte filter, ktorý chcete aplikovat (1-2)" << std::endl;
    std::cout << "  1.FilterUJTyp" << std::endl;
    std::cout << "  2.FilterUJPrislusnost" << std::endl;
    std::cout << "Odpoved: ";
    std::cin >> filter;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte , ako chcete triedit prvky" << std::endl;
    std::cout << "  1.Vzostupne" << std::endl;
    std::cout << "  2.Zosupne" << std::endl;
    std::cout << "Odpoved: ";
    std::cin >> stylSortovania;

    system("CLS");

    std::cout << "-----------------------------------------------------" << std::endl;

    switch (filter)
    {
    case 1: {
        UnsortedSequenceTable<std::string, UzemnaJednotka*>* filterTypUnsorted = new  UnsortedSequenceTable<std::string, UzemnaJednotka*>();
        int filterUJTypChoice;
        int secondfilterChoice;
        std::cout << " Zadajte TypUzemnejJednotky pre filter: filterUJTyp" << std::endl;
        std::cout << "  1.KRAJ" << std::endl;
        std::cout << "  2.OKRES" << std::endl;
        std::cout << "  3.OBEC" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterUJTypChoice;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Chcete pridat ju filtru: filterUJTyp jednu z nasledujucich ? " << std::endl;
        std::cout << "  1.FilterVekPodiel" << std::endl;
        std::cout << "  2.FilterVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> secondfilterChoice;
        
        //premenne//////////////////////////
        int filterTypVzdelavanieVekPodiel;
        double filterDolnaHranicaVekPodiel;
        double filterHornaHranicaVekPodiel;
        int filterVekPodielVek;

        int filterTypVekovaSkupinaPocet;
        int filterDolnaHranicaVekovaSkupinaPocet;
        int filterHornaHranicaVekovaSkupinaPocet;

        FilterUJTyp* filterUJTyp = new FilterUJTyp(getTypUzemnejJednotkyIndex(filterUJTypChoice));
        FilterAND<UzemnaJednotka>* filterAND = new FilterAND<UzemnaJednotka>();
        if (secondfilterChoice == 1)
        {
            std::cout << " Zadajte typPohlavia (1-2)" << std::endl;
            std::cout << "  1.MUZ" << std::endl;
            std::cout << "  2.ZENA" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterTypVzdelavanieVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterDolnaHranicaVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte hornu hranicu pre filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterHornaHranicaVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte vek filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterVekPodielVek;
            FilterUJVekPodiel* filterUJVekPodiel = new FilterUJVekPodiel(filterDolnaHranicaVekPodiel, filterHornaHranicaVekPodiel, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel), filterVekPodielVek);
            filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekPodiel);
            
        }
        else if (secondfilterChoice == 2) {
            std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
            std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
            std::cout << "  2.PRODUKTIVNY" << std::endl;
            std::cout << "  3.POPRODUKTIVNY" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterTypVekovaSkupinaPocet;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterDolnaHranicaVekovaSkupinaPocet;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte hornu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterHornaHranicaVekovaSkupinaPocet;
            FilterUJVekovaSkupinaPocet* filterUJVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(filterDolnaHranicaVekovaSkupinaPocet, filterHornaHranicaVekovaSkupinaPocet, getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
            filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekovaSkupinaPocet);
        }
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJTyp);
        

        for (auto item : *vsetkyUzemneJednotky)
        {
            if (item->accessData()->getTypUzemnehoCelku() == getTypUzemnejJednotkyIndex(filterUJTypChoice))
            {
                if (filterAND->pass(vsetkyUzemneJednotky->find(item->accessData()->getOfficialTitle())))
                {
                    filterTypUnsorted->insert(item->accessData()->getOfficialTitle(), item->accessData());
                }
            }  
        }
        
        system("CLS");

        if (secondfilterChoice == 1)
        {
            QuickSort<std::string, UzemnaJednotka*>* filterTypQuickSort = new QuickSort<std::string, UzemnaJednotka*>(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
            filterTypQuickSort->sort(*filterTypUnsorted);
            if (stylSortovania == 2)
            {
                int index = filterTypUnsorted->size();
                Array<UzemnaJednotka*>* zostupnePole = new Array<UzemnaJednotka*>(filterTypUnsorted->size());
                for (auto item : *filterTypUnsorted) {
                    zostupnePole->at(index - 1) = item->accessData();
                    index--;
                }
                KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
                for (size_t i = 0; i < zostupnePole->size(); i++)
                {
                    double pocetVek = kriteriumUJVekPodiel->evaluate(zostupnePole->at(i));
                    std::cout << zostupnePole->at(i)->getOfficialTitle() << " " << std::to_string(pocetVek) << std::endl;
                }
                delete kriteriumUJVekPodiel;
                delete zostupnePole;
            }
            if (stylSortovania == 1)
            {
                KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
                for (auto item : *filterTypUnsorted)
                {
                    double pocetVek = kriteriumUJVekPodiel->evaluate(item->accessData());
                    std::cout << item->accessData()->getOfficialTitle() << " " << std::to_string(pocetVek) << std::endl;
                }
                delete kriteriumUJVekPodiel;
            }
            delete filterTypQuickSort;
        }
        else if (secondfilterChoice == 2) 
        {
            QuickSortVekSkup<std::string, UzemnaJednotka*>* filterTypQuickSort = new QuickSortVekSkup<std::string, UzemnaJednotka*>(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
            filterTypQuickSort->sort(*filterTypUnsorted);
            if (stylSortovania == 2)
            {
                int index = filterTypUnsorted->size();
                Array<UzemnaJednotka*>* zostupnePole = new Array<UzemnaJednotka*>(filterTypUnsorted->size());
                for (auto item : *filterTypUnsorted) {
                    zostupnePole->at(index - 1) = item->accessData();
                    index--;
                }
                KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
                for (size_t i = 0; i < zostupnePole->size(); i++)
                {
                    int pocetVekSkup = kriteriumUJVekovaSkupinaPocet->evaluate(zostupnePole->at(i));
                    std::cout << zostupnePole->at(i)->getOfficialTitle() << " " << std::to_string(pocetVekSkup) << std::endl;
                }
                delete kriteriumUJVekovaSkupinaPocet;
                delete zostupnePole;
            }
            if (stylSortovania == 1)
            {
                KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
                for (auto item : *filterTypUnsorted)
                {
                    int pocetVekSkup = kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData());
                    std::cout << item->accessData()->getOfficialTitle() << " " << std::to_string(pocetVekSkup) << std::endl;
                }
                delete kriteriumUJVekovaSkupinaPocet;
            }     
            delete filterTypQuickSort;
        }
        else {
            for (auto item : *filterTypUnsorted)
            {
                std::cout << item->accessData()->getOfficialTitle() << std::endl;
            }
        }
        delete filterTypUnsorted;
        delete filterAND;
        delete filterUJTyp;
        break;
    }
    case 2: {
        UnsortedSequenceTable<std::string, UzemnaJednotka*>* filterTypUnsorted = new  UnsortedSequenceTable<std::string, UzemnaJednotka*>();

        system("CLS");
        std::string nazovUzemnejJednotky;
        std::cout << " Zadajte nazov vysiej uzemnej jednotky pre filter: filterUJPrislusnost" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nazovUzemnejJednotky);
        system("CLS");

        int secondfilterChoice;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Chcete pridat ju filtru: filterUJTyp jednu z nasledujucich ? " << std::endl;
        std::cout << "  1.FilterVekPodiel" << std::endl;
        std::cout << "  2.FilterVekovaSkupinaPocet" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> secondfilterChoice;


        int filterTypVzdelavanieVekPodiel;
        double filterDolnaHranicaVekPodiel;
        double filterHornaHranicaVekPodiel;
        int filterVekPodielVek;

        int filterTypVekovaSkupinaPocet;
        int filterDolnaHranicaVekovaSkupinaPocet;
        int filterHornaHranicaVekovaSkupinaPocet;

        FilterUJPrislusnost* filterUJPrislusnost = new FilterUJPrislusnost(vsetkyUzemneJednotky->find(nazovUzemnejJednotky));
        FilterAND<UzemnaJednotka>* filterAND = new FilterAND<UzemnaJednotka>();
        if (secondfilterChoice == 1)
        {
            std::cout << " Zadajte typPohlavia (1-2)" << std::endl;
            std::cout << "  1.MUZ" << std::endl;
            std::cout << "  2.ZENA" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterTypVzdelavanieVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterDolnaHranicaVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte hornu hranicu pre filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterHornaHranicaVekPodiel;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte vek filter: filterUJVekPodiel" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterVekPodielVek;
            FilterUJVekPodiel* filterUJVekPodiel = new FilterUJVekPodiel(filterDolnaHranicaVekPodiel, filterHornaHranicaVekPodiel, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel), filterVekPodielVek);
            filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekPodiel);

        }
        else if (secondfilterChoice == 2) {
            std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
            std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
            std::cout << "  2.PRODUKTIVNY" << std::endl;
            std::cout << "  3.POPRODUKTIVNY" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterTypVekovaSkupinaPocet;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte dolnu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterDolnaHranicaVekovaSkupinaPocet;
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << " Zadajte hornu hranicu pre filter: filterUJVekovaSkupinaPocet" << std::endl;
            std::cout << "Odpoved: ";
            std::cin >> filterHornaHranicaVekovaSkupinaPocet;
            FilterUJVekovaSkupinaPocet* filterUJVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(filterDolnaHranicaVekovaSkupinaPocet, filterHornaHranicaVekovaSkupinaPocet, getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
            filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJVekovaSkupinaPocet);
        }
        filterAND->registeredFilter((Filter<UzemnaJednotka>*)filterUJPrislusnost);


        for (auto item : *vsetkyUzemneJednotky)
        {
            if (filterAND->pass(vsetkyUzemneJednotky->find(item->accessData()->getOfficialTitle())))
            {
                std::cout << item->accessData()->getOfficialTitle() << std::endl;
                filterTypUnsorted->insert(item->accessData()->getOfficialTitle(), item->accessData());
            }
        }

        system("CLS");

        if (secondfilterChoice == 1)
        {
            QuickSort<std::string, UzemnaJednotka*>* filterTypQuickSort = new QuickSort<std::string, UzemnaJednotka*>(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
            filterTypQuickSort->sort(*filterTypUnsorted);
            if (stylSortovania == 2)
            {
                int index = filterTypUnsorted->size();
                Array<UzemnaJednotka*>* zostupnePole = new Array<UzemnaJednotka*>(filterTypUnsorted->size());
                for (auto item : *filterTypUnsorted) {
                    zostupnePole->at(index - 1) = item->accessData();
                    index--;
                }
                KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
                for (size_t i = 0; i < zostupnePole->size(); i++)
                {
                    double pocetVek = kriteriumUJVekPodiel->evaluate(zostupnePole->at(i));
                    std::cout << zostupnePole->at(i)->getOfficialTitle() << " " << std::to_string(pocetVek) << std::endl;
                }
                delete kriteriumUJVekPodiel;
                delete zostupnePole;
            }
            if (stylSortovania == 1)
            {
                KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(filterVekPodielVek, getTypPohlaviaIndex(filterTypVzdelavanieVekPodiel));
                for (auto item : *filterTypUnsorted)
                {
                    double pocetVek = kriteriumUJVekPodiel->evaluate(item->accessData());
                    std::cout << item->accessData()->getOfficialTitle() << " " << std::to_string(pocetVek) << std::endl;
                }
                delete kriteriumUJVekPodiel;
            }
            delete filterTypQuickSort;
        }
        else if (secondfilterChoice == 2)
        {
            QuickSortVekSkup<std::string, UzemnaJednotka*>* filterTypQuickSort = new QuickSortVekSkup<std::string, UzemnaJednotka*>(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
            filterTypQuickSort->sort(*filterTypUnsorted);
            if (stylSortovania == 2)
            {
                int index = filterTypUnsorted->size();
                Array<UzemnaJednotka*>* zostupnePole = new Array<UzemnaJednotka*>(filterTypUnsorted->size());
                for (auto item : *filterTypUnsorted) {
                    zostupnePole->at(index - 1) = item->accessData();
                    index--;
                }
                KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
                for (size_t i = 0; i < zostupnePole->size(); i++)
                {
                    int pocetVekSkup = kriteriumUJVekovaSkupinaPocet->evaluate(zostupnePole->at(i));
                    std::cout << zostupnePole->at(i)->getOfficialTitle() << " " << std::to_string(pocetVekSkup) << std::endl;
                }
                delete kriteriumUJVekovaSkupinaPocet;
                delete zostupnePole;
            }
            if (stylSortovania == 1)
            {
                KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(getTypVekovejSkupinyIndex(filterTypVekovaSkupinaPocet));
                for (auto item : *filterTypUnsorted)
                {
                    int pocetVekSkup = kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData());
                    std::cout << item->accessData()->getOfficialTitle() << " " << std::to_string(pocetVekSkup) << std::endl;
                }
                delete kriteriumUJVekovaSkupinaPocet;
            }
            delete filterTypQuickSort;
        }
        else {
            for (auto item : *filterTypUnsorted)
            {
                std::cout << item->accessData()->getOfficialTitle() << std::endl;
            }
        }

        delete filterTypUnsorted;
        delete filterAND;
        delete filterUJPrislusnost;
        break;
    }

    default:
        break;
    }
}

void vyberoveKriteria() {
    system("CLS");
    std::string inputNazov;
    int filter;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << " Zadajte filter, ktorý chcete aplikovat (1-2)" << std::endl;
    std::cout << "  1.FilterUJTyp" << std::endl;
    std::cout << "  2.FilterUJPrislusnost" << std::endl;
    std::cout << "Odpoved: ";
    std::cin >> filter;

    system("CLS");
    std::cout << "-----------------------------------------------------" << std::endl;

    switch (filter)
    {
    case 1: {
        UnsortedSequenceTable<int, UzemnaJednotka*>* filterTypUnsorted = new  UnsortedSequenceTable<int, UzemnaJednotka*>();
        int filterUJTypChoice;
        int secondfilterChoice;
        std::cout << " Zadajte TypUzemnejJednotky pre filter: filterUJTyp" << std::endl;
        std::cout << "  1.KRAJ" << std::endl;
        std::cout << "  2.OKRES" << std::endl;
        std::cout << "  3.OBEC" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> filterUJTypChoice;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Ktoru z hodnot chcete otestovat ? " << std::endl;
        std::cout << "  1.NajmensiaVekovaSkupina" << std::endl;
        std::cout << "  2.NajvacsieVekovaSkupina" << std::endl;
        std::cout << "  3.Ziadne" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> secondfilterChoice;

        FilterUJTyp* filterUJTyp = new FilterUJTyp(getTypUzemnejJednotkyIndex(filterUJTypChoice));

        std::cout << "-----------------------------------------------------" << std::endl;
        int getTypvekSkup;
        std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
        std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
        std::cout << "  2.PRODUKTIVNY" << std::endl;
        std::cout << "  3.POPRODUKTIVNY" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> getTypvekSkup;

        int pocet = 1;
        for (auto item : *vsetkyUzemneJednotky)
        {
            if (item->accessData()->getTypUzemnehoCelku() == getTypUzemnejJednotkyIndex(filterUJTypChoice))
            {    
                if (filterUJTyp->pass(vsetkyUzemneJednotky->find(item->accessData()->getOfficialTitle())))
                {
                    filterTypUnsorted->insert(pocet++, item->accessData());
                }
            }
        }

        system("CLS");

        if (secondfilterChoice == 1)
        {
            SelectionKriteriumMinimum* minVS = new SelectionKriteriumMinimum(getTypVekovejSkupinyIndex(getTypvekSkup));
            UzemnaJednotka* jednotka1 = minVS->selectBest(filterTypUnsorted);
            std::cout << jednotka1->getOfficialTitle() << std::endl;
            std::cout << " " << std::endl;
            if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ) {
                std::cout << "TypUzemnejJednotky: KRAJ" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES) {
                std::cout << "TypUzemnejJednotky: OKRES" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka1->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC) {
                std::cout << "TypUzemnejJednotky: OBEC" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->OKRES: " << jednotka1->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka1->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            std::cout << "-----------------------------------------------------" << std::endl;
            delete minVS;
        }
        else if (secondfilterChoice == 2) {
            SelectionKriteriumMaximum* maxVS = new SelectionKriteriumMaximum(getTypVekovejSkupinyIndex(getTypvekSkup));
            UzemnaJednotka* jednotka2 = maxVS->selectBest(filterTypUnsorted);
            std::cout << jednotka2->getOfficialTitle() << std::endl;
            std::cout << " " << std::endl;
            if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ) {
                std::cout << "TypUzemnejJednotky: KRAJ" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES) {
                std::cout << "TypUzemnejJednotky: OKRES" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka2->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC) {
                std::cout << "TypUzemnejJednotky: OBEC" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->OKRES: " << jednotka2->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka2->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            std::cout << "-----------------------------------------------------" << std::endl;
            delete maxVS;
        }


        delete filterTypUnsorted;
        delete filterUJTyp;
        break;
    }
    case 2: {
        UnsortedSequenceTable<int, UzemnaJednotka*>* filterTypUnsorted = new  UnsortedSequenceTable<int, UzemnaJednotka*>();
        system("CLS");
        std::string nazovUzemnejJednotky;
        int getTypvekSkup;

        std::cout << " Zadajte nazov vysiej uzemnej jednotky" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nazovUzemnejJednotky);
        system("CLS");

        int secondfilterChoice;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << " Ktoru z hodnot chcete otestovat ? " << std::endl;
        std::cout << "  1.NajmensiaVekovaSkupina" << std::endl;
        std::cout << "  2.NajvacsieVekovaSkupina" << std::endl;
        std::cout << "  3.Ziadne" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> secondfilterChoice;

        std::cout << "-----------------------------------------------------" << std::endl;
        FilterUJPrislusnost* filterUJPrislusnost = new FilterUJPrislusnost(vsetkyUzemneJednotky->find(nazovUzemnejJednotky));
        

        std::cout << " Zadajte typVekovejSkupiny (1-3)" << std::endl;
        std::cout << "  1.PREDPRODUKTIVNY" << std::endl;
        std::cout << "  2.PRODUKTIVNY" << std::endl;
        std::cout << "  3.POPRODUKTIVNY" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> getTypvekSkup;
        std::cout << "-----------------------------------------------------" << std::endl;

        int pocet = 1;
        for (auto item : *vsetkyUzemneJednotky)
        {
            if (filterUJPrislusnost->pass(vsetkyUzemneJednotky->find(item->accessData()->getOfficialTitle())))
            {
                filterTypUnsorted->insert(pocet++, item->accessData());
            }
        }

        system("CLS");
        if (secondfilterChoice == 1)
        {
            SelectionKriteriumMinimum* minVS = new SelectionKriteriumMinimum(getTypVekovejSkupinyIndex(getTypvekSkup));
            UzemnaJednotka* jednotka1 = minVS->selectBest(filterTypUnsorted);
            std::cout << jednotka1->getOfficialTitle() << std::endl;
            std::cout << " " << std::endl;
            if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ) {
                std::cout << "TypUzemnejJednotky: KRAJ" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES) {
                std::cout << "TypUzemnejJednotky: OKRES" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka1->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka1->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC) {
                std::cout << "TypUzemnejJednotky: OBEC" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->OKRES: " << jednotka1->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka1->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            std::cout << "-----------------------------------------------------" << std::endl;
            delete minVS;
        }
        else if (secondfilterChoice == 2) {
            SelectionKriteriumMaximum* maxVS = new SelectionKriteriumMaximum(getTypVekovejSkupinyIndex(getTypvekSkup));
            UzemnaJednotka* jednotka2 = maxVS->selectBest(filterTypUnsorted);
            std::cout << jednotka2->getOfficialTitle() << std::endl;
            std::cout << " " << std::endl;
            if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ) {
                std::cout << "TypUzemnejJednotky: KRAJ" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES) {
                std::cout << "TypUzemnejJednotky: OKRES" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka2->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            else if (jednotka2->getTypUzemnehoCelku() == TypUzemnejJednotky::OBEC) {
                std::cout << "TypUzemnejJednotky: OBEC" << std::endl;
                std::cout << "patriDoUzemnejJednotky ->OKRES: " << jednotka2->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJ: " << jednotka2->getVyssiaUzemnaJednotka()->getVyssiaUzemnaJednotka()->getOfficialTitle() << std::endl;
                std::cout << "patriDoUzemnejJednotky ->KRAJINA: " << "Slovakia" << std::endl;
            }
            std::cout << "-----------------------------------------------------" << std::endl;
            delete maxVS;
        }


        delete filterTypUnsorted;  
        delete filterUJPrislusnost;
        break;
    }

    default:
        break;
    }
}

void userInterfaceIntroduction() {
    system("CLS");
    bool running = true;
    std::string choice;
    while (running) {
    system("CLS");
    std::cout << " Vyberte možnos, ktorú chcete testova." << std::endl;
    std::cout << "  1.Test Kriterií" << std::endl;
    std::cout << "  2.Test Filtrov" << std::endl;
    std::cout << "  3.Bodove Vyhladavanie" << std::endl;
    std::cout << "  4.Aplikácia Filtrov" << std::endl;
    std::cout << "  5.Triedenie" << std::endl;
    std::cout << "  6.Vyberove Kriterium" << std::endl;
    std::cout << "  7.Ukonèi program" << std::endl;
        std::cout << "Odpoved: ";
        std::cin >> choice;
       
        switch (atoi(choice.c_str()))
        {
        case 1:
            testKriteria();
            break;
        case 2:
            testFiltre();
            break;
        case 3:
            bodoveVyhladavanie();
            break;
        case 4:
            aplikaciaFiltrov();
            break;
        case 5:
            triedenie();
            break;
        case 6:
            vyberoveKriteria();
            break;
        case 7:
            running = false;
            break;
        default:
            std::cout << " Zadali ste nespravnu možnos. Skúste znovu." << std::endl;
            break;
        }
        if (running)
        {
            std::string ukoncenie;
            std::cout << " ----------------------------------------------------" << std::endl;
            std::cout << " Chcete sa vratit ku možnostiam testovania operacii ?" << std::endl;
            std::cout << "  1.Ano" << std::endl;
            std::cout << "  2.Nie - Ukonèi aplikáciu" << std::endl;
            std::cout << "  Odpoved: ";
            std::cin >> ukoncenie;
            if (atoi(ukoncenie.c_str()) == 1)
            {
                running = true;
            }
            else {
                running = false;
            }
        }
    }
}

void userInterfaceVstup() {
    Vstup* vstup = new Vstup("cvs/kraje.csv", "cvs/okresy.csv", "cvs/obce.csv", "cvs/vek.csv", "cvs/vzdelanie.csv");
    system("CLS");
    std::cout << " Vyberte jednu z nasledujúcich možností.(1, 2)" << std::endl;
    std::cout << "  1.Naèita súbory" << std::endl;
    std::cout << "  2.Ukonèi program" << std::endl;
    std::string introduction;
    bool running = true;
    while(running) {
        std::cout << "Odpoved: ";
        std::cin >>  introduction;
        switch (atoi(introduction.c_str()))
        {
        case 1: 
            system("CLS");
            vstup->nacitajSubory();
            vsetkyUzemneJednotky->assign(*vstup->getVsetkyUzemneJednotky());
            running = false;
            userInterfaceIntroduction();
            break;
        case 2:
            running = false;
            break;
        default:
            std::cout << " Zadali ste nespravnu možnos. Skúste znovu." << std::endl;
            break;
        }
    }
    delete vstup;
}

int main()
{
    initHeapMonitor();
    SetConsoleOutputCP(1250);
    SetConsoleCP(1250);
    setlocale(LC_ALL, "slovak");

    userInterfaceVstup();

    delete vsetkyUzemneJednotky;
    vsetkyUzemneJednotky = nullptr;
    return 0;
}
