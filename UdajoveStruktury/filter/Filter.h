#pragma once
#include "../kriterium/Kriterium.h"

template<typename O>
class Filter
{
public:
	virtual bool pass(O* objekt) = 0;
};

