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
	Node* main_node;
	void display();
	void display_backwards(Node* node);

	int get_node_count();
	int get_sum();

	int get_max();
	
	Node* search(int x);
	Node* search2(int x);

	void insert(int idx, int x);
};