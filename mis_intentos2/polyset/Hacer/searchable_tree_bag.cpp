#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{

}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other)
{
	
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other) {
		destroy_tree(tree);
		tree = copy_node(other.tree);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
	tree_bag::~tree_bag();
}

bool searchable_tree_bag::has(int index) const
{
	node *current = tree;
	while (current != nullptr)
	{
		if (index < current->value)
			return (current->l);
		else if (index > current->value)
			return (current->r);
		else
			return (true);
	}
	return (false);
}