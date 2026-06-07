//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Queue {
//private:
//    int capacity;
//    int front;
//    int rear;
//    T* array;
//    int count;
//
//public:
//    Queue(int size) {
//        capacity = size;
//        front = 0;
//        rear = -1;
//        array = new T[size];
//        count = 0;
//    }
//
//    bool isEmpty()
//    {
//        if (count==0)
//        {
//            return false;
//        }
//        return true;
//    }
//
//    void enqueue(T const& e)
//    {
//        if (count == capacity)
//        {
//            cout << "Queue is full!" << endl;
//            return;
//        }
//        rear = (rear + 1) % capacity;
//        array[rear] = e;
//        count++;
//    }
//
//    void dequeue() {
//        if (count == 0) {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        front = (front + 1) % capacity;
//        count--;
//    }
//
//    int size()
//    {
//        return count;
//    }
//
//    void print()
//    {
//        if (count == 0)
//        {
//            cout << "Queue is empty" << endl;
//            return;
//        }
//        cout << "Queue Values: ";
//        for (int i = 0; i < count; i++)
//        {
//            int index = (front + i) % capacity;
//            cout << array[index] << " ";
//        }
//        cout << endl;
//    }
//
//    bool Front_Value(T & e)
//    {
//        if (count==0)
//        {
//            return false;
//        }
//
//        else
//        {
//            e = array[front];
//            return true;
//        }
//    }
//
//    int SecondHighest()
//    {
//        if (count==0 || count==1)
//        {
//            cout << "No Second Highest" << endl;
//            return -1;
//        }
//
//        int s_high = 0, high = 0;
//
//        for (int i=0;i<count;i++)
//        {
//            int posi = (front + i) % capacity;
//            if (array[posi]>high)
//            {
//                s_high = high;
//                high = array[posi];
//            }
//        }
//        return s_high;
//    }
//
//    void intersection(Queue& other)
//    {
//
//        cout << "Common Values: ";
//        for (int i=0;i<this->count;i++)
//        {
//            for (int j=0;j<other.count;j++)
//            {
//                if (this->array[(this->front+i)%this->capacity]==other.array[(other.front + j) % other.capacity])
//                {
//                    cout << this->array[(this->front + i) % this->capacity]<<" ";
//                }
//            }
//        }
//    }
//
//    ~Queue()
//    {
//        delete[] array;
//    }
//};
//
//int main() {
//    int size;
//
//    do {
//        cout << "Enter queue size: ";
//        cin >> size;
//        if (size <= 0)
//        {
//            cout << "Invalid Size" << endl;
//        }
//    } while (size <= 0);
//
//    Queue<int> obj(size);
//
//    cout << "Enter values (-1 to stop):" << endl;
//    for (int i = 0; i < size; i++)
//    {
//        int val;
//        cin >> val;
//        if (val == -1)
//        {
//            break;
//        }
//        obj.enqueue(val);
//    }
//
//    int select;
//    do
//    {
//        cout << "1 for Enqueue"<<endl;
//        cout << "2 for Dequeue"<<endl;
//        cout << "3 for Print "<<endl;
//        cout << "4 for Front Value"<<endl;
//        cout << "5 for Size"<<endl;
//        cout << "6 for Second Highest"<<endl;
//        cout << "7 for Intersection "<<endl;
//        cout << "8 for Exit"<<endl;
//        cout << "Enter value: ";
//        cin >> select;
//
//        switch (select)
//        {
//        case 1:
//        {
//            int val;
//            cout << "Enter value to enqueue: ";
//            cin >> val;
//            if (val != -1) obj.enqueue(val);
//            break;
//        }
//        case 2:
//            obj.dequeue();
//            break;
//        case 3:
//            obj.print();
//            break;
//        case 4:
//        {
//            int x;
//            if (obj.Front_Value(x))
//            {
//                cout << "Front Value: " << x << endl;
//            }
//            else
//            {
//                cout << "Queue is empty!" << endl;
//            }
//            break;
//        }
//        case 5:
//            cout << "Queue Size: " << obj.size() << endl;
//            break;
//        case 6:
//        {
//            int s_high = obj.SecondHighest();
//            if (s_high != -1)
//            {
//                cout << "Second Highest: " << s_high << endl;
//            }
//                break;
//        }
//        case 7: {
//            int size2;
//            cout << "Enter size for second queue: ";
//            cin >> size2;
//            Queue<int> obj2(size2);
//            cout << "Enter values (-1 to stop): " << endl;
//            for (int i = 0; i < size2; i++)
//            {
//                int val;
//                cin >> val;
//                if (val == -1)
//                {
//                    break;
//
//                }
//                obj2.enqueue(val);
//            }
//            obj.intersection(obj2);
//            cout << endl;
//            break;
//        }
//        case 8:
//            cout << "Exiting" << endl;
//            break;
//        default:
//            cout << "Invalid choice!" << endl;
//        }
//    } while (select != 8);
//}