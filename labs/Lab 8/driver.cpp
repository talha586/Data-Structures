#include <iostream>
using namespace std;

template <typename k, typename v>
class Node
{
public:
    k key;
    v value;
    Node<k, v>* leftChild;
    Node<k, v>* rightChild;

    Node(k key, v value)
    {
        this->key = key;
        this->value = value;

        leftChild = nullptr;
        rightChild = nullptr;
    }
};

template <typename k, typename v>
class BST
{
    Node<k, v>* root;



public:
    BST()
    {
        root = nullptr;
    }

    BST(const BST<k, v>& other)
    {
        root = copy(other.root);
    }

    ~BST()
    {
        destroy(root);
    }

    void destroy(Node<k, v>* node)
    {
        if (node == nullptr)
        {
            return;
        }

        destroy(node->leftChild);
        destroy(node->rightChild);

        delete node;
    }

    Node<k, v>* copy(Node<k, v>* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        Node<k, v>* newNode = new Node<k, v>(node->key, node->value);
        newNode->leftChild = copy(node->leftChild);
        newNode->rightChild = copy(node->rightChild);

        return newNode;
    }

    Node<k, v>* insertRecHelper(Node<k, v>* node, k key, v value)
    {
        if (node == nullptr)
        {
            return new Node<k, v>(key, value);
        }
        if (key < node->key)
        {
            node->leftChild = insertRecHelper(node->leftChild, key, value);
        }

        else if (key > node->key)
        {
            node->rightChild = insertRecHelper(node->rightChild, key, value);
        }

        else
        {
            node->value = value;
        }

        return node;
    }

    int totalNodesHelper(Node<k, v>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }


        return 1 + totalNodesHelper(node->leftChild) + totalNodesHelper(node->rightChild);
    }

    int heightHelper(Node<k, v>* node) const
    {
        if (node == nullptr)
        {
            return 0;

        }

        int leftH = heightHelper(node->leftChild);
        int rightH = heightHelper(node->rightChild);
        if (leftH > rightH)
        {
            return leftH + 1;
        }

        else
        {
            return rightH + 1;
        }


    }

    int leafNodesHelper(Node<k, v>* node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node->leftChild == nullptr && node->rightChild == nullptr)
        {
            return 1;
        }


        return leafNodesHelper(node->leftChild) + leafNodesHelper(node->rightChild);
    }

    Node<k, v>* search(k key)
    {
        Node<k, v>* current = root;
        while (current != nullptr)
        {
            if (key == current->key)
            {
                return current;
            }

            else if (key < current->key)
            {
                current = current->leftChild;
            }

            else
            {
                current = current->rightChild;
            }
        }

        return nullptr;
    }

    void insert(k const key, v const value)
    {
        if (root == nullptr)
        {
            root = new Node<k, v>(key, value);
            return;
        }
        Node<k, v>* current = root;
        Node<k, v>* parent = nullptr;
        while (current != nullptr)
        {
            parent = current;
            if (key == current->key)
            {
                current->value = value;
                return;
            }
            else if (key < current->key)
            {
                current = current->leftChild;
            }

            else
            {
                current = current->rightChild;
            }
        }
        if (key < parent->key)
        {
            parent->leftChild = new Node<k, v>(key, value);
        }

        else
        {
            parent->rightChild = new Node<k, v>(key, value);
        }
    }

    void insertRec(k const key, v const value)
    {
        root = insertRecHelper(root, key, value);
    }

    void inorderTraversal() const
    {
        Node<k, v>* stack[100];
        int top = -1;
        Node<k, v>* current = root;
        while (true)
        {
            if (current != nullptr)
            {
                stack[++top] = current;
                current = current->leftChild;
            }
            else
            {
                if (top == -1) break;
                current = stack[top--];
                cout << current->key << " ";
                current = current->rightChild;
            }
        }
        cout << endl;
    }

    int totalNodes()
    {
        return totalNodesHelper(root);
    }

    int height(Node<k, v>* node) const
    {
        return heightHelper(node);
    }

    int leafNodes() const
    {
        return leafNodesHelper(root);
    }

    void Height(k key, v value)
    {
        Node<k, v>* node = search(key);
        if (node == nullptr)
            cout << "Node not found" << endl;
        else
            cout << "Height of given node: " << height(node) << endl;
    }
};

int main()
{
    BST<int, int> tree;
    tree.insert(500, 500);
    tree.insertRec(1000, 1000);
    tree.insert(1, 1);
    tree.insert(600, 600);
    tree.insertRec(700, 700);
    tree.insert(10, 10);
    tree.insert(30, 30);
    tree.insertRec(9000, 9000);
    tree.insert(50000, 50000);
    tree.insertRec(20, 20);
    tree.Height(9000, 9000);
    cout << "Printing keys using iterative inorder traversal: ";
    tree.inorderTraversal();
    system("pause");
    return 0;
}
