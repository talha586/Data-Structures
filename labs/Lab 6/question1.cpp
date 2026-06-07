//#include<iostream>
//using namespace std;
//
//template<typename T>
//class stack {
//private:
//    T* arr;
//    int count;
//    int capacity;
//    int top;
//
//public:
//    stack() 
//    {
//        arr = nullptr;
//        capacity = 0;
//        count = 0;
//        top = -1;
//    }
//
//    stack(int c) 
//    {
//        arr = new T[c];
//        capacity = c;
//        count = 0;
//        top = -1;  
//    }
//
//    bool isFull() 
//    {
//        return count == capacity;
//    }
//
//    bool isEmpty() 
//    {
//        return count == 0;
//    }
//
//    int size() 
//    {
//        return count;
//    }
//
//    void push(T val) 
//    {
//        if (isFull()) 
//        {
//            cout << "Stack Filled" << endl;
//            return;
//        }
//        top++;
//        arr[top] = val;
//        count++;
//        cout << "Inserted " << val << endl;
//    }
//
//    void pop() 
//    {
//        if (isEmpty()) 
//        {
//            cout << "Stack Empty" << endl;
//            return;
//        }
//        cout << "Deleted " << arr[top] << endl;
//        top--;
//        count--;
//    }
//
//    bool top_value(T& var)
//    {
//        if (isEmpty()) 
//        {
//            cout << "Stack Empty" << endl;
//            return false;
//        }
//        var = arr[top];
//        return true;
//    }
//
//    void display() 
//    {
//        if (isEmpty()) 
//        {
//            cout << "Stack empty" << endl;
//            return;
//        }
//        cout << "Stack elements: ";
//        for (int i = 0; i <= top; i++) 
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    int capacity;
//    cout << "Enter capacity of stack: ";
//    cin >> capacity;
//
//    stack<int> s(capacity);
//
//    int choice, value;
//
//    do 
//    {
//        cout << "1 for push" << endl;
//        cout << "2 for pop" << endl;
//        cout << "3 for top" << endl;
//        cout << "4 for size" << endl;
//        cout << "5 for display" << endl;
//        cout << "6 for exit" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) 
//        {
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            s.push(value);
//            break;
//        case 2:
//            s.pop();
//            break;
//        case 3: 
//        {
//            int var;
//            if (s.top_value(var))
//                cout << "Top element is: " << var << endl;
//            break;
//        }
//        case 4:
//            cout << "Size: " << s.size() << endl;
//            break;
//        case 5:
//            s.display();
//            break;
//        case 6:
//            cout << "Exit" << endl;
//            break;
//        default:
//            cout << "Invalid choice" << endl;
//        }
//    } 
//    while (choice != 6);
//}
