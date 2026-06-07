#include<iostream>
using namespace std;
int main()
{
	int size;
	cout << "enter the size of array:";
	cin >> size;
	int* arr = new int[size];
	for (int i=0;i<size;i++)
	{
		cout << "enter number:";
		cin >> arr[i];
	}

	int temp = 0;

	for (int i=0;i<size;i++)
	{
		temp = 1;
		for (int j=i+1;j<size;j++)
		{
			if (arr[i]==arr[j])
			{
				temp++;
			}
		}
		cout << "The number " << arr[i] << " is repeated:" << temp;
		i += temp-1;
		cout << endl;
	}
}