#include<iostream>
using namespace std;

template<typename k, typename v>
class Node
{
public:
    Node<k, v>* left;
    Node<k, v>* right;
    k key;
    v value;

    Node()
    {
        left = right = nullptr;
        key = k();
        value = v();
    }

    Node(k keys, v val)
    {
        key = keys;
        value = val;
        left = right = nullptr;
    }
};

template<typename k, typename v>
class SpecialBST
{
private:
    Node<k, v>* root;

    Node<k, v>* leftRotate(Node<k, v>* temp)
    {
        Node<k, v>* random = temp->right;
        temp->right = random->left;
        random->left = temp;
        return random;
    }

    Node<k, v>* rightRotate(Node<k, v>* temp)
    {
        Node<k, v>* random = temp->left;
        temp->left = random->right;
        random->right = temp;
        return random;
    }

    Node<k, v>* KeyToRoot(Node<k, v>* temp, k key_val)
    {
        if (temp == nullptr || temp->key == key_val)
        {
            return temp;
        }

        if (key_val < temp->key)
        {
            if (temp->left == nullptr)
            {
                return temp;
            }

            if (key_val < temp->left->key)
            {
                temp->left->left = KeyToRoot(temp->left->left, key_val);
                temp = rightRotate(temp);
            }
            else if (key_val > temp->left->key)
            {
                temp->left->right = KeyToRoot(temp->left->right, key_val);
                if (temp->left->right != nullptr)
                {
                    temp->left = leftRotate(temp->left);
                }
            }

            if (temp->left == nullptr)
            {
                return temp;
            }
            else
            {
                return rightRotate(temp);
            }
        }
        else
        {
            if (temp->right == nullptr)
            {
                return temp;
            }

            if (key_val > temp->right->key)
            {
                temp->right->right = KeyToRoot(temp->right->right, key_val);
                temp = leftRotate(temp);
            }
            else if (key_val < temp->right->key)
            {
                temp->right->left = KeyToRoot(temp->right->left, key_val);
                if (temp->right->left != nullptr)
                {
                    temp->right = rightRotate(temp->right);
                }
            }

            if (temp->right == nullptr)
            {
                return temp;
            }
            else
            {
                return leftRotate(temp);
            }
        }
    }

    void Inorder(Node<k, v>* temp, v*& arr, int& index)
    {
        if (temp == nullptr)
        {
            return;
        }

        Inorder(temp->left, arr, index);
        arr[index++] = temp->value;
        Inorder(temp->right, arr, index);
    }

    int TreeHeight(Node<k, v>* temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }

        return 1 + TreeHeight(temp->left) + TreeHeight(temp->right);
    }

public:

    SpecialBST()
    {
        root = nullptr;
    }

    bool Insert(k keys, v val)
    {
        if (root == nullptr)
        {
            root = new Node<k, v>(keys, val);
            return true;
        }

        root = KeyToRoot(root, keys);

        if (root->key == keys)
        {
            return false;
        }

        Node<k, v>* newNode = new Node<k, v>(keys, val);

        if (keys < root->key)
        {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        }
        else
        {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        root = newNode;
        return true;
    }

    v* Search(k key_val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        root = KeyToRoot(root, key_val);

        if (root->key == key_val)
        {
            return &root->value;
        }

        return nullptr;
    }

    bool deleteKey(k key_val)
    {
        if (root == nullptr)
        {
            return false;
        }

        root = KeyToRoot(root, key_val);

        if (root->key != key_val)
        {
            return false;
        }

        Node<k, v>* temp;

        if (root->left == nullptr)
        {
            temp = root;
            root = root->right;
        }
        else
        {
            temp = root;
            Node<k, v>* random = root->left;
            random = KeyToRoot(random, key_val);
            random->right = root->right;
            root = random;
        }

        delete temp;
        return true;
    }

    v* ValuesInOrder(int& size)
    {
        size = TreeHeight(root);
        v* arr = new v[size];
        int index = 0;
        Inorder(root, arr, index);
        return arr;
    }

    void destroy(Node<k, v>* temp)
    {
        if (temp == nullptr)
        {
            return;
        }

        destroy(temp->left);
        destroy(temp->right);
        delete temp;
    }

    ~SpecialBST()
    {
        destroy(root);
    }
};

