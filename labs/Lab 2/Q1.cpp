//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int size;
//    cout << "Enter size of array: ";
//    cin >> size;
//
//    int* arr = new int[size];
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << "Enter number : ";
//        cin >> arr[i];
//    }
//    int p_num = 0, n_num = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] < 0)
//        {
//            n_num++;
//
//        }
//        else
//        {
//            p_num++;
//        }
//    }
//
//    int* p_arr = new int[p_num];
//    int* n_arr = new int[n_num];
//
//    int y = 0, z = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] < 0)
//        {
//            n_arr[z++] = arr[i];
//        }
//        else
//        {
//            p_arr[y++] = arr[i];
//        }
//    }
//
//    for (int i=0;i<size;i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    int i = 0;
//    y = 0;
//    z = 0;
//
//    while (y < p_num && z < n_num && i < size)
//    {
//        arr[i++] = p_arr[y++];
//        arr[i++] = n_arr[z++];
//    }
//
//    while (y < p_num && i < size)
//    {
//        arr[i++] = p_arr[y++];
//    }
//    while (z < n_num && i < size)
//    {
//        arr[i++] = n_arr[z++];
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//
//    delete[] arr;
//    delete[] p_arr;
//    delete[] n_arr;
//}
