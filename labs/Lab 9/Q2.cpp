#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class Node
{
public:
    Node* left;
    Node* right;
    T data;

    Node(T info)
    {
        data = info;
        left = right = nullptr;
    }
};

template<typename T>
class AVL
{
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, T data)
    {
        if (node == nullptr)
            return new Node<T>(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void Preorder(Node<T>* node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    bool isSkewed(Node<T>* node)
    {
        if (node == nullptr)
            return true;

        if (node->left != nullptr && node->right != nullptr)
            return false;

        if (node->left != nullptr)
            return isSkewed(node->left);
        else
            return isSkewed(node->right);
    }

    int CountNodes(Node<T>* node)
    {
        if (node == nullptr)
            return 0;
        return 1 + CountNodes(node->left) + CountNodes(node->right);
    }

    void storeArray(Node<T>* root, T arr[], int& index)
    {
        if (root == nullptr)
            return;

        storeArray(root->left, arr, index);
        arr[index++] = root->data;
        storeArray(root->right, arr, index);
    }

    void SortArray(T arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

    Node<T>* ConvertBST(T arr[], int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Node<T>* node = new Node<T>(arr[mid]);
        node->left = ConvertBST(arr, start, mid - 1);
        node->right = ConvertBST(arr, mid + 1, end);
        return node;
    }

    int checkAVL(Node<T>* node, bool& is_balanced)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = checkAVL(node->left, is_balanced);
        int rightHeight = checkAVL(node->right, is_balanced);

        if (abs(leftHeight - rightHeight) > 1)
            is_balanced = false;

        return 1 + max(leftHeight, rightHeight);
    }

    Node<T>* find_kth_min(Node<T>* node, int& k)
    {
        if (node == nullptr)
            return nullptr;

        Node<T>* left = find_kth_min(node->left, k);
        if (left != nullptr)
            return left;

        k--;
        if (k == 0)
            return node;

        return find_kth_min(node->right, k);
    }

public:
    AVL() { root = nullptr; }

    void InsertNode(T data)
    {
        root = insert(root, data);
    }

    void PreOrderDisplay()
    {
        Preorder(root);
        cout << endl;
    }

    void CheckSkewed()
    {
        cout << "Is Tree Skewed: " << (isSkewed(root) ? "Yes" : "No") << endl;
    }

    void Conversion()
    {
        int size = CountNodes(root);
        T* arr = new T[size];
        int index = 0;
        storeArray(root, arr, index);
        SortArray(arr, size);
        root = ConvertBST(arr, 0, size - 1);
        delete[] arr;
        cout << "Tree successfully balanced!" << endl;
    }

    void CheckIsAVL()
    {
        bool balanced = true;
        checkAVL(root, balanced);
        cout << "Is Tree AVL: " << (balanced) << endl;
    }

    void FindKthMin(int k)
    {
        int counter = k;
        Node<T>* result = find_kth_min(root, counter);
        if (result)
            cout << "element is: " << result->data << endl;
        else
            cout << "Tree has fewer than " << k << " elements.\n";
    }
};

int main()
{
    AVL<int> tree;
    int choice, value, k;

    do
    {
        cout << "1. Insert Node\n";
        cout << "2. Display Preorder\n";
        cout << "3. Check if Tree is Skewed\n";
        cout << "4. Check if Tree is AVL\n";
        cout << "5. Convert to Balanced BST\n";
        cout << "6. Find kth Minimum Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.InsertNode(value);
            break;

        case 2:
            cout << "Preorder Traversal: ";
            tree.PreOrderDisplay();
            break;

        case 3:
            tree.CheckSkewed();
            break;

        case 4:
            tree.CheckIsAVL();
            break;

        case 5:
            tree.Conversion();
            tree.PreOrderDisplay();
            break;

        case 6:
            cout << "Enter k: ";
            cin >> k;
            tree.FindKthMin(k);
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
