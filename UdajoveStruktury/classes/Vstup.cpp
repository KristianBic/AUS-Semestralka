#include "Vstup.h"

Vstup::Vstup(std::string nazovSuboru1, std::string nazovSuboru2, std::string nazovSuboru3, std::string nazovSuboru4, std::string nazovSuboru5) :
    nazovSuboru1_(nazovSuboru1), nazovSuboru2_(nazovSuboru2), nazovSuboru3_(nazovSuboru3), nazovSuboru4_(nazovSuboru4), nazovSuboru5_(nazovSuboru5)
{
    krajinaSlovensko = new Krajina("0", "Slovakia", "Slovakia", "SK", "0", nullptr);
    zoznamVzdelanie_ = new SortedSequenceTable<std::string, Vzdelanie*>();
    zoznamVekMuz_ = new SortedSequenceTable<std::string, Array<int>*>();
    zoznamVekZena_ = new SortedSequenceTable<std::string, Array<int>*>();
}

void Vstup::nacitajSubory()
{
    std::cout << " *** Citanie Suborov *** " << std::endl;
    citajSuborVzdelanie();
    citajSuborVek();
    citajSuborUzemnaJednotka(nazovSuboru1_);
    citajSuborUzemnaJednotka(nazovSuboru2_);
    citajSuborUzemnaJednotka(nazovSuboru3_);
    nacitanieVekovVzdelavaie();
}

void Vstup::nacitanieVekovVzdelavaie()
{
    std::cout << "-> Nacitanie Vekov " << std::endl;
    for (auto item : *vsetkyUzemneJednotky)
    {
        if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::OKRES)
        {
            item->accessData()->setVekMuzi();
            item->accessData()->setVekZeny();
            item->accessData()->setVzdelanie();
        }
    }
    for (auto item : *vsetkyUzemneJednotky)
    {
        if (item->accessData()->getTypUzemnehoCelku() == TypUzemnejJednotky::KRAJ)
        {
            item->accessData()->setVekMuzi();
            item->accessData()->setVekZeny();
            item->accessData()->setVzdelanie();
        }
    }
}


Vstup::~Vstup()
{

    delete krajinaSlovensko;
    krajinaSlovensko = nullptr;

    delete vsetkyUzemneJednotky;
    vsetkyUzemneJednotky = nullptr;

    
    for (auto item : *zoznamVzdelanie_)
    {
        delete item->accessData();
    }

    for (auto item : *zoznamVekMuz_)
    {
        delete item->accessData();
    }

    for (auto item : *zoznamVekZena_)
    {
        delete item->accessData();
    }
    
    delete zoznamVzdelanie_;
    zoznamVzdelanie_ = nullptr;
     
    delete zoznamVekMuz_;
    zoznamVekMuz_ = nullptr;
    
    delete zoznamVekZena_;
    zoznamVekZena_ = nullptr;
}

void Vstup::citajSuborVzdelanie()
{
    std::fstream file;
    std::string row;
    file.open(nazovSuboru5_);
    if (file.is_open())
    {
        std::getline(file, row);
        while (std::getline(file, row))
        {
            std::stringstream stlpec(row);
            std::string polozka;
            int umiestneniePolozky = 0;
            Array<int>* zoznamPoloziek = new Array<int>(8);

            std::getline(stlpec, polozka, ';');
            std::string code = polozka;
            std::getline(stlpec, polozka, ';');
            std::string title = polozka;

            while (std::getline(stlpec, polozka, ';'))
            {
                zoznamPoloziek->at(umiestneniePolozky) = atoi(polozka.c_str());
                umiestneniePolozky++;
            }
            zoznamVzdelanie_->insert(code, new Vzdelanie(zoznamPoloziek->at(0), zoznamPoloziek->at(1), zoznamPoloziek->at(2),
                zoznamPoloziek->at(3), zoznamPoloziek->at(4), zoznamPoloziek->at(5), zoznamPoloziek->at(6), zoznamPoloziek->at(7)));
           
            delete zoznamPoloziek;
            zoznamPoloziek = nullptr;
        }
    }
    std::cout << " -> vzdelavanie.cvs precitane " << std::endl;
    file.close();
}

void Vstup::citajSuborVek()
{
    std::fstream file;
    std::string row;
    file.open(nazovSuboru4_);
    if (file.is_open())
    {
        std::getline(file, row);
        while (std::getline(file, row))
        {
            std::stringstream stlpec(row);
            std::string polozka;
            int umiestneniePolozky = 0;
            Array<int>* zoznamPoloziekMuz = new Array<int>(101);
            Array<int>* zoznamPoloziekZena = new Array<int>(101);
            std::getline(stlpec, polozka, ';');
            std::string code = polozka;
            std::getline(stlpec, polozka, ';');
            std::string title = polozka;

            while (std::getline(stlpec, polozka, ';'))
            {
                if (umiestneniePolozky <= 100)
                {
                    zoznamPoloziekMuz->at(umiestneniePolozky) = atoi(polozka.c_str());
                    umiestneniePolozky++;
                }
                else
                {
                    zoznamPoloziekZena->at(umiestneniePolozky - 101) = atoi(polozka.c_str());
                    umiestneniePolozky++;
                }
            }
            zoznamVekMuz_->insert(code, zoznamPoloziekMuz);
            zoznamVekZena_->insert(code, zoznamPoloziekZena);
        }
    }
    std::cout << " -> vek.cvs precitane " << std::endl;
    file.close();
}


void Vstup::citajSuborUzemnaJednotka(std::string nazovSuboru)
{
    std::fstream file;
    std::string row;
    file.open(nazovSuboru);
    if (file.is_open())
    {
        std::getline(file, row);
        while (std::getline(file, row))
        {
            
            std::stringstream stlpec(row);
            std::string polozka;
            std::getline(stlpec, polozka, ';');
            int sortNumber = atoi(polozka.c_str());
            std::getline(stlpec, polozka, ';');
            std::string code = polozka;
            std::getline(stlpec, polozka, ';');
            std::string officialTitle = polozka;
            std::getline(stlpec, polozka, ';');
            std::string mediumTitle = polozka;
            std::getline(stlpec, polozka, ';');
            std::string shortTitle = polozka;
            std::getline(stlpec, polozka, ';');
            std::string note = polozka;
            
            Array<std::string*>* nazitanePolozky = new Array<std::string*>(5);
            nazitanePolozky->at(0) = new std::string(code);
            nazitanePolozky->at(1) = new std::string(officialTitle);
            nazitanePolozky->at(2) = new std::string(mediumTitle);
            nazitanePolozky->at(3) = new std::string(shortTitle);
            nazitanePolozky->at(4) = new std::string(note);

            if (nazovSuboru == nazovSuboru3_) { spracujUdaje(nazitanePolozky, 3); }
            else if (nazovSuboru == nazovSuboru2_) { spracujUdaje(nazitanePolozky, 2); }
            else if (nazovSuboru == nazovSuboru1_) { spracujUdaje(nazitanePolozky, 1); }
            else { throw std::runtime_error("Vstup.h, citajSuborUzemnaJednotka() -> Zly nazov suboru!"); }

            for (int i = 0; i < nazitanePolozky->size(); i++)
            {
                delete nazitanePolozky->at(i);
            }
            delete nazitanePolozky;
        }
    }
    if (nazovSuboru == nazovSuboru3_) { std::cout << " -> obec.cvs precitane " << std::endl; }
    else if (nazovSuboru == nazovSuboru2_) { std::cout << " -> okres.cvs precitane " << std::endl; }
    else if (nazovSuboru == nazovSuboru1_) { std::cout << " -> kraj.cvs precitane " << std::endl;}
    file.close();
}


void Vstup::spracujUdaje(Array<std::string*>* udaje, int spracovaneUdaje)
{
    switch (spracovaneUdaje)
    {
    case 1:
        //pridanie vsetkych krajov do Krajiny slovensko
        if (!krajinaSlovensko->getNizsieUzemneCelky()->containsKey(*udaje->at(0)))
        {
            Kraj* novyKraj = new Kraj(*udaje->at(0), *udaje->at(1), *udaje->at(2), *udaje->at(3), *udaje->at(4), krajinaSlovensko);
            krajinaSlovensko->pridajUzemnuJednotkuDoZoznamu(novyKraj);
            vsetkyUzemneJednotky->insert(*udaje->at(1), novyKraj);
        }
        break;
    case 2:
        //pridanie okresov do krajov
        UzemnaJednotka* kraj;
        for (size_t i = 1; i <= 9; i++)
        {
            krajinaSlovensko->getNizsieUzemneCelky()->tryFind(std::to_string(i), kraj);
            if (kraj->getNote().substr(5, 5) ==  udaje->at(0)->substr(0, 5))
            {
                if (!kraj->getNizsieUzemneCelky()->containsKey(*udaje->at(0)))
                {                
                    Okres* novyOkres = new Okres(*udaje->at(0), *udaje->at(1), *udaje->at(2), *udaje->at(3), *udaje->at(4), kraj);
                    kraj->pridajUzemnuJednotkuDoZoznamu(novyOkres);
                    vsetkyUzemneJednotky->insert(*udaje->at(1), novyOkres);
                }
            }
            else if (kraj->getNote().substr(0, 2) == udaje->at(0)->substr(2, 2))
            {
                if (!kraj->getNizsieUzemneCelky()->containsKey(*udaje->at(0)))
                {
                    Okres* novyOkres = new Okres(*udaje->at(0), *udaje->at(1), *udaje->at(2), *udaje->at(3), *udaje->at(4), kraj);
                    kraj->pridajUzemnuJednotkuDoZoznamu(novyOkres);
                    vsetkyUzemneJednotky->insert(*udaje->at(1), novyOkres);
                }
            }
        }
        break;
    case 3:
        //pridanie obci do okresov
        for (auto item : *krajinaSlovensko->getNizsieUzemneCelky()) {
            UzemnaJednotka* okres = nullptr;
            item->accessData()->getNizsieUzemneCelky()->tryFind((*udaje->at(0)).substr(0, 6), okres);
            if (okres != nullptr)
            {
                if (okres->getCode() == udaje->at(0)->substr(0, 6))
                {
                    if (!okres->getNizsieUzemneCelky()->containsKey(*udaje->at(0)))
                    {
                        Vzdelanie* zoznamVzdel = nullptr;
                        Array<int>* zoznamMuz = nullptr;
                        Array<int>* zoznamZena = nullptr;
                        zoznamVzdelanie_->tryFind(*udaje->at(0), zoznamVzdel);
                        zoznamVekMuz_->tryFind(*udaje->at(0), zoznamMuz);
                        zoznamVekZena_->tryFind(*udaje->at(0), zoznamZena);

                        Obec* novyObec = new Obec(*udaje->at(0), *udaje->at(1), *udaje->at(2), *udaje->at(3), *udaje->at(4), okres,
                            zoznamVzdel, zoznamMuz, zoznamZena);
                        okres->pridajUzemnuJednotkuDoZoznamu(novyObec);
                        vsetkyUzemneJednotky->insert(*udaje->at(1), novyObec);
                    }
                }
            }
        }
        break;
    default:
        throw std::runtime_error("Vstup.h, SpracujUdaje() -> Nespravny Parameter");
        break;
    }     
}
