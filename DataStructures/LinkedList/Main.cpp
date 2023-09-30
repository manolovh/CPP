#include <iostream>
#include "LinkedList.hpp"

int main()
{
	Node linked_list = Node ( 5 );
	Node* node_ptr = &linked_list;
	for (int i = 6; i < 10; i++)
	{
		node_ptr->next = new Node( i );
		node_ptr = node_ptr->next;
	}

	LinkedList l;
	l.display(&linked_list);
	l.display_backwards(&linked_list);
}