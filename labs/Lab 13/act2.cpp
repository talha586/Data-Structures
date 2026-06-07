//#include<iostream>
//#include<list>
//using namespace std;
//
//class Vertex
//{
//public:
//	int value;
//	bool visit;
//
//	Vertex()
//	{
//		value = 0;
//		visit = false;
//	}
//
//};
//
//class Graph
//{
//	int totalVertice;
//	list<Vertex>* adjList;
//
//public:
//
//	Graph(int n)
//	{
//
//		totalVertice = n;
//		adjList = new list<Vertex>[totalVertice];
//
//		for (int i=0;i<totalVertice;i++)
//		{
//			Vertex v;
//			v.value = 0;
//			v.visit = false;
//
//			adjList[i].push_back(v);
//
//		}
//
//	}
//
//	void TakeVertexInput(int n,int w)
//	{
//		Vertex v;
//		v.value = w;
//		v.visit = false;
//
//		adjList[n].push_back(v);
//
//	}
//
//	void DFS(int start)
//	{
//		adjList[start].front().visit = true;
//
//		cout << start << " ";
//		list<Vertex> temp = adjList[start];
//		temp.pop_front();
//		while (!temp.empty())
//		{
//			int x = temp.front().value;
//			temp.pop_front();
//			
//			if (!adjList[x].front().visit)
//			{
//				DFS(x);
//			}
//		}
//	}
//
//	void ResetVisit()
//	{
//		for (int i=0;i<totalVertice;i++)
//		{
//			adjList[i].front().visit = false;
//
//		}
//	}
//
//	void DFSspanningTree(int start)
//	{
//		adjList[start].front().visit = true;
//
//		list<Vertex> temp = adjList[start];
//		temp.pop_front();
//		while (!temp.empty())
//		{
//			int x = temp.front().value;
//			temp.pop_front();
//
//			if (!adjList[x].front().visit)
//			{
//				cout << start << "->"<< x << endl;
//				DFSspanningTree(x);
//			}
//		}
//
//	}
//
//};
//
//int main()
//{
//	Graph g(6);
//
//	g.TakeVertexInput(0, 1);
//	g.TakeVertexInput(0, 2);
//	g.TakeVertexInput(1, 3);
//	g.TakeVertexInput(1, 4);
//	g.TakeVertexInput(2, 5);
//	g.TakeVertexInput(3, 5);
//
//	cout << "DFS : ";
//	g.DFS(0);
//	cout << endl;
//	cout << "Spanning Tree: " << endl;
//	g.ResetVisit();
//	g.DFSspanningTree(0);
//
//}