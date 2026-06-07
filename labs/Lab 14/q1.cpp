//#include <iostream>
//using namespace std;
//class Node 
//{
//public:
//    int val;
//    Node* next;
//
//};
//
//class Graph 
//{
//private:
//
//    int totalVertices;
//    Node** adjList;
//
//public:
//
//    Graph()
//    {
//        totalVertices = 0;
//        adjList = nullptr;
//    }
//   
//    Graph(int V) 
//    {
//        totalVertices = V;
//        adjList = new Node * [V];
//        
//        for (int i = 0; i < V; i++)
//        {
//            adjList[i] = nullptr;
//        }
//    }
//    
//    void addEdge(int src, int dest) 
//    {
//                Node* newNode = new Node;
//        newNode->val = dest;
//        newNode->next = nullptr;
//
//        
//        newNode->next = adjList[src];
//        adjList[src] = newNode;
//    }
//
//    
//    int CouyntNodes(int k)
//    {
//        
//        int* in_d = new int[totalVertices];
//
//                for (int i = 0; i < totalVertices; i++)
//                {
//            in_d[i] = 0;
//        }
//
//        
//                for (int i = 0; i < totalVertices; i++) 
//                {
//            Node* current = adjList[i];
//
//         
//          
//            while (current != nullptr) 
//            {
//                int x = current->val;
//                in_d[x] = in_d[x] + 1;
//
//               
//                current = current->next;
//            }
//        }
//
//        
//        int count = 0;
//        
//        for (int i = 0; i < totalVertices; i++)
//        {
//            if (in_d[i] > k) 
//            {
//                count++;
//            }
//        }
//
//        
//        delete[] in_d;
//
//        return count;
//    }
//
//    ~Graph() 
//    {
//        for (int i = 0; i < totalVertices; i++)
//        {
//            Node* temp = adjList[i];
//            while (temp != nullptr) 
//            {
//                Node* temp = temp;
//                temp = temp->next;
//                delete temp;
//            }
//        }
//        delete[] adjList;
//    }
//
//};
//
//int main() {
//    int V, E, k;
//
//    cout << "Enter number of vertices: ";
//    cin >> V;
//
//    Graph g(V);
//
//    cout << "Enter number of edges: ";
//    cin >> E;
//
//    cout << "Enter edges: \n";
//
//    for (int i = 0; i < E; i++)
//    {
//        int u, v;
//        cin >> u;
//        cin >> v;
//
//        if (u >= 0 && u < V && v >= 0 && v < V) 
//        {
//            g.addEdge(u, v);
//        }
//        else
//        {
//            cout << "Invalid\n";
//        }
//    }
//
//    cout << "Enter value for k: ";
//    cin >> k;
//
//    int result = g.CouyntNodes(k);
//
//    cout << "Number of nodes of greater  " << k << " is: " << result << endl;
//}