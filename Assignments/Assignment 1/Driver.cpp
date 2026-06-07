#include "Node.h"
#include "SinglyLinkedList.h"
#include "SortedSet.h"

int main()
{
	SortedSet<int> s;
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(10);
	s.insert(50);
	cout<<"First Linked List: ";
	s.print();
	cout << endl;
	SortedSet<int>s1;
	s1.insert(0);
	s1.insert(1);
	s1.insert(11);
    cout << "Second Linked List: ";
	s1.print();
	cout << endl;
	s.unionSets(s1);
	cout << "Union of two linked list: ";
	s.print();
	cout << endl;
	s.delete_node(2);
	cout << "After Deletion: ";
	s.print();
}
