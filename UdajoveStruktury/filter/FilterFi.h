#pragma once
#include "FilterWithKriterium.h"

template<typename O, typename R>
class FilterFi : public FilterWithKriterium<O, R>
{
public:
	FilterFi(Kriterium<O, R>* kriterium, R value) : FilterWithKriterium<O, R>(kriterium), value_(value) {}
protected:
	bool passFilter(R value) { return value == value_; }
private:
	R value_;
};

