//#include<iostream>
//using namespace std;
//class PascaleTriangle
//{
//private:
//	int** ptr;
//	int n;
//public:
//	PascaleTriangle(int r)
//	{
//		n = r;
//
//		ptr = new int*[n];
//
//		for (int i=0;i<n;i++)
//		{
//			ptr[i] = new int[i+1];
//		}
//
//		for (int i=0;i<n;i++)
//		{
//            for (int j=0;j<=i;j++)
//            {
//                if (j==0 || j==i)
//                {
//                    ptr[i][j] = 1;
//                }
//                else
//                {
//                    ptr[i][j] = ptr[i-1][j-1] + ptr[i-1][j];
//                }
//            }
//		}
//	}
//
//	void display()
//	{
//		cout << "SIMPLE DISPLAY:" << endl;
//		for (int i=0;i<n;i++)
//		{
//			for (int j=0;j<=i;j++)
//			{
//				cout << ptr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	void invertedDisplay()
//	{
//		cout << endl;
//		cout << "INVERTED DISPLAY:"<<endl;
//		for (int i=n-1;i>=0;i--)
//		{
//			//for (int j=0;j<=i;j++)
//			{
//				cout << ptr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	~PascaleTriangle()
//	{
//		for (int i=0;i<n;i++)
//		{
//			delete [] ptr[i];
//		}
//		delete [] ptr;
//	}
//
//	PascaleTriangle(PascaleTriangle& other)
//	{
//		n = other.n;
//		ptr = new int* [n];
//		for (int i=0;i<n;i++)
//		{
//			ptr[i] = new int [i+1];
//			for (int j=0;j<=i;j++)
//			{
//				ptr[i][j] = other.ptr[i][j];
//			}
//		}
//		
//	}
//
//
//
//};
//int main()
//{
//	int row;
//	cout << "Enter the value of rows:";
//	cin >> row;
//	PascaleTriangle tri(row);
//	tri.display();
//    tri.invertedDisplay();
//	PascaleTriangle tri2=tri;
//	tri2.display();
//	tri2.invertedDisplay();
//}
