#pragma once
#include "Filter.h"

template<typename O, typename R>
class FilterWithKriterium : public Filter<O>
{
public:
	~FilterWithKriterium() { delete kriterium_; };
	FilterWithKriterium(Kriterium<O, R>* kriterium) : kriterium_(kriterium) {}
	bool pass(O* objekt) override { return passFilter(kriterium_->evaluate(objekt)); }
protected:
	virtual bool passFilter(R value) = 0;
private:
	Kriterium<O, R>* kriterium_;
};

