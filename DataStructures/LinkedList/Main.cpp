#include <iostream>
#include "LinkedList.hpp"

void f1()
{
	Node linked_list = Node(5);
	Node* node_ptr = &linked_list;
	for (int i = 6; i < 10; i++)
	{
		node_ptr->next = new Node(i);
		node_ptr = node_ptr->next;
	}

	LinkedList l;

	l.main_node = &linked_list;
	l.display();

	l.display_backwards(&linked_list);

	l.main_node = &linked_list;
	std::cout << l.get_node_count() << std::endl;

	l.main_node = &linked_list;
	std::cout << l.get_sum() << std::endl;

	l.main_node = &linked_list;
	std::cout << l.get_max() << std::endl;
}

void f2()
{
	Node linked_list = Node(5);
	Node* node_ptr = &linked_list;
	for (int i = 6; i < 10; i++)
	{
		node_ptr->next = new Node(i);
		node_ptr = node_ptr->next;
	}

	LinkedList l;

	l.main_node = &linked_list;
	Node* found = l.search2(7);

	l.main_node = found;
	l.display();

	l.main_node = found;
	Node* found2 = l.search2(8);

	l.main_node = found2;
	l.display();
}

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

	l.main_node = &linked_list;
	l.insert(2, 10);

	l.display();

	l.main_node = &linked_list;
	l.insert(0, 15);

	l.display();
}
