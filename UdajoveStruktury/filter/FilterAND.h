#pragma once
#include "CompositeFilter.h"

template<typename O>
class FilterAND : public CompositeFilter<O>
{
public:
	bool pass(O* objekt) override;
};

template<typename O>
inline bool FilterAND<O>::pass(O* objekt)
{

	for (auto item : *this->filters_)
	{
		if (!item->pass(objekt)) return false;
	}
	return true;
	
};
	/*
	int pocetSplnenychTestov = 0;
	for (auto item : *this->filters_) {
		if (item->pass(objekt)) pocetSplnenychTestov++;
	}
	if (this->filters_->size() == pocetSplnenychTestov) return true;
	return false;
	*/

