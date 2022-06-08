#pragma once
#include "FilterFi.h"
#include "../structures/list/array_list.h"

template<typename O>
class CompositeFilter : public Filter<O>
{
protected:
	structures::ArrayList<Filter<O>*>* filters_ = new structures::ArrayList<Filter<O>*>();
public:
	~CompositeFilter();
	void registeredFilter(Filter<O>* filter) { filters_->add(filter); }
};

template<typename O>
inline CompositeFilter<O>::~CompositeFilter()
{
	delete filters_;
	filters_ = nullptr;
}
