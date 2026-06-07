#include <iostream>
using namespace std;

class Node {
public:
    int value;
    int priority;
    Node* next;
    Node(int v, int p) {
        value = v;
        priority = p;
        next = NULL;
    }
};

class QueueList {
private:
    Node* head;

public:
    QueueList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int val, int pr) {
        Node* newNode = new Node(val, pr);

        // if list is empty OR higher priority than head
        if (head == NULL || pr > head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;
            // go until next node has lower priority
            while (temp->next != NULL && temp->next->priority >= pr) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Dequeued: " << temp->value << " (Priority " << temp->priority << ")" << endl;
        head = head->next;
        delete temp;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Priority Queue: ";
        while (temp != NULL) {
            cout << "[" << temp->value << ", p=" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size() {
        int c = 0;
        Node* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    ~QueueList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    QueueList pq;

    int choice;
    do {
        cout << "1. Enqueue \n";
        cout << "2. Dequeue \n";
        cout << "3. Print \n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int val, pr;
            cout << "Enter value: "; cin >> val;
            cout << "Enter priority: "; cin >> pr;
            pq.enqueue(val, pr);
            break;
        }
        case 2: pq.dequeue(); break;
        case 3: pq.print(); break;
        case 4: cout << "size: " << pq.size() << endl; break;
        case 5: cout << "Exiting " << endl; break;
        default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}