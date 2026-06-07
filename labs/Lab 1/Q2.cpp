//#include<iostream>
//#include<stdexcept>
//using namespace std;
//template<typename T>
//class SafeArray
//{
//	T* arr;
//	int si;
//public:
//
//	SafeArray(int row)
//	{
//		si = row;
//		arr = new T[row];
//
//		for (int i=0;i<si;i++)
//		{
//			cout << "Enter value of array:";
//			cin >> arr[i];
//		}
//	}
//
//	~SafeArray()
//	{
//		delete[] arr;
//	}
//
//	int size()
//	{
//		return si;
//	}
//
//	SafeArray(SafeArray& other)
//	{
//		si = other.si;
//		arr = new T[si];
//		for (int i=0;i<si;i++)
//		{
//			arr[i] = other.arr[i];
//		}
//	}
//
//	SafeArray& operator=(SafeArray& other)
//	{
//		if (this==&other)
//		{
//			return *this;
//		}
//
//		delete[] arr;
//		si = other.si;
//		arr = new T[si];
//
//		for (int i=0;i<si;i++)
//		{
//			arr[i] = other.arr[i];
//		}
//
//		return*this;
//	}
//
//	T& operator[](int pos)
//	{
//		if (pos>=si || pos<0)
//		{
//			throw out_of_range("Position not found");
//		}
//		else
//		{
//			return arr[pos];
//		}
//	}
//};
//
//int main()
//{
//	int r;
//	cout << "Enter the size of array:";
//	cin >> r;
//	SafeArray<int> array(r);
//	SafeArray<int> array2 = array;
//
//	cout<<"The size of Array: "<< array.size()<<endl;
//	cout << "The size of Array: " << array2.size() << endl;
//	try
//	{
//		cout <<"The value is:"<< array[1] << endl;
//	}
//
//	catch (const out_of_range& e)
//	{
//		cout << "Exception Found :" << e.what();
//	}
//
//	cout << endl;
//
//	try
//	{
//		cout << array2[5] << endl;
//	}
//
//	catch (const out_of_range& e)
//	{
//		cout << "Exception Found :" << e.what();
//	}
//}