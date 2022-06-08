#pragma once
#include "../classes/UzemnaJednotka.h"
#include "../kriterium/KriteriumUJVekovaSkupinaPocet.h"

class SelectionKriteriumMinimum
{
public:
	SelectionKriteriumMinimum(TypVekovejSkupiny typ);
	~SelectionKriteriumMinimum();
	bool isTestedValueBatter(int bestNow, int bestTested) { return bestTested < bestNow; }
	UzemnaJednotka* selectBest(structures::Table<int, UzemnaJednotka*>* table);
private:
	TypVekovejSkupiny typ_;
	KriteriumUJVekovaSkupinaPocet* kriterium_;
};


inline SelectionKriteriumMinimum::SelectionKriteriumMinimum(TypVekovejSkupiny typ) {
	typ_ = typ;
	kriterium_ = new KriteriumUJVekovaSkupinaPocet(typ_);
}

inline SelectionKriteriumMinimum::~SelectionKriteriumMinimum()
{
	delete kriterium_;
}

inline UzemnaJednotka* SelectionKriteriumMinimum::selectBest(structures::Table<int, UzemnaJednotka*>* table)
{
	UzemnaJednotka* bestSelectedObject = nullptr;
	bool first = true;
	int bestTested = 0;
	for (auto item : *table) {
		if (first)
		{
			bestSelectedObject = item->accessData();
			bestTested = this->kriterium_->evaluate(bestSelectedObject);
			first = false;
		}
		else
		{
			UzemnaJednotka* bestTestedObject = item->accessData();
			int bestNow = this->kriterium_->evaluate(bestTestedObject);
			if (isTestedValueBatter(bestTested, bestNow))
			{
				bestTested = bestNow;
				bestSelectedObject = bestTestedObject;
			}
		}
	}
	return bestSelectedObject;
}
