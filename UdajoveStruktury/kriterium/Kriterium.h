#pragma once
template<typename O, typename R>
class Kriterium
{
public:
	virtual R evaluate(O* objekt) = 0;
};