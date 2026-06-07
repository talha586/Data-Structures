//#include<iostream>
//using namespace std;
//template<typename v>
//class HashItem 
//{
//
//public:
//    int key;
//    int status;
//    v value;
//
//    HashItem() : key(0), status(0), value(0)
//    { }
//    
//    HashItem(int k, int s, v val) : key(k), status(s), value(val)
//    { }
//};
//
//template<typename v>
//class HashMap
//{
//
//protected:
//    HashItem<v>* hashArray;
//    int capacity;
//    int currentElement;
//
//    virtual int getNextCandidateIndex(int key, int i) = 0;
//
//    void DoubleCapacity() 
//    {
//        int oldCapacity = capacity;
//        capacity = capacity * 2;
//
//        HashItem<v>* oldArray = hashArray;
//        hashArray = new HashItem<v>[capacity];
//        currentElement = 0;
//
//        for (int i = 0; i < oldCapacity; i++) 
//        {
//            if (oldArray[i].status == 2) 
//            {
//
//                Insert(oldArray[i].key, oldArray[i].value);
//            }
//        }
//
//        delete[] oldArray;
//    }
//
//public:
//    HashMap() : capacity(10), currentElement(0)
//    {
//
//        hashArray = new HashItem<v>[capacity];
//    
//    }
//
//    HashMap(int capa) : capacity(capa), currentElement(0) 
//    {
//
//        hashArray = new HashItem<v>[capacity];
//    }
//
//    int Hash(int k) 
//    {
//        return (k % capacity);
//    }
//
//    void Insert(int k, v val) 
//    {
//        float loadFactor = static_cast<float>(currentElement / capacity);
//
//
//        if (loadFactor >= 0.75) 
//        {
//
//            DoubleCapacity();
//        }
//
//        int index = Hash(k);
//        
//        int i = 1;
//
//        while (hashArray[index].status == 2)
//        {
//            index = getNextCandidateIndex(k, i++);
//
//            if (index >= capacity)
//            {
//                index %= capacity;
//            }
//        }
//
//
//        hashArray[index].key = k;
//        hashArray[index].value = val;
//        hashArray[index].status = 2;
//        currentElement++;
//
//    }
//
//    bool deleteKey(int k) 
//    {
//
//        for (int i = 0; i < capacity; i++) 
//        {
//
//            if (hashArray[i].key == k && hashArray[i].status == 2) 
//            {
//                hashArray[i].status = 1;
//                currentElement--;
//
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    v* get(int k) 
//    {
//
//        for (int i = 0; i < capacity; i++) 
//        {
//            if (hashArray[i].key == k && hashArray[i].status == 2) 
//            {
//
//                return &hashArray[i].value;
//            }
//        }
//        return nullptr;
//    }
//
//    ~HashMap() 
//    {
//
//        delete[] hashArray;
//    }
//};
//
//template<typename v>
//class LinearHash : public HashMap<v> 
//{
//protected:
//    int getNextCandidateIndex(int k, int i) override
//    {
//        return (k + i) % this->capacity;
//    }
//};
//
//int main() {
//    LinearHash<int> obj;
//
//    obj.Insert(10, 100);
//    obj.Insert(20, 200);
//    obj.Insert(30, 300);
//    obj.Insert(40, 400);
//
//    cout << "Value at key 20: ";
//
//    int* val = obj.get(20);
//
//    if (val)
//    {
//        cout << *val << endl;
//    }
//
//    else
//    {
//        cout << "Key not found" << endl;
//}
//
//    cout << "Deleting key 30: ";
//
//    if  (obj.deleteKey(30))
//    {
//        cout << "Deleted successfully" << endl;
//    }
//
//    else 
//    {
//        cout << "Key not found" << endl;
//    }
//
//    cout << "Trying to get deleted key 30: ";
//
//}