class Student
{
public:
    int roll;
    int batch;
    string first, last, department;
    float cgpa;

    Student()
    {
        roll = batch = 0;
        cgpa = 0;
    }

    Student(int r, string f, string l, int b, string d, float c) : roll(r), first(f), last(l), batch(b), department(d), cgpa(c)
    {

    }
};

class StudentList
{
private:
    SpecialBST<int, Student> tree;
public:

    bool InsertStudent(int r, string f, string l, int b, string d, float c)
    {
        if (r <= 0 || b <= 0 || c < 0)
        {
            return false;
        }

        return tree.Insert(r, Student(r, f, l, b, d, c));
    }

    bool deleteStudent(int r)
    {
        if (r <= 0)
        {
            return false;
        }
        return tree.deleteKey(r);
    }

    Student* SearchStudent(int r)
    {
        if (r <= 0)
        {
            return nullptr;
        }

        return tree.Search(r);
    }

    bool UpdateStudent(int oldr, int newr, string f, string l, int b, string d, float c)
    {
        Student* temp = SearchStudent(oldr);

        if (temp == nullptr)
        {
            return false;
        }

        if (oldr == newr)
        {
            temp->first = f;
            temp->last = l;
            temp->batch = b;
            temp->department = d;
            temp->cgpa = c;
            return true;
        }

        if (SearchStudent(newr) != nullptr)
        {
            return false;
        }

        tree.deleteKey(oldr);
        tree.Insert(newr, Student(newr, f, l, b, d, c));
        return true;
    }

    void PrintStudents()
    {
        int count;
        Student* temp = tree.ValuesInOrder(count);
        if (count == 0)
        {
            cout << "No students Present" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "Roll Number: " << temp[i].roll << "\n";
            cout << "First Name: " << temp[i].first << "\n";
            cout << "Last Name: " << temp[i].last << "\n";
            cout << "Batch: " << temp[i].batch << "\n";
            cout << "Department: " << temp[i].department << "\n";
            cout << "CGPA: " << temp[i].cgpa << "\n\n";
        }

        delete[] temp;
    }
};

int main()
{
    StudentList sl;
    char choice;

    while (true)
    {
        cout << "I: Insert\nD: Delete\nS: Search\nU: Update\nP: Print\nE: Exit\n ";
        cin >> choice;

        if (choice == 'E' || choice == 'e')
        {
            break;
        }

        if (choice == 'I' || choice == 'i')
        {
            int r, b;
            string f, l, d;
            float c;
            cout << "Enter Roll, First, Last, Batch, Department, CGPA:\n ";
            cin >> r >> f >> l >> b >> d >> c;
            if (sl.InsertStudent(r, f, l, b, d, c))
            {
                cout << "Inserted\n";

            }
            else
            {
                cout << "Failed\n";
            }
        }

        else if (choice == 'P' || choice == 'p')
        {
            sl.PrintStudents();
        }

        else if (choice == 'S' || choice == 's')
        {
            int r;
            cout << "Enter Roll to Search: ";
            cin >> r;
            Student* s = sl.SearchStudent(r);
            if (s != nullptr)
            {
                cout << s->roll << " " << s->first << " " << s->last << " " << s->batch << " " << s->department << " " << s->cgpa << "\n";
            }
            else
            {
                cout << "Not Found\n";
            }
        }

        else if (choice == 'U' || choice == 'u')
        {
            int oldr, newr, b;
            string f, l, d;
            float c;
            cout << "Enter OldRoll NewRoll First Last Batch Department CGPA:\n> ";
            cin >> oldr >> newr >> f >> l >> b >> d >> c;
            if (sl.UpdateStudent(oldr, newr, f, l, b, d, c))
            {
                cout << "Updated\n";
            }
            else
            {
                cout << "Update Failed\n";
            }
        }

        else if (choice == 'D' || choice == 'd')
        {
            int r;
            cout << "Enter Roll to Delete: ";
            cin >> r;
            if (sl.deleteStudent(r))
            {
                cout << "Deleted\n";
            }
            else
            {
                cout << "Not Found\n";
            }
        }

        else
        {
            cout << "Invalid Choice\n";
        }
    }
}
