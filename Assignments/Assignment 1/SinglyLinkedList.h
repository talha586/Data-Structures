#pragma once
#include "Node.h"
template<typename T>
class SinglyLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
public:

	SinglyLinkedList();
	void add_end(T val);
	void add_front(T val);
	void print();
	void delete_end();
	void delete_front();
	bool search(T val);
	void deleteAll();
	int get_length();
	void rotateleft(int k);
	//void removeDuplicate();
	void delete_value(int k);
	bool iscycle();
	void addNode_tail(int val);
	void separation();
	void sum_bw_nodes();
	void swap_nodes();

};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(): head(nullptr),tail(nullptr)
{}

template<typename T>
void SinglyLinkedList<T>::add_end(T val)
{
	Node<T>* n1 = new Node<T>(val);

	if (head==nullptr)
	{
		head = n1;
		tail = n1;
		return;
	}

	Node<T>* temp = head;

	if (head==tail)
	{
		temp->next = n1;
		tail = n1;
		return;
	}

	while (temp->next!=nullptr)
	{
		temp = temp->next;
	}

	temp->next = n1;
	tail = n1;
	return;
}

template<typename T>
void SinglyLinkedList<T>::add_front(T val)
{
	Node<T>* n1 = new Node<T>(val);

	if (head==nullptr)
	{
		head = n1;
		tail = n1;
		return;
	}

	Node<T>* temp = head;

	n1->next = temp;
	head = n1;
	return;
}

template<typename T>
void SinglyLinkedList<T> ::print()
{
	if (head == nullptr)
	{
		cout << "No Nodes" << endl;
		return;
	}

	Node<T>* temp = head;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	return;
}

template<typename T>
void SinglyLinkedList<T>::delete_end()
{
	if (head==nullptr)
	{
		cout << "No Node" << endl;
		return;
	}

	Node<T>* temp = head;

	if (head==tail)
	{	
		head = nullptr;
		tail = nullptr;
		delete temp;
		return;
	}

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

template <typename T>
void SinglyLinkedList<T> :: delete_value(int val)
{
	if (head==nullptr)
	{
		return;
	}

	Node<T>* temp = head;

	if (head==tail)
	{
		if (val==head->data)
		{
			delete temp;
			head = nullptr;
			tail = nullptr;
			return;
		}
	}

	while (temp->next!=nullptr)
	{
		if (temp->next->data==val)
		{
			Node<T>* rand = temp->next;
			temp->next = rand->next;
			if (rand==tail)
			{
				tail = temp;
			}
			delete rand;
		}
		temp = temp->next;
	}
}

template<typename T>
void SinglyLinkedList<T>::delete_front()
{
	if (head==nullptr)
	{
		cout << "No Node" << endl;
		return;
	}

	Node<T>* temp = head;

	if (head==tail)
	{
		head = nullptr;
		tail = nullptr;
		delete temp;
		return;
	}

	Node<T>* rand = temp->next;
	head = rand;
	delete temp;
	return;
}

template<typename T>
bool SinglyLinkedList<T>::search(T val)
{
	if (head==nullptr)
	{
		cout << "No Node" << endl;
	}
	
	Node<T>* temp = head;

	while (temp!=nullptr)
	{
		if (temp->data==val)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<typename T>
void SinglyLinkedList<T>::deleteAll()
{
	if (head==nullptr)
	{
		cout << "No Node to Delete" << endl;
		return;
	}

	Node<T>* temp = head;
	
	while (temp!=nullptr)
	{
		Node<T>* rand = temp;
		Node<T>* rand2 = temp->next;
		head = rand2;
		temp = temp->next;
		delete rand;
	}
	cout << "Delete All Values" << endl;
	return;
}

template<typename T>
int SinglyLinkedList<T>::get_length()
{
	int counter = 1;
	
	if (head==nullptr)
	{
		cout << "Zero length" << endl;
		return 0;
	}

	Node<T>* temp = head;

	while (temp!=tail)
	{
		counter++;
		temp = temp->next;
	}

	return counter;
}

template<typename T>
void SinglyLinkedList<T>::rotateleft(int k)//Left Shift
{
	if (head== nullptr || head==tail)
	{
		cout << "No rotation" << endl;
		return;
	}

	int times = k;

	Node<T>* temp = head;

	for (int i=0;i<times;i++)
	{
		temp = head;
		T data = head->data;
		while (temp->next!=nullptr)
		{
			temp->data = temp->next->data;
			temp = temp->next;
		}
		temp->data = data;
	}
	return;
}

//template<typename T>
//void SinglyLinkedList<T>::removeDuplicate()
//{
//
//	if (head==nullptr || head==tail)
//	{
//		return;
//	}
//
//	Node<T>* temp = head;
//
//	while (temp->next!=nullptr)
//	{
//		if (temp->data==temp->next->data)
//		{
//			delete_value(temp->next->data);
//		}
//		temp = temp->next;
//	}
//	return;
//}
template<typename T>
void SinglyLinkedList<T>::addNode_tail(int val)
{
	if (val<=0)
	{
		return;
	}

	Node<T>* temp = head;

	int i = 0;
	
	while (i<val)
	{
		temp = temp->next;
		i++;
	}

	tail->next = temp;
	return;
}

template<typename T>
bool SinglyLinkedList<T>::iscycle()
{
	
	if (head==nullptr || tail->next==nullptr)
	{
		return false;
	}

	Node<T>* temp = head;

	int i = 1;

	while (temp->next!=nullptr)
	{
		if (tail->next == temp)
		{
			return true;
		}
		temp = temp->next;
	}

	return false;
}

template<typename T>
void SinglyLinkedList<T>::separation()
{
	if (head==nullptr || head==tail)
	{
		return;
	}

	Node<T>* temp = head;
	Node<T>* rand2 = temp->next;
	Node<T>* rand = temp->next;

	while (temp->next!=nullptr && rand->next!=nullptr)
	{
		temp->next = temp->next->next;
		temp = temp->next;

		rand->next = rand->next->next;
		rand = rand->next;
	}

	temp->next = rand2;
}

template<typename T>
void SinglyLinkedList<T>::sum_bw_nodes()
{
	if (head==nullptr)
	{
		return;
	}

	if (head==tail)
	{
		cout << "The sum is 0" << endl;
		return;
	}

	Node<T>* temp = head;
	int sum = 0;
	while (temp->next!=nullptr)
	{
		sum = 0;
		while (temp->next->data!=0)
		{
			sum += temp->next->data;
			temp = temp->next;
		}
		cout << "The Sum is :" << sum << endl;
		temp = temp->next;
	}
}

template <typename T>
void SinglyLinkedList<T>::swap_nodes()
{
	if (head == nullptr || head==tail)
	{
		return;
	}

	Node<T>* temp = head;
	Node<T>* rand = temp->next;

	while (temp->next!=nullptr && rand->next!=nullptr)
	{
		T val = temp->data;
		temp->data = rand->data;
		rand->data = val;

		temp = rand->next;
		rand = temp->next;
	}

	if (get_length()%2==0)
	{
		T val = temp->data;
		temp->data = rand->data;
		rand->data = val;
	}
	
	return;
}

