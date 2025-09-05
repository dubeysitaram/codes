// linkedlist.cpp
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		this->data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
};