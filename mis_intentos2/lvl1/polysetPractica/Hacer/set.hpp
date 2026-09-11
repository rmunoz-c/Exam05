#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &_bag;

	public:
		set(searchable_bag &bag);
		set(const set &other);
		set &operator=(const set &other);
		~set();

		void insert(int i);
		void insert(int *array, int size);
		void print() const;
		void clear();
		bool has(int i);
		searchable_bag &get_bag();

};

#endif