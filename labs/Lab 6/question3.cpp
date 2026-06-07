#include<iostream>
using namespace std;

template<typename T>
class stack {
private:
    T* arr;
    int count;
    int capacity;
    int top;

public:
    stack() 
    {
        arr = nullptr;
        capacity = 0;
        count = 0;
        top = -1;
    }

    stack(int c) 
    {
        arr = new T[c];
        capacity = c;
        count = 0;
        top = -1;  
    }

    bool isFull() 
    {
        return count == capacity;
    }

    bool isEmpty() 
    {
        return count == 0;
    }

    int size() 
    {
        return count;
    }

    void push(T val) 
    {
        if (isFull()) 
        {
            cout << "Stack Filled" << endl;
            return;
        }
        top++;
        arr[top] = val;
        count++;
        cout << "Inserted " << val << endl;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Empty" << endl;
            return;
        }
        cout << "Deleted " << arr[top] << endl;
        top--;
        count--;
    }

    bool top_value(T& var)
    {
        if (isEmpty()) 
        {
            cout << "Stack Empty" << endl;
            return false;
        }
        var = arr[top];
        return true;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Stack empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int precedence(char op) 
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        if (op == '*' || op == '/')
        {
            return 2;
        }
        return 0;
    }

    string infixToPostfix(string expr)
    {
        stack<char> st;
        string result;

        for (int i = 0; i < expr.length(); i++) 
        {
            char c = expr[i];

            if (c == ' ') continue;

            if (isalnum(c))
            {
                result += c;
                result += ' '; 
            }
            else if (c == '(') 
            {
                st.push(c);
            }

            else if (c == ')') 
            {
                while (!st.empty() && st.top() != '(') 
                {
                    result += st.top();
                    result += ' ';
                    st.pop();
                }
                if (!st.empty() && st.top() == '(')
                    st.pop();
            }

            else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    result += st.top();
                    result += ' ';
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) 
        {
            result += st.top();
            result += ' ';
            st.pop();
        }

        if (!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};

int main() 
{
    string expr1 = "A + B * C";
    string expr2 = "(A + B) * C";
    string expr3 = "A * (B + C) / D";

    cout << "Infix: " << expr1 << "\nPostfix: " << infixToPostfix(expr1) << "\n\n";
    cout << "Infix: " << expr2 << "\nPostfix: " << infixToPostfix(expr2) << "\n\n";
    cout << "Infix: " << expr3 << "\nPostfix: " << infixToPostfix(expr3) << "\n\n";

    return 0;
    
}