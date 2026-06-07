//#include <iostream>
//using namespace std;
//
//void printCombination(int arr[], int n, int r, int index, int data[], int i) {
//
//    if (index == r) {
//        for (int j = 0; j < r; j++)
//        {
//            cout << data[j] << " ";
//        }
//        cout << endl;
//        return;
//    }
//
//    if (i >= n)
//    {
//        return;
//    }
//
//    data[index] = arr[i];
//    printCombination(arr, n, r, index + 1, data, i + 1);
//
//    printCombination(arr, n, r, index, data, i + 1);
//}
//
//void combination(int arr[], int n, int r) 
//{
//    int* data = new int[r];
//    printCombination(arr, n, r, 0, data, 0);
//    delete[] data;
//}
//
//int main() 
//{
//    int arr[4] = { 1, 2, 3, 4 };
//    int n = 4;
//    int r = 2;
//
//    cout << "Combinations of size " << r << ":\n";
//    combination(arr, n, r);
//}