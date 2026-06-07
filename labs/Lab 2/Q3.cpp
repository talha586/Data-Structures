//#include<iostream>
//using namespace std;
//int main()
//{
//	int size,key;
//	
//	cout << "Enter the size of array:";
//	cin >> size;
//	cout << "Enter the no of smallest position you want to find:";
//	cin >> key;
//
//	int* arr = new int[size];
//
//	for (int i=0;i<size;i++)
//	{
//		cout << "enter number:";
//		cin >> arr[i];
//	}
//
//	for (int i=0;i<size-1;i++)
//	{
//		for (int j=0;j<size-i-1;j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				swap(arr[j+1],arr[j]);
//			}
//		}
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i]<<" ";
//	}
//	cout << endl;
//	cout << "The " << key << " smallest value :" << arr[key-1];
//	delete[] arr;
//}