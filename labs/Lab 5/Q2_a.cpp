#include <iostream>
using namespace std;

class PriorityQueueArray {
private:
    int capacity;
    int count;
    int* values;
    int* priority;

public:
    PriorityQueueArray(int size) {
        capacity = size;
        count = 0;
        values = new int[size];
        priority = new int[size];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int val, int pr) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        values[count] = val;
        priority[count] = pr;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int highPr = priority[0], index = 0;
        for (int i = 1; i < count; i++) {
            if (priority[i] > highPr) {
                highPr = priority[i];
                index = i;
            }
        }

        cout << "Dequeued: " << values[index] << " (Priority " << priority[index] << ")" << endl;

        // shift elements
        for (int i = index; i < count - 1; i++) {
            values[i] = values[i + 1];
            priority[i] = priority[i + 1];
        }
        count--;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < count; i++) {
            cout << "[" << values[i] << ", p=" << priority[i] << "] ";
        }
        cout << endl;
    }

    int size() {
        return count;
    }

    ~PriorityQueueArray() {
        delete[] values;
        delete[] priority;
    }
};

int main() {
    int size;
    cout << "Enter size : ";
    cin >> size;

    PriorityQueueArray pq(size);

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