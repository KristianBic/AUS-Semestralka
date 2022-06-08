#pragma once
#include "FilterWithKriterium.h"

template<typename O, typename R>
class FilterFII : public FilterWithKriterium<O, R>
{
public:
	FilterFII(Kriterium<O, R>* kriterium, R valueMin, R valueMax) : 
		FilterWithKriterium<O, R>(kriterium), valueMin_(valueMin), valueMax_(valueMax) {}
protected:
	bool passFilter(R value) { return value >= valueMin_ && value <= valueMax_; }
private:
	R valueMin_;
	R valueMax_;
};
