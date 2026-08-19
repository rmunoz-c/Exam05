#ifndef SET_HPP
# define SET_HPP

#include "../Dan/searchable_bag.hpp"

class set
{
	private:
		searchable_bag &_bag;
	public:
		set(searchable_bag &bag);
		set(const set &other);
		set &operator=(const set &other);
		~set();

		virtual void insert(int i);
		virtual void insert(int *array, int size);
		virtual void print() const;
		virtual void clear();
		bool has(int index);
		searchable_bag &get_bag();
};

#endif