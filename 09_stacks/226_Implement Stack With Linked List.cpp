// 226_Implement Stack With Linked List.cpp

/*
Problem statement
You must implement the Stack data structure using a Singly Linked List.



Create a class named 'Stack' which supports the following operations(all in O(1) time):



getSize: Returns an integer. Gets the current size of the stack

isEmpty: Returns a boolean. Gets whether the stack is empty

push: Returns nothing. Accepts an integer. Puts that integer at the top of the stack

pop: Returns nothing. Removes the top element of the stack. It does nothing if the stack is empty.

getTop: Returns an integer. Gets the top element of the stack. Returns -1 if the stack is empty

*/


/****************************************************************

    Following is the class structure of the Node class:

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


***************************************************************** we are constructing the reversed linked list/

class Stack
{
	//Write your code here

public:
	Node* temp;
	int size;
	Stack()
	{
		//Write your code here
		temp = NULL;
		size = 0;
	}

	int getSize()
	{
		//Write your code here
		return size;
	}

	bool isEmpty()
	{
		//Write your code here
		return size == 0;
	}

	void push(int data)
	{
		//Write your code here
		Node* node =  new Node(data);
		node->next = temp;
		temp = node;
		size++;
	}

	void pop()
	{
		//Write your code here
		if (size == 0)return;
		size--;
		Node* x = temp;
		temp = temp->next;
		delete(x);
	}

	int getTop()
	{
		//Write your code here
		if (size == 0)return -1;
		return temp->data;
	}
};