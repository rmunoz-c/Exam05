#include "../Dan/searchable_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include "set.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;
	searchable_bag *t = new searchable_tree_bag;
	searchable_bag *a = new searchable_array_bag;

	for (int i = 1; i < argc; i++)
	{
		t->insert(atoi(argv[i]));
		a->insert(atoi(argv[i]));
	}
	t->print();
	a->print();
	std::cout << std::endl;

	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " en t: " <<  t->has(atoi(argv[i])) << std::endl;
		std::cout << argv[i] << " en a: " << a->has(atoi(argv[i])) << std::endl;
		std::cout << atoi(argv[i]) - 1 << " en t: " << t->has(atoi(argv[i]) - 1) << std::endl;
		std::cout << atoi(argv[i]) - 1 << " en a: " << a->has(atoi(argv[i]) - 1) << std::endl;
		std::cout << "-----------------------------\n";
	}

	t->clear();
	a->clear();

	const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
	tmp.print() ;
	tmp.has(1);

	set sa(*a);
	set st(*t);
	int arr[] = { 1, 2, 3, 4, };
	for (int i = 1; i < argc; i++)
	{
		st.insert(atoi(argv[i]));
		sa.insert(atoi(argv[i]));

		std::cout << "sa has " << atoi(argv[i]) << " --> " << sa.has(atoi(argv[i])) << std::endl;
		std::cout << "a printando su contenido: ", sa.print();
		std::cout << "la bag de sa printando su contenido: ", sa.get_bag().print();
		std::cout << "la bag de st printando su contenido: ", st.print();
		sa.clear();
		sa.insert(arr, 4);
		std::cout << std::endl;
	}
	return (0);
}