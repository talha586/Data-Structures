#include <iostream>
using namespace std;

class PersonNode
{
public:
    int id;
    PersonNode* next;

    PersonNode(int val)
    {
        id = val;
        next = nullptr;
    }
};

class JosephusList
{
private:
    PersonNode* head;

public:
    JosephusList(int n)
    {
        if (n <= 0)
        {
            head = nullptr;
            return;
        }

        head = new PersonNode(1);
        PersonNode* prev = head;

        for (int i = 2; i <= n; i++)
        {
            PersonNode* node = new PersonNode(i);
            prev->next = node;
            prev = node;
        }

        prev->next = head;
    }

    ~JosephusList()
    {
        if (head=nullptr)
        {
            return;
        }

        PersonNode* temp = head->next;
        
        while (temp != head)
        {
            PersonNode* next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
    }

    void print()
    {
        if (head==nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        PersonNode* temp = head;
        while (temp!=head)
        {
            cout << temp->id << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    
    int winner(int M)
    {
        if (head==nullptr)
        {
            return -1;
        }

        PersonNode* curr = head;
        PersonNode* prev = nullptr;

        while (curr->next != curr)
        {

            for (int i = 0; i < M; i++)
            {
                prev = curr;
                curr = curr->next;
            }


            cout << "Eliminated: " << curr->id << endl;

            prev->next = curr->next;

            if (curr == head)
            { 
                head = curr->next;
            }

            delete curr;
            curr = prev->next;
        }

        head = curr;
        return head->id;
    }
};

int main()
{
    JosephusList j(5);

    int winner = j.winner(3); 
    cout << "Winner: " << winner << endl;

    cout << "Remaining list: ";
    j.print();

    return 0;
}
