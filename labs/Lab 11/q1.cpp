
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    int frequency;
    Node* left, * right;

    Node() {
        data = '\0';
        frequency = 0;
        left = right = NULL;
    }

    Node(char d, int f) {
        data = d;
        frequency = f;
        left = right = NULL;
    }
};

void findMinTwo(Node* arr[], int size, int& min1, int& min2) {
    min1 = -1;
    min2 = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == NULL)
        {
            continue;
        }

        if (min1 == -1 || arr[i]->frequency < arr[min1]->frequency)
        {
            min1 = i;
        }
    }


    for (int i = 0; i < size; i++) {
        if (arr[i] == NULL || i == min1)
        {
            continue;
        }

        if (min2 == -1 || arr[i]->frequency < arr[min2]->frequency)
        {
            min2 = i;
        }
    }
}

void generateCodes(Node* root, string code, char chars[], string codes[], int& idx) {
    if (!root)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        chars[idx] = root->data;
        codes[idx] = code;
        idx++;
        return;
    }

    generateCodes(root->left, code + "0", chars, codes, idx);
    generateCodes(root->right, code + "1", chars, codes, idx);
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    Node* freqNodes[256];

    for (int i = 0; i < 256; i++)
        freqNodes[i] = NULL;

    for (int i = 0; i < text.length(); i++) {
        unsigned char c = text[i];
        if (freqNodes[c] == NULL)
        {
            freqNodes[c] = new Node(c, 1);
        }
        else
        {
            freqNodes[c]->frequency++;
        }
    }


    Node* arr[256];
    int size = 0;

    for (int i = 0; i < 256; i++)
    {
        if (freqNodes[i] != NULL)
        {
            arr[size++] = freqNodes[i];
        }
    }


    while (size > 1) {
        int min1, min2;
        findMinTwo(arr, size, min1, min2);

        Node* leftNode = arr[min1];
        Node* rightNode = arr[min2];

        Node* newNode = new Node('\0', leftNode->frequency + rightNode->frequency);
        newNode->left = leftNode;
        newNode->right = rightNode;

        if (min1 > min2) {
            arr[min1] = arr[size - 1];
            arr[min2] = newNode;
        }
        else {
            arr[min2] = arr[size - 1];
            arr[min1] = newNode;
        }

        size--;
    }

    Node* root = arr[0];

    char chars[256];
    string codes[256];
    int idx = 0;

    generateCodes(root, "", chars, codes, idx);

    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < idx; i++) {
        cout << "Character '" << chars[i] << "' : Code " << codes[i] << endl;
    }

    string encoded = "";

    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < idx; j++) {
            if (text[i] == chars[j])
            {
                encoded += codes[j];
                break;
            }
        }
    }

    cout << "\nEncoded String: " << encoded << endl;
}
