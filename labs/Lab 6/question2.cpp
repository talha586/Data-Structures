//#include<iostream>
//#include<cstring>
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
//
//    bool isBalanced(string exp)
//    {
//        string data = exp;
//        int length = data.length();
//
//        cout << "Length of String " << length << endl;
//
//        for (int i=0;i<length;i++)
//        {
//            if (data[i]=='['|| data[i] == '{' || data[i] == '(')
//            {
//                push(data[i]);
//            }
//
//            else if (data[i]!='['|| data[i]!=']' || data[i] != '{' || data[i] != '(' || data[i] != '}' || data[i] != ')')
//            {
//                cout << "Invalid data" << endl;
//                return false;
//            }
//
//            else
//            {
//                pop();
//            }
//        }
//
//        if (isEmpty())
//        {
//            return true;
//        }
//        return false;
//    }
//};
//
//int main()
//{
//    string temp;
//    cout << "Enter expression: ";
//    cin >> temp; 
//
//    stack<char> st(temp.length());
//
//    if (st.isBalanced(temp))
//        cout << "Balanced" << endl;
//    else
//        cout << "Not Balanced" << endl;
//
//}