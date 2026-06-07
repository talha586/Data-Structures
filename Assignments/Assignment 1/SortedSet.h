#pragma once
#include "SinglyLinkedList.h"

template<typename T>
class SortedSet
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	SortedSet();
	void insert(T val);
	void print();
	void delete_node(int index);
	int getlength();
	void unionSets(SortedSet<T>& other);
};

template<typename T>
SortedSet<T>::SortedSet():head(nullptr),tail(nullptr) {}

template<typename T>
void SortedSet<T>:: insert(T val)
{
	Node<T>* n1 = new Node<T>(val);

	if (head==nullptr)
	{
		head = n1;
		tail = n1;
		return;
	}

	Node<T>* temp = head;

	while (temp!=nullptr)
	{
		if (temp->data==val)
		{
			return;
		}
		temp = temp->next;
	}

	temp = head;

	if (head==tail)
	{
		if (val>temp->data)
		{
			temp->next = n1;
			tail = n1;
			return;
		}

		n1->next = temp;
		head = n1;

		return;
	}

	if (val < head->data)
	{
		n1->next = head;
		head = n1;
		return;
	}

	if (val>tail->data)
	{
		while (temp->next!=nullptr)
		{
			temp = temp->next;
		}
		temp->next = n1;
		tail = n1;
		return;
	}

	while (temp->next!=nullptr)
	{
		if (n1->data > temp->data && n1->data < temp->next->data)
		{
			Node<T>* rand = temp->next;
			n1->next = rand;
			temp->next = n1;
		}

		temp = temp->next;
	}
}

template<typename T>
void SortedSet<T>::print()
{
	if (head==nullptr)
	{
		cout << "No Nodes" << endl;
		return;
	}

	Node<T>* temp = head;
	
	while (temp!=nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return;
}

template<typename T>
int SortedSet<T>::getlength()
{
	int counter = 1;

	if (head == nullptr)
	{
		cout << "Zero length" << endl;
		return 0;
	}

	Node<T>* temp = head;

	while (temp != tail)
	{
		counter++;
		temp = temp->next;
	}

	return counter;
}

template<typename T>
void SortedSet<T>:: delete_node(int index)
{

	if (index<=0 || index>getlength())
	{
		cout << "Index Out of Bound" << endl;
		return;
	}

	Node<T>* temp = head;
	
	if (index==1)
	{
		Node<T>* rand = temp->next;
		head = rand;
		temp->next = nullptr;
		delete temp;
		return;
	}

	if (index==getlength())
	{
		while (temp->next!=tail)
		{
			temp = temp->next;
		}
		Node<T>* rand = temp->next;
		tail = temp;
		temp->next = nullptr;
		delete rand;
		return;
	}

	for (int i=0;i<index-1;i++)
	{
		temp = temp->next;
	}

	Node<T>* rand = temp->next;
	Node<T>* rand2 = rand->next;
	temp->next = rand2;
	rand->next = nullptr;
	delete rand;
	return;
}

template<typename T>
void SortedSet<T> :: unionSets(SortedSet<T> &other)
{
	Node<T>* temp = other.head;

	while (temp!=nullptr)
	{
		insert(temp->data);
		temp = temp->next;
	}
	return;
}