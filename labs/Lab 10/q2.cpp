//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class Student
//{
//private:
//    int rollNumber;
//    string name;
//    float cgpa;
//
//public:
//    Student()
//    {
//        rollNumber = 0;
//        name = "";
//        cgpa = 0;
//    }
//
//    Student(int r, string n, float c)
//    {
//        rollNumber = r;
//        name = n;
//        cgpa = c;
//    }
//
//    void setRollNumber(int r)
//    {
//        rollNumber = r; 
//    }
//
//    void setName(string n) 
//    {
//        name = n; 
//    }
//
//    void setCgpa(float c)
//    {
//        cgpa = c;
//    }
//
//    int getRollNumber()
//    {
//        return rollNumber; 
//    }
//
//    string getName()
//    {
//        return name;
//    }
//
//    float getCgpa()
//    { 
//        return cgpa; 
//    }
//
//    friend ostream& operator<<(ostream& cout, Student& s)
//    {
//        cout << "Roll No: " << s.rollNumber << " Name: " << s.name << " CGPA: " << s.cgpa;
//        return cout;
//    }
//};
//
//template <typename K, typename V>
//struct HeapItem
//{
//    K key;
//    V value;
//};
//
//template <typename K, typename V>
//class Heap
//{
//private:
//    HeapItem<K, V>* arr;
//    int count;
//    int size;
//
//    void swapItems(HeapItem<K, V>& a, HeapItem<K, V>& b)
//    {
//        HeapItem<K, V> temp = a;
//        a = b;
//        b = temp;
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
//    void heapifyDown(int index)
//    {
//        int left = 2 * index + 1;
//        int right = 2 * index + 2;
//        int smallest = index;
//
//        if (left < size && arr[left].key < arr[smallest].key)
//        {
//            smallest = left;
//
//        }
//        if (right < size && arr[right].key < arr[smallest].key)
//        {
//            smallest = right;
//        }
//
//        if (smallest != index)
//        {
//            swapItems(arr[index], arr[smallest]);
//            heapifyDown(smallest);
//        }
//    }
//
//    void doubleCapacity()
//    {
//        int newCount;
//        if (count == 0)
//        {
//            newCount = 1;
//        }
//        else
//        {
//            newCount = count * 2;
//        }
//
//        HeapItem<K, V>* newArr = new HeapItem<K, V> [newCount];
//        
//        for (int i = 0; i < size; i++)
//        {
//            newArr[i] = arr[i];
//        }
//        
//        delete[] arr;
//        arr = newArr;
//        count = newCount;
//    }
//
//public:
//
//
//    Heap()
//    {
//        arr = nullptr;
//        count = 0;
//        size = 0;
//    }
//
//    Heap(int c)
//    {
//        count = c;
//        arr = new HeapItem<K, V>[count];
//        size = 0;
//    }
//
//    void insert(K key, V value)
//    {
//        if (size == count)
//        {
//            doubleCapacity();
//        }
//
//        arr[size].key = key;
//
//        arr[size].value = value;
//        
//        heapifyUp(size);
//        
//        size++;
//    }
//
//    void getMin(V& val)
//    {
//        if (size <= 0)
//        {
//            cout << "empty" << endl;
//            return;
//        }
//        val = arr[0].value;
//    }
//
//    void deleteMin()
//    {
//        if (size <= 0)
//        {
//            cout << "empty" << endl;
//            return;
//        }
//
//        arr[0] = arr[size - 1];
//        
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
//    int size() 
//    {
//        return size;
//    }
//};
//
//void Input(string fileName, Heap<int, Student>& stdHeap)
//{
//    ifstream file(fileName.c_str());
//    if (!file)
//    {
//        cout << "error opening file" << endl;
//        return;
//    }
//
//    int roll;
//    string name;
//    float cgpa;
//
//    while (file >> roll >> name >> cgpa)
//    {
//        Student s(roll, name, cgpa);
//        stdHeap.insert(roll, s);
//    }
//
//    file.close();
//}
//
//void sortDescending(Heap<int, Student>& heap)
//{
//    Student s;
//    int size = heap.size();
//    Student* sorted = new Student[size];
//    int index = size - 1;
//
//    while (!heap.isEmpty())
//    {
//        heap.getMin(s);
//
//
//
//        sorted[index--] = s;
//
//        heap.deleteMin();
//    }
//
//    cout << endl << "Students :" << endl;
//    for (int i = 0; i < size; i++)
//    {
//        cout << sorted[i] << endl;
//    }
//
//
//    delete[] sorted;
//}
//
//void ByCgpa(Heap<float, Student>& sec1, Heap<float, Student>& sec2)
//{
//    Heap<float, Student> merged;
//    Student s;
//
//    while (!sec1.isEmpty())
//    {
//        sec1.getMin(s);
//        merged.insert(s.getCgpa(), s);
//        sec1.deleteMin();
//    }
//    while (!sec2.isEmpty())
//    {
//        sec2.getMin(s);
//        merged.insert(s.getCgpa(), s);
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
//        sec2.deleteMin();
//    }
//
//    cout << endl << "Students:" << endl;
//    while (!merged.isEmpty())
//    {
//        merged.getMin(s);
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
//        cout << s << endl;
//        merged.deleteMin();
//    }
//}
//
//
//    while (!sec2.isEmpty())
//    {
//        sec2.getMin(s);
//        merged.insert(s.getCgpa(), s);
//
//
//        sec2.deleteMin();
//    }
//
//    cout <<  "Students:" << endl;
//
//
//    while (!merged.isEmpty())
//    {
//        merged.getMin(s);
//        cout << s << endl;
//        merged.deleteMin();
//    }
//}

