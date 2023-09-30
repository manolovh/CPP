#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#endif

struct Node
{
	int value;
	Node* next;

	Node(int val)
	{
		value = val;
		next = nullptr;
	}
};

class LinkedList
{
public:
	void display(Node* node);
	void display_backwards(Node* node);
};