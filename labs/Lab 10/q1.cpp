//#include <iostream>
//using namespace std;
//
//template <typename k, typename v>
//struct HeapItem
//{
//    k key;
//    v value;
//};
//
//template <typename k, typename v>
//class Heap
//{
//private:
//    HeapItem<k, v>* arr; 
//    int count;       
//    int size;      
//
//
//    void swapItems(HeapItem<k, v>& x, HeapItem<k, v>& y)
//    {
//        HeapItem<k, v> temp = x;
//        x = y;
//        y = temp;
//    }
//
//    void heapifyUp(int index)
//    {
//        if (index == 0)
//        {
//            return;
//        }
//
//        int parent = (index - 1) / 2;
//
//        if (arr[index].key < arr[parent].key)
//        {
//            swapItems(arr[index], arr[parent]);
//            heapifyUp(parent);
//        }
//    }
//
//    void increaseCapacity()
//    {
//        int newCount = count * 2;
//        HeapItem<k, v>* result = new HeapItem<k, v>[newCount];
//
//        for (int i = 0; i < size; i++)
//        {
//            result[i] = arr[i];
//        }
//
//        delete[] arr;
//        arr = result;
//        count = newCount;
//    }
//
//public:
//
//    Heap()
//    {
//        arr = nullptr;
//        count = 0;
//        size = 0;
//    }
//
//    Heap(int cap)
//    {
//        if (cap <= 0)
//        {
//            return;
//        }
//
//        count = cap;
//        arr = new HeapItem<k, v>[count];
//        size = 0;
//    }
//
//    void insert(k keyval, v val)
//    {
//        if (count == 0)
//        {
//            count = 1;
//            arr = new HeapItem<k, v>[count];
//        }
//
//        if (size == count)
//        {
//            increaseCapacity();
//        }
// 
//        arr[size]->key = keyval;
//        arr[size]->value = val;
//
//        heapifyUp(size);
//
//        size++;
//    }
//
//    void getMin(v val)
//    {
//        if (size <= 0)
//        {
//            cout << "Empty"<<endl;
//            return;
//        }
//
//        val = arr[0]->value;
//    }
//
//    void deleteMin()
//    {
//        if (size <= 0)
//        {
//            cout << "Empty" << endl;;
//            return;
//        }
//
//        arr[0] = arr[size - 1];
//        size--;
//
//        heapifyDown(0);
//    }
//
//    bool isEmpty()
//    {
//        return size == 0;
//    }
//
//    void display()
//    {
//        for (int i = 0; i < size; i++)
//        {
//            cout << arr[i]->value << "  ";
//        }
//        cout << endl;
//    }
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int main()
//{
//    Heap<int, int> heap(4);
//
//    heap.insert(10, 4);
//    heap.insert(5, 3);
//    heap.insert(7, 2);
//    heap.insert(3, 1);
//
//    heap.display();
//
//    int val;
//    heap.getMin(val);
//    cout << "Minimum value: " << val << endl;
//
//    heap.deleteMin();
//    heap.display();
//
//    cout << "Is heap empty " << heap.isEmpty();
//}
