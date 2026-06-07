//#include <iostream>
//#include <string>
//#include <cassert>
//#include <fstream>
//
//using namespace std;
//
//template<typename v>
//class HashItem
//{
//public:
//    int key;
//    v value;
//    int status; 
//
//    HashItem()
//    {
//        status = 0;
//    }
//};
//
//template<typename v>
//class HashMap
//{
//protected:
//    HashItem<v>* hashArray;
//    int capacity;
//    int currentElements;
//
//    virtual int getNextCandidateIndex(int key, int i)
//    {
//
//        return (key + i) % capacity;
//    }
//
//    int Hash(int key) const
//    {
//        return key % capacity;
//    }
//
//
//    void doubleCapacity()
//    {
//        int oldCapacity = capacity;
//        capacity *= 2;
//
//        HashItem<v>* oldArray = hashArray;
//        hashArray = new HashItem<v>[capacity];
//        currentElements = 0;
//
//
//        for (int i = 0; i < oldCapacity; i++)
//        {
//            if (oldArray[i].status == 2)
//            {
//                insert(oldArray[i].key, oldArray[i].value);
//            }
//        }
//
//        delete[] oldArray;
//    }
//
//public:
//
//    HashMap()
//    {
//        capacity = 10;
//        currentElements = 0;
//        hashArray = new HashItem<v>[capacity];
//    }
//
//
//    HashMap(int cap)
//    {
//        assert(cap > 1);
//        capacity = cap;
//        currentElements = 0;
//        hashArray = new HashItem<v>[capacity];
//    }
//
//    void insert(int key, v value)
//    {
//     
//        float loadFactor = (float)currentElements / capacity;
//
//        if (loadFactor >= 0.75f)
//        {
//            doubleCapacity();
//        }
//
//        int index = Hash(key);
//        int i = 1;
//        int firstDeletedIndex = -1; 
//
//        while (hashArray[index].status != 0)
//        {   
//            if (hashArray[index].status == 2 && hashArray[index].key == key)
//            {
//                hashArray[index].value = value;
//                return;
//            }
//
//            if (hashArray[index].status == 1 && firstDeletedIndex == -1)
//            {
//                firstDeletedIndex = index;
//            }
//
//            index = getNextCandidateIndex(key, i++);
//        }
//
//        if (firstDeletedIndex != -1)
//        {
//            index = firstDeletedIndex;
//        }
//
//        hashArray[index].key = key;
//        hashArray[index].value = value;
//        hashArray[index].status = 2;
//        currentElements++;
//    }
//
//
//    bool deleteKey(int key)
//    {
//        int index = Hash(key);
//        int i = 1;
//
//        while (hashArray[index].status != 0)
//        {
//            if (hashArray[index].status == 2 && hashArray[index].key == key)
//            {
//                hashArray[index].status = 1;
//                return true;
//            }
//
//            index = getNextCandidateIndex(key, i++);
//        }
//
//        return false;
//    }
//
//
//    v* get(int key)
//    {
//        int index = Hash(key);
//        int i = 1;
//
//        while (hashArray[index].status != 0)
//        {
//            if (hashArray[index].status == 2 && hashArray[index].key == key)
//            {
//                return &hashArray[index].value;
//            }
//
//            index = getNextCandidateIndex(key, i++);
//        }
//
//        return nullptr;
//    }
//
//
//    ~HashMap()
//    {
//            delete[] hashArray;
//            hashArray = nullptr;
//    }
//};
//
//template<typename v>
//class QHashMap : public HashMap<v>
//{
//protected:
//    int getNextCandidateIndex(int key, int i) override
//    {
//        return (key % this->capacity + 3 * i +  2 * (i * i)) % this->capacity;
//    }
//};
//
//template<typename v>
//class DHashMap : public HashMap<v>
//{
//protected:
//    int getNextCandidateIndex(int key, int i) override
//    {
//        int prime = 7;
//        int first_value = key % this->capacity;
//        int second_value = (prime - (key % prime));
//
//        return (first_value + i * second_value) % this->capacity;
//    }
//};
//
//void populateHash(string filename, HashMap<string>*hash)
//{
//    ifstream file(filename);
//    
//    if (!file.is_open())
//    {
//        cout << "Error: Could not open file " << filename << endl;
//        return;
//    }
//
//    int id;
//    string name;
//
//    while (file >> id >> name) 
//    {
//        hash->insert(id, name);
//    }
//
//    file.close();
//}
//
//int main()
//{
//    HashMap<string>* obj;
//
//    obj = new HashMap<string>;
//    populateHash("student.txt", obj);
//
//    if (obj->get(9))
//    {
//        cout << "Inserted Linear HashMap" << *obj->get(9) << endl;
//    }
//
//    else
//    {
//        cout << "Key 9 not found" << endl;
//    }
//
//    obj->deleteKey(9);
//    assert(obj->get(9) == nullptr);
//    delete obj;
//
//    obj = new QHashMap<string>;
//    populateHash("student.txt", obj);
//
//    if (obj->get(98))
//    {
//        cout << "Inserted Quadratic HashMap: " <<* obj->get(98) << endl;
//    }
//
//    else
//    {
//        cout << "Key 98 not found" << endl;
//    }
//
//    obj->deleteKey(98);
//    assert(obj->get(98) == nullptr);
//    delete obj;
//
//    obj = new DHashMap<string>;
//    populateHash("student.txt", obj);
//
//    if (obj->get(101))
//    {
//        cout <<"Inserted Double HashMap: "<< * obj->get(101) << endl;
//
//    }
//
//    else
//    {
//        cout << "Key 101 not found" << endl;
//    }
//
//    obj->deleteKey(101);
//    assert(obj->get(101) == nullptr);
//
//    delete obj;
//}