//
//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Node
//{
//public:
//    Node* left;
//    Node* right;
//    T data;
//
//    Node(T info)
//    {
//        data = info;
//        left = right = nullptr;
//    }
//};
//
//template<typename T>
//class AVL
//{
//private:
//    Node<T>* root;
//
//    Node<T>* insert(Node<T>* node, T data)
//    {
//        if (node == nullptr)
//            return new Node<T>(data);
//
//        if (data < node->data)
//            node->left = insert(node->left, data);
//        else
//            node->right = insert(node->right, data);
//
//        return node;
//    }
//
//    void Preorder(Node<T>* node)
//    {
//        if (node == nullptr)
//            return;
//
//        cout << node->data << " ";
//        Preorder(node->left);
//        Preorder(node->right);
//    }
//
//    bool isSkewed(Node<T>* node)
//    {
//        if (node == nullptr)
//            return true;
//
//        if (node->left != nullptr && node->right != nullptr)
//            return false;
//
//        if (node->left != nullptr)
//            return isSkewed(node->left);
//        else
//            return isSkewed(node->right);
//    }
//
//    int CountNodes(Node<T>* node)
//    {
//        if (node == nullptr)
//            return 0;
//        return 1 + CountNodes(node->left) + CountNodes(node->right);
//    }
//
//    void storeArray(Node<T>* root, T arr[], int& index)
//    {
//        if (root == nullptr)
//            return;
//
//        storeArray(root->left, arr, index);
//        arr[index++] = root->data;
//        storeArray(root->right, arr, index);
//    }
//
//    void SortArray(T arr[], int size)
//    {
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = i + 1; j < size; j++)
//            {
//                if (arr[i] > arr[j])
//                    swap(arr[i], arr[j]);
//            }
//        }
//    }
//
//    Node<T>* ConvertBST(T arr[], int start, int end)
//    {
//        if (start > end)
//            return nullptr;
//
//        int mid = (start + end) / 2;
//        Node<T>* node = new Node<T>(arr[mid]);
//        node->left = ConvertBST(arr, start, mid - 1);
//        node->right = ConvertBST(arr, mid + 1, end);
//        return node;
//    }
//
//public:
//    AVL() { root = nullptr; }
//
//    void InsertNode(T data)
//    {
//        root = insert(root, data);
//    }
//
//    void PreOrderDisplay()
//    {
//        Preorder(root);
//        cout << endl;
//    }
//
//    void CheckSkewed()
//    {
//        cout << "Is Tree Skewed: " << (isSkewed(root) << endl;
//    }
//
//    Node<T>* BalancedBST(Node<T>* node)
//    {
//        int size = CountNodes(node);
//        T* arr = new T[size];
//        int index = 0;
//
//        storeArray(node, arr, index);
//        SortArray(arr, size);
//
//        Node<T>* result = ConvertBST(arr, 0, size - 1);
//
//        delete[] arr;
//        return result;
//    }
//
//    void Conversion()
//    {
//        root = BalancedBST(root);
//    }
//};
//
//int main()
//{
//    AVL<int> tree;
//    int choice, value;
//
//    do
//    {
//        cout << "1 for Insert Node\n";
//        cout << "2 for Display Preorder\n";
//        cout << "3 for if Tree is Skewed\n";
//        cout << "4 for Convert to Balanced BST\n";
//        cout << "5 for Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            cout << "Enter value to insert: ";
//            cin >> value;
//            tree.InsertNode(value);
//            break;
//
//        case 2:
//            cout << "Preorder Traversal: ";
//            tree.PreOrderDisplay();
//            break;
//
//        case 3:
//            tree.CheckSkewed();
//            break;
//
//        case 4:
//            tree.Conversion();
//            tree.PreOrderDisplay();
//            break;
//
//        case 5:
//            cout << "Exiting program...\n";
//            break;
//
//        default:
//            cout << "Invalid choice\n";
//        }
//
//    } while (choice != 5);
//
//    return 0;
//}