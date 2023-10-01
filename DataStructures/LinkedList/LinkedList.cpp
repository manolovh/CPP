#include <iostream>
#include "LinkedList.hpp"

void LinkedList::display()
{
	while (main_node)
	{
		std::cout << main_node->value << " -> ";
		main_node = main_node->next;
	}
	std::cout << "NULL\n";
}

void LinkedList::display_backwards(Node *node)
{
	if (node)
	{
		display_backwards(node->next);
		std::cout << node->value << std::endl;
	}
}

int LinkedList::get_node_count()
{
	int count = 0;
	while (main_node)
	{
		count++;
		main_node = main_node->next;
	}
	return count;
}

int LinkedList::get_sum()
{
	int sum = 0;
	while (main_node)
	{
		sum += main_node->value;
		main_node = main_node->next;
	}
	return sum;
}

int LinkedList::get_max()
{
	int max_value = -10000000;

	while (main_node)
	{
		if (main_node->value > max_value)
		{
			max_value = main_node->value;
		}

		main_node = main_node->next;
	}
	return max_value;
}

Node* LinkedList::search(int x)
{
	while (main_node)
	{
		if (main_node->value == x)
		{
			return main_node;
		}

		main_node = main_node->next;
	}
	return nullptr;
}

Node* LinkedList::search2(int x)
{
	Node* p = main_node;
	Node* q = nullptr;

	while (p)
	{
		if (p->value == x)
		{
			q->next = p->next;
			p->next = main_node;
			main_node = p;
			return p;
		}
		q = p;
		p = p->next;
	}

	return nullptr;
}

void LinkedList::insert(int idx, int x)
{
	Node* p = main_node;
	Node* q = nullptr;
	Node* r = new Node(x);
	int count = 1;

	if (idx == 0)
	{
		r->next = p;
		main_node = r;
	}
	else
	{
		while (p)
		{
			if (count != idx) {
				count++;
			}
			else
			{
				Node* temp = p->next;
				p->next = r;
				r->next = temp;
				break;
			}
			p = p->next;
		}

	}
}