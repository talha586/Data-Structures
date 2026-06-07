
//24L-0618
#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node* next;

    Node()
    {
        next = nullptr;
    }

    Node(T val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        delete next;
    }
};

template<typename T>
class singlelinkedlist
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    singlelinkedlist()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Print() //O(n)
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return;
    }

    void insertatend(T const val)// O(n)
    {
        Node<T>* n1 = new Node<T>(val);

        if (head == nullptr)
        {
            head = n1;
            tail = n1;
            cout << "Node Added" << endl;
            size++;
            return;
        }

        Node<T>* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = n1;
        tail = temp->next;
        cout << "Node Added at Last" << endl;
        size++;
    }

    void insertatfront(T const val)//O(1)
    {
        Node<T>* n1 = new Node<T>(val);

        if (head == nullptr)
        {
            head = n1;
            tail = n1;
            cout << "Nodde added at front" << endl;
            size++;
            return;
        }

        n1->next = head;
        head = n1;
        cout << "New Node added at Front" << endl;
        size++;

    }



    bool search(T const val) //O(n)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isempty()// O(1)
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    void deletestart() // O(1)
    {
        if (isempty() == false)
        {
            Node<T>* temp = head;
            head = temp->next;
            delete temp;
            size--;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            cout << "Deleted the element at start" << endl;
            return;
        }

        cout << "The Node is empty" << endl;
    }

    void deleteEnd()//O(n)
    {
        if (isempty() == true)
        {
            cout << "No Node" << endl;
            return;
        }

        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }

        Node<T>* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
        return;
    }

    bool insert_after(T const v1, T const v2)//O(n)
    {
        Node<T>* temp = head;

        while (temp != nullptr) 
        {
            if (temp->data == v1)
            {
                Node<T>* n1 = new Node<T>(v2);
                n1->next = temp->next;
                temp->next = n1;

                if (temp == tail)
                {
                    tail = n1;
                }

                size++;
                cout << "Insertedion done" << endl;
                return true;
            }
            temp = temp->next;
        }

        cout << "Value no found" << v1 << endl;
        return false;
    }

    void deleteAll(T const value)//O(n)
    {
        if (isempty())
        {
            cout << "Empty list" << endl;
            return;
        }

        while (head->data == value)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
        }

        Node<T>* current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node<T>* temp = current->next;
                current->next = temp->next;
                if (temp == tail)
                {
                    tail = current;
                }
                delete temp;
                size--;
            }
            else
            {
                current = current->next;
            }
        }

        cout << "All repeated values deleted" << value << endl;
    }

    void findfrom_end(int index)//O(n)
    {
        Node<T>* temp = head;

        if (index<0 || index>size)
        {
            cout << "Index not accesible" << endl;
            return;
        }

        int x = size - index;
        for (int i=0;i<=x-1;i++)
        {
            temp = temp->next;
        }
        cout << "The Element from the last N Node is :" << temp->data << endl;
        return;
    }

    bool issorted() // O(n)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node<T>* temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data > temp->next->data)
                return false;
            temp = temp->next;
        }
        return true;
    }

    ~singlelinkedlist()
    {
        delete head;
        delete tail;

    }
};

int main()
{
    singlelinkedlist<int> l1;
    l1.insertatfront(2);
    l1.insertatfront(6);
    l1.insertatfront(8);
    cout << endl;
    l1.Print();
    l1.insertatend(3);
    l1.Print();
    cout << endl;
    l1.insertatfront(2);
    l1.insertatfront(4);
    l1.insertatfront(6);
    l1.deleteAll(6);
    cout << endl;
    l1.Print();
    cout << endl;
    l1.search(2);
    l1.search(9);
    l1.search(-1);
    l1.deletestart();
    cout << endl;
    l1.Print();
    l1.findfrom_end(3);

}
