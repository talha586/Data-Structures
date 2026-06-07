//#include<iostream>
//#include<list>
//#include<queue>
//using namespace std;
//
//class Graph
//{
//private:
//	int totalVertices;
//	list<int>* adjList;
//
//public:
//	
//	Graph(int n) 
//	{
//		totalVertices = n;
//		adjList = new list<int>[totalVertices];
//	}
//
//	void TakeInput(int n,int w)
//	{
//		adjList[n].push_back(w);
//	}
//
//	void DFS(int curr, bool visited[], int path[], int pathLen)
//	{
//		visited[curr] = true;
//		path[pathLen] = curr;
//
//		for (int i=0;i<=pathLen;i++)
//		{
//			cout << path[i] << " ";
//		}
//		cout << endl;
//
//		list<int> temp = adjList[curr];
//
//		while (!temp.empty())
//		{
//			int x = temp.front();
//			temp.pop_front();
//
//			if (!visited[x])
//			{
//				DFS(x, visited, path, pathLen + 1);
//			}
//		}
//	}
//
//	void ExploreDFS(int start)
//	{
//		bool* visited = new bool[totalVertices];
//
//		int* path = new int[totalVertices];
//
//		for (int i=0;i<totalVertices;i++)
//		{
//			visited[i] = false;
//		}
//
//		DFS(start,visited,path,0);
//
//		delete[] visited;
//		delete[] path;
//
//	}
//
//	void ExploreBFS(int start)
//	{
//		bool* visited = new bool[totalVertices];
//
//		for (int i=0;i<totalVertices;i++)
//		{
//			visited[i] = false;
//		}
//
//		queue<int*> q;
//		queue<int> length;
//		
//		int* startPath = new int[totalVertices];
//
//		startPath[0] = start;
//		visited[start] = true;
//
//		q.push(startPath);
//		length.push(1);
//
//		while (!q.empty())
//		{
//			int* currPath = q.front();
//			q.pop();
//			int len = length.front();
//			length.pop();
//			int last = currPath[len - 1];
//
//			for (int i = 0; i < len; i++)
//			{
//				cout << currPath[i] << " ";
//			}
//			cout << endl;
//
//			list<int> temp = adjList[last];
//
//			while (!temp.empty())
//			{
//				int x = temp.front();
//				temp.pop_front();
//				
//				if (!visited[x])
//				{
//					visited[x] = true;
//					
//					int* newPath = new int[totalVertices];
//
//					for (int i=0;i<len;i++)
//					{
//						newPath[i] = currPath[i];
//					}
//
//					newPath[len] = x;
//					q.push(newPath);
//					length.push(len+1);
//				}
//			}
//			delete[] currPath;
//		}
//		delete[] visited;
//
//
//	}
//
//	~Graph()
//	{
//		delete[] adjList;
//	}
//
//};
//
//int main()
//{
//
//    Graph obj(4);
//
//    obj.TakeInput(0, 1);
//    obj.TakeInput(0, 2);
//
//    obj.TakeInput(1, 2);
//    obj.TakeInput(2, 0);
//    obj.TakeInput(2, 3);
//    obj.TakeInput(3, 3);
//
//    cout << "BFS Traversal:" << endl;
//    obj.ExploreBFS(0);
//
//    cout << "DFS Traversal:"<<endl;
//    obj.ExploreDFS(0);
//
//
//}