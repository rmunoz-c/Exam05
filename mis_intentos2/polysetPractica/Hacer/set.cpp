#include "set.hpp"

set::set(searchable_bag &bag) : _bag(bag)
{

}

set::set(const set &other) : _bag(other._bag)
{

}

set &set::operator=(const set &other)
{
	this->_bag = other._bag;
	return(*this);
}

set::~set()
{

}

void set::insert(int i)
{
	if (!_bag.has(i))
		_bag.insert(i);
}

void set::insert(int *array, int size)
{
	int i;
	i = 0;

	while (i < size)
	{
		if (!_bag.has(array[i]))
			_bag.insert(array[i]);
		i++;
	}
}

void set::print()const
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

bool set::has(int i)
{
	return(_bag.has(i));
}

searchable_bag &set::get_bag()
{
	return(_bag);
}