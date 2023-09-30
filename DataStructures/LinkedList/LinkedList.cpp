#include <iostream>
#include "LinkedList.hpp"

void LinkedList::display(Node* node)
{
	while (node)
	{
		std::cout << node->value << std::endl;
		node = node->next;
	}
}

void LinkedList::display_backwards(Node* node)
{
	if (node)
	{
		display_backwards(node->next);
		std::cout << node->value << std::endl;
	}
}