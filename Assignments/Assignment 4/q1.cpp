//#include <iostream>
//#include <list>
//#include <string>
//#include <fstream>
//
//using namespace std;
//const int MAX_VERTICES = 200;
//
//class vertex 
//{
//public:
//
//    int id;
//    string type;     
//    int key;         
//    int id_parent;    
//    bool active;     
//
//    vertex()
//    {
//
//        id = 0;
//        type = "";
//        key = INT_MAX;
//        id_parent = 0;
//        active = false;
//    }
//};
//
//class MinHeap 
//{
//private:
//    vertex** arr; 
//    int* pos;           
//    int capacity;
//    int currentSize;
//
//
//    void swapNodes(int i, int j) 
//    {
//        vertex* temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//
//        pos[arr[i]->id] = i;
//        pos[arr[j]->id] = j;
//
//    }
//
//    void heapify(int index) 
//    {
//        int smallest = index;
//        int left = 2 * index + 1;
//        int right = 2 * index + 2;
//
//        if (left < currentSize && arr[left]->key < arr[smallest]->key)
//        {
//            smallest = left;
//        }
//
//        if (right < currentSize && arr[right]->key < arr[smallest]->key)
//        {;
//            smallest = right;
//        }
//
//        if (smallest != index) 
//        {
//            swapNodes(index, smallest);
//            heapify(smallest);
//        }
//    }
//
//public:
//
//    MinHeap()
//    {
//        capacity = 0;
//        currentSize = 0;
//        arr = NULL;
//        pos = nullptr;
//    
//    }}}
//
//    MinHeap(int cap)
//    {
//
//        capacity = cap;
//        currentSize = 0;
//        arr = new vertex *[cap];
//        pos = new int[MAX_VERTICES];
//
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            pos[i] = 0;
//        }
//
//    }
//
//    bool isEmpty()
//    {
//        if (currentSize == 0)
//        {
//            return true;
//        }
//
//        return false;
//    }
//
//    bool isFull()
//    {
//        if (currentSize==capacity)
//        {
//            return true;
//        }
//        return false;
//    }
//
//    void insert(vertex* v) 
//    {
//        if (isFull())
//        {
//            return;
//        }
//
//        arr[currentSize] = v;
//        pos[v->id] = currentSize;
//        currentSize++;
//    }
//
//    bool isInMinHeap(int vertexID) 
//    {
//        if (vertexID >= MAX_VERTICES)
//        {
//            return false;
//
//        }
//
//        if (vertexID < 0)
//        {
//            return false;
//        }
//
//        if (pos[vertexID] < currentSize && pos[vertexID] >= 0)
//        {
//            return true;
//        }
//
//        return false;
//    }
//
//
//
//    vertex* extractMin() 
//    {
//        if (isEmpty()==true)
//        {
//            return nullptr;
//        }
//
//        vertex* first = arr[0];
//        vertex* last = arr[currentSize - 1];
//
//        arr[0] = last;
//
//        pos[first->id] = currentSize - 1;
//        pos[last->id] = 0;
//
//        currentSize--;
//        heapify(0);
//
//        return first;
//    }
//
//    void decreaseKey(int n_id, int n_k) 
//    {
//        int i = pos[n_id];
//        arr[i]->key = n_k;
//
//        while (arr[i]->key < arr[(i - 1) / 2]->key) 
//        {
//            swapNodes(i, (i - 1) / 2);
//            i = (i - 1) / 2;
//        }
//    }
//
//    ~MinHeap() 
//    {
//        delete[] arr;
//        delete[] pos;
//    }
//
//};
//
//class Graph 
//{
//private:
//    vertex* vertices;
//    list<pair<int, int>>* adjList;
//    int totalVertices;abc
//
//public:
//
//    Graph() 
//    {
//        totalVertices = 0;
//        vertices = new vertex[MAX_VERTICES];
//        adjList = new list<pair<int, int>>[MAX_VERTICES];
//    }
//
//    void loadFromFile(string filename)
//    {
//        ifstream f(filename);
//
//        if (!f)
//        {
//            cout << "Error " << endl;
//            return;
//        }
//
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            adjList[i].clear();
//            vertices[i].active = false;
//        }
//
//        totalVertices = 0;
//
//        int V, E;
//        f >> V;
//
//        for (int i = 0; i < V; i++)
//        {
//            int id;
//            string type;
//            char comma;
//
//            f >> id >> comma;
//            getline(f, type);
//
//            if (!type.empty() && type[0] == ' ')
//            {
//                type = type.substr(1);
//            }
//
//            insertVertex(id, type);
//        }
//
//        f >> E;
//
//        for (int i = 0; i < E; i++)
//        {
//            int u, v, w;
//            char comma;
//
//            f >> u >> comma >> v >> w;
//            insertEdge(u, v, w);
//        }
//
//        f.close();
//        cout << "Graph loaded " << endl;
//    }
//
//
//    void insertEdge(int u, int v, int w) 
//    {
//        if (u >= MAX_VERTICES || v >= MAX_VERTICES)
//        {
//            return;
//        }
//
//        adjList[u].push_back(make_pair(v, w));
//        adjList[v].push_back(make_pair(u, w));
//    }
//
//    void insertVertex(int id, string type)
//    {
//        if (id >= MAX_VERTICES)
//        {
//            cout << "Graphs is full"<<endl;
//            return;
//        }
//
//        vertices[id].id = id;
//        vertices[id].type = type;
//        vertices[id].active = true;
//        totalVertices++;
//    }
//
//
//
//    void saveToFile(string filename) 
//    {
//        ofstream o(filename);
//        
//        if (!o) 
//        {
//            cout << "Error " << endl;
//            return;
//        }
//
//        int count = 0;
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            if (vertices[i].active)
//            {
//                count++;
//            }
//        }
//
//
//        o << count << endl;
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            if (vertices[i].active) 
//            {
//                o << vertices[i].id << ", " << vertices[i].type << endl;
//            }
//        }
//
//        int edgeCount = 0;
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            edgeCount += adjList[i].size();
//        }
//        o << edgeCount / 2 << endl; 
//
//        for (int u = 0; u < MAX_VERTICES; u++) 
//        {
//            if (!vertices[u].active)
//            {
//                continue;
//            }
//            
//
//            for (list<pair<int, int>>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it)
//            {
//                int v = it->first;
//                int w = it->second;
//                
//                if (u < v)
//                {
//                    o << u << "," << v << " " << w << endl;
//                }
//            }
//        }
//
//        o.close();
//        cout << "Graph saved\n";
//    }
//
//    void generateGraph() 
//    {
//        if (totalVertices == 0) 
//        {
//            cout << "Graph empty\n";
//            return;
//        }
//
//        int startID = -1;
//        
//        for (int i = 0; i < MAX_VERTICES; i++) 
//        {
//            if (vertices[i].active)
//            {
//                vertices[i].key = INT_MAX;
//                vertices[i].id_parent = -1;
//                if (startID == -1)
//                {
//                    startID = i;
//                }
//            }
//        }
//
//        if (startID == -1)
//        {
//            return;
//        }
//
//        vertices[startID].key = 0;
//
//        MinHeap minHeap(totalVertices + 10);
//
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            if (vertices[i].active) 
//            {
//                minHeap.insert(&vertices[i]);
//            }
//        }
//
//
//        while (!minHeap.isEmpty()) 
//        {
//            vertex* uNode = minHeap.extractMin();
//            int u = uNode->id;
//
//            for (list<pair<int, int>>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it)
//            {
//                int v = it->first;
//                int weight = it->second;
//
//                if (minHeap.isInMinHeap(v))
//                {
//                    if (weight < vertices[v].key) 
//                    {
//                        vertices[v].id_parent = u;
//                        vertices[v].key = weight;
//                        minHeap.decreaseKey(v, weight);
//                    }
//                }
//            }
//        }
//
//        cout << "Edge\t\t Weight"<<endl;
//        int totalWeight = 0;
//        for (int i = 0; i < MAX_VERTICES; i++)
//        {
//            if (vertices[i].active && vertices[i].id_parent != -1) 
//            {
//                cout << vertices[i].id_parent << "   " << vertices[i].id << " \t\t" << vertices[i].key << endl;
//                totalWeight += vertices[i].key;
//            }
//        }
//        cout << "Total Length: " << totalWeight << endl;
//    }
//
//    ~Graph() 
//    {
//        delete[] vertices;
//        delete[] adjList;
//
//    }
//};
//
//int main()
//{
//    Graph obj;
//    int choice;
//    string name, type;
//    int id, source_id, destination_id, wei;
//
//    while (true) 
//    {
//        cout << "Enter 1 to input graph from file"<<endl;
//        cout << "Enter 2 to save graph to file"<<endl;
//        cout << "Enter 3 to add an edge" << endl;
//        cout << "Enter 4 to add a vertex"<<endl;
//        cout << "Enter 5 to display"<<endl;
//        cout << "Enter 6 to exit"<<endl;
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            cout << "Enter name of file: ";
//            cin >> name;
//            obj.loadFromFile(name);
//            break;
//        case 2:
//            cout << "Enter filename to save: ";
//            cin >> name;
//            obj.saveToFile(name);
//            break;
//        case 3:
//            cout << "Enter source ID: ";
//            cin >> source_id;
//            cout << "Enter destination ID: ";
//            cin >> destination_id;
//            cout << "Enter weight: ";
//            cin >> wei;
//            obj.insertEdge(source_id, destination_id, wei);
//            cout << "Edge included\n";
//            break;
//        case 4:
//            cout << "Enter Vertex ID: ";
//            cin >> id;
//            cout << "Enter Type: ";
//            cin.ignore();
//            getline(cin, type);
//            obj.insertVertex(id, type);
//            cout << "Vertex added"<<endl;
//            break;
//        case 5:
//            cout << "Graph is: "<<endl;
//            obj.generateGraph();
//            break;
//        case 6:
//            break;
//        default:
//            cout << "Invalid choice.\n";;;
//        }
//    }
//}
