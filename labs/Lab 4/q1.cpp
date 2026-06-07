//#include<iostream>
//#include<cmath>
//using namespace std;
//
//template <typename T>
//class Node
//{
//public:
//    T data;
//    Node* next;
//    Node* prev;
//
//    Node(T val)
//    {
//        data = val;
//        next = nullptr;
//        prev = nullptr;
//    }
//};
//
//template <typename T>
//class DoublyLinkedList
//{
//    Node<T>* head;
//    Node<T>* tail;
//
//public:
//    DoublyLinkedList()
//    {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    void add_node(T val)
//    {
//        Node<T>* n1 = new Node<T>(val);
//
//        if (head == nullptr)
//        {
//            head = n1;
//            tail = n1;
//            return;
//        }
//
//        Node<T>* temp = head;
//
//        if (head == tail)
//        {
//            temp->next = n1;
//            tail = n1;
//            tail->prev = head;
//            return;
//        }
//
//        while (temp->next != nullptr)
//        {
//            temp = temp->next;
//        }
//        temp->next = n1;
//        n1->prev = temp;
//        tail = n1;
//    }
//
//    void remove()
//    {
//        if (head == nullptr)
//        {
//            cout << "No Node exist" << endl;
//            return;
//        }
//
//        if (head == tail)
//        {
//            delete head;
//            head = nullptr;
//            tail = nullptr;
//            return;
//        }
//
//        Node<T>* random = tail;
//        tail = random->prev;
//        tail->next = nullptr;
//        delete random;
//    }
//
//    void reverseLinkList()
//    {
//        if (head == nullptr)
//        {
//            cout << "No Reverse" << endl;
//            return;
//        }
//
//        if (head == tail)
//        {
//            cout << "There is only one Node" << endl;
//            return;
//        }
//
//        Node<T>* temp = head;
//        Node<T>* rand = nullptr;
//
//        while (temp != nullptr)
//        {
//            rand = temp->prev;
//            temp->prev = temp->next;
//            temp->next = rand;
//            temp = temp->prev;
//        }
//
//        rand = head;
//        head = tail;
//        tail = rand;
//    }
//
//    void isMyPalindrome()
//    {
//        Node<T>* temp1 = head;
//        Node<T>* temp2 = tail;
//
//        bool flag=false;
//        while (temp1!=temp2)
//        {
//            int diff = temp1->data - temp2->data;
//            diff = abs(diff);
//            if (diff<7)
//            {
//                temp1 = temp1->next;
//                temp2 = temp2->prev;
//                flag = true;
//            }
//            else
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag==true)
//        {
//            cout << "is MyPalindrome" << endl;
//        }
//        else
//        {
//            cout << "No MyPalindrome" << endl;
//        }
//        return;
//    }
//
//    int getlength()
//    {
//        Node<T>* temp = head;
//        int length = 0;
//        while (temp!=nullptr)
//        {
//            length++;
//            temp = temp->next;
//        }
//        return length;
//    }
//
//    //void reorderList() {
//    //    if (head == nullptr)
//    //    {
//    //        return;
//    //    }
//
//    //    Node<T>* slow = head;
//    //    Node<T>* fast = head;
//
//    //    while (fast->next && fast->next->next)
//    //    {
//    //        slow = slow->next;
//    //        fast = fast->next->next;
//    //    }
//
//    //    Node<T>* second = slow->next;
//    //    slow->next = nullptr;
//
//    //    if (second)
//    //    {
//    //        second->prev = nullptr;
//    //    }
//    //    second = reverseList(second);
//
//    //    Node<T>* first = head;
//    //    while (first && second)
//    //    {
//    //        Node<T>* fnext = first->next;
//    //        Node<T>* snext = second->next;
//
//    //        first->next = second;
//    //        second->prev = first;
//
//    //        if (fnext) 
//    //        {
//    //            second->next = fnext;
//    //            fnext->prev = second;
//    //        }
//
//    //        first = fnext;
//    //        second = snext;
//    //    }
//
//    //    tail = head;
//    //    while (tail->next)
//    //    {
//    //        tail = tail->next;
//    //    }
//    //}
//
//    void swapNodes(int n)
//    {
//            int length = getlength();
//
//            if (n > length || n <= 0)
//            {
//                cout << "Invalid Input" << endl;
//                return;
//            }
//            if (head == nullptr || head == tail)
//            {
//                cout << "Head and Tail at same point" << endl;
//                return;
//            }
//
//            Node<T>* temp = head;
//
//            for (int i = 1; i < n; i++)
//            {
//                temp = temp->next;
//            }
//            Node<T>* rand = head;
//            for (int i = 1; i < length - n + 1; i++)
//            {
//                rand = rand->next;
//            }
//
//            if (temp == rand)
//            {
//                return;
//            }
//            Node<T>* temp_Prev1 = temp->prev;
//            Node<T>* temp_next1 = temp->next;
//            Node<T>* rand_prev1 = rand->prev;
//            Node<T>* rand_next2 = rand->next;
//
//            if (temp->next == rand)
//            {
//                if (temp_Prev1) temp_Prev1->next = rand;
//                if (rand_next2) rand_next2->prev = temp;
//
//                rand->prev = temp_Prev1;
//                temp->next = rand_next2;
//
//                rand->next = temp;
//                temp->prev = rand;
//            }
//            
//            else if (rand->next == temp)
//            {
//                if (rand_prev1) rand_prev1->next = temp;
//                if (temp_next1) temp_next1->prev = rand;
//
//                temp->prev = rand_prev1;
//                rand->next = temp_next1;
//
//                temp->next = rand;
//                rand->prev = temp;
//            }
//           
//            else
//            {
//                if (temp_Prev1)
//                {
//                    temp_Prev1->next = rand;
//                }
//                if (temp_next1)
//                {
//                    temp_next1->prev = rand;
//                }
//                if (rand_prev1)
//                {
//                    rand_prev1->next = temp;
//                }
//                if (rand_next2)
//                {
//                    rand_next2->prev = temp;
//                }
//
//                Node<T>* tempNext = temp->next;
//                temp->next = rand->next;
//                rand->next = tempNext;
//
//                
//                Node<T>* tempPrev = temp->prev;
//                temp->prev = rand->prev;
//                rand->prev = tempPrev;
//            }
//
//           
//            if (n == 1)
//            {
//                head = rand;
//            }
//            if (n == length)
//            {
//                head = temp;
//            }
//            if (temp == tail)
//            {
//                tail = rand;
//            }
//            else if (rand == tail)
//            {
//                tail = temp;
//            }
//    }
//
//    int sum(int num)
//    {
//        int sum = 0;
//        num = abs(num);
//        while (num > 0)
//        {
//            sum += num % 10;
//            num /= 10;
//        }
//        return sum;
//    }
//
//    void remove_occurence()
//    {
//        if (head == nullptr)
//        {
//            cout << "No Nodes exist" << endl;
//            return;
//        }
//
//        Node<T>* temp = head;
//        int sum = 0;
//        int product = 1;
//        bool flag = false;
//
//        while (temp != nullptr)
//        {
//            Node<T>* nNode = temp->next;
//
//            if (sum(temp->data) % 3 == 0)
//            {
//                if (temp->prev)
//                {
//                    temp->prev->next = temp->next;
//                }
//                else
//                {
//                    head = temp->next;
//                }
//                if (temp->next)
//                {
//                    temp->next->prev = temp->prev;
//                }
//                else
//                {
//                    tail = temp->prev; 
//                }
//                delete temp;
//            }
//            else
//            {
//                sum += temp->data;
//                product *= temp->data;
//                flag = true;
//            }
//
//            temp = nNode;
//        }
//
//        if (flag)
//        {
//            cout << "Sum of remaining elements = " << sum << endl;
//            cout << "Product of remaining elements = " << product << endl;
//        }
//        else
//        {
//            cout << "No elements remaining after deletion" << endl;
//        }
//    }
//
//    void reorderList()
//    {
//        if (head == nullptr || head == tail)
//        {
//            return;
//        }
//        Node<T>* temp = head;//for left
//        Node<T>* rand = tail;//for right
//
//        while (temp != rand && temp->prev != rand)
//        {
//            Node<T>* leftNext = temp->next;
//            Node<T>* rightPrev = rand->prev;
//
//        
//            temp->next = rand;
//            rand->prev = temp;
//
//            if (leftNext == rand)
//            {
//                break;
//            }
//            
//            rand->next = leftNext;
//            leftNext->prev = rand;
//
//            
//            temp = leftNext;
//            rand = rightPrev;
//        }
//
//        
//        tail = rand;
//        tail->next = nullptr;
//    }
//
//
//
//    void print()
//    {
//        Node<T>* temp = head;
//
//        while (temp != nullptr)
//        {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    ~DoublyLinkedList()
//    {
//        Node<T>* temp = head;
//        while (temp != nullptr)
//        {
//            Node<T>* rand = temp;
//            temp = temp->next;
//            delete rand;
//        }
//        head = nullptr;
//        tail = nullptr;
//    }
//};
//
//int main()
//{
//    DoublyLinkedList<int> d1
//        ;
//    d1.add_node(1);
//    d1.add_node(2);
//    d1.add_node(3);
//    d1.add_node(4);
//    d1.add_node(5);
//    d1.add_node(6);
//    d1.add_node(7);
//    d1.add_node(8);
//    d1.add_node(9);
//    d1.swapNodes(2);
//    //cout << "Before eversing the List: ";
//    //d1.print();
//    //d1.reverseLinkList();
//    //cout << "After reversing the List: ";
//    //d1.print();
//    //d1.isMyPalindrome();
//    //d1.reorderList();
//    d1.reorderList();
//    d1.print();
//}