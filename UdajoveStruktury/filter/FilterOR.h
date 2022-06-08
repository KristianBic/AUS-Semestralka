#pragma once
#include "CompositeFilter.h"

template<typename O>
class FilterOR : public CompositeFilter<O>
{
public:
	bool pass(O* objekt) override;
};

template<typename O>
inline bool FilterOR<O>::pass(O* objekt)
{
	for (auto item : *this->filters_) {
		if (item->pass(objekt)) return true;
	}
	return false;
}
