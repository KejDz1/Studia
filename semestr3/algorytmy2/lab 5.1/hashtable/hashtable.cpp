#include <iostream>

using namespace std;

template <class H>
class HashNode
{
public:
    string key;
    H value;
    HashNode<H>* Next;
    HashNode<H>* Previous;

    HashNode() : Next(nullptr), Previous(nullptr) {}

};
template <class H>
class HashList
{
public:
    HashNode<H>* Head;
    HashNode<H>* Tail;
    HashList<H>() : Head(nullptr), Tail(nullptr) {}

    void addOnBack(string node_key, H node_value)
    {
        HashNode<H>* obj = new HashNode<H>;
        obj->key = node_key;
        obj->value = node_value;
        if (Tail == nullptr)
        {
            Head = obj;
            Tail = obj;
        }
        else
        {
            Tail->Next = obj;
            obj->Previous = Tail;
            Tail = obj;
        }
    }
    void displayList()
    {
        HashNode<H>* temp = Head;
        while (temp != nullptr)
        {
            cout << "<" << temp->key << ", " << temp->value << ">, ";
            temp = temp->Next;
        }
    }
    
};
template <class H>
class HashTable
{
private:
    int size;
    int max_size;
    HashList<H>** hashTable;
public:

    HashTable() 
    {
        size = 0;
        max_size = 1;
        hashTable = new HashList<H>*[max_size];
        for (int i = 0; i < max_size; i++)
            hashTable[i] = nullptr;
    }

    int hash(string key)
    {
        int keyLength = key.length();
        int summary = 0;
        for (int i = 0; i < keyLength; i++)
            summary = summary + (int(key[i]) * (31 ^ (keyLength - (i + 1))));
        summary = summary % max_size;
        return summary;
    }
    void insertNode(string node_key, H node_value)
    {

        if (size == max_size)
        {
            int new_hash;
            max_size *= 2;
            HashList<H>** temp = new HashList<H>*[max_size]();
            for (int i = 0; i < max_size; i++)
                temp[i] = nullptr;
            for (int i = 0; i < size; i++)
            {
                HashNode<H>* elem = hashTable[i]->Head;
                while(elem != nullptr)
                {
                    int hash_index = hash(elem->key);
                    if (temp[hash_index] == nullptr)
                        temp[hash_index] = new HashList<H>;
                    temp[hash_index]->addOnBack(elem->key, elem->value);
                    elem = elem->Next;
                }
            }
            
           delete[] hashTable;
           hashTable = temp;
        }
        int hash_index = hash(node_key);
        //HashList<H>* obj;
        //obj = hashTable[hash_index];
       // obj->addOnBack(node_key, node_value);
       size++;
       if (hash_index >= 0 && hash_index < size)
       {
           if (hashTable[hash_index] == nullptr)
               hashTable[hash_index] = new HashList<H>;
           hashTable[hash_index]->addOnBack(node_key, node_value);
       }
        
    }
    HashList<H>* searchByKey(string node_key)
    {
        int hash_index = hash(node_key);
        HashList<H>* obj;
        obj = hashTable[hash_index];
        if (obj->Head == nullptr)
        {
            cout << "Odnaleziony element jest pusty!" << endl;
            return obj;
        }
        return obj;
    }
    void deleteElement(string node_key)
    {
        HashList<H>* obj;
        int hash_index = hash(node_key);
        obj = hashTable[hash_index];
        if (obj->Head == nullptr)
        {
            cout << "Element jest pusty!" << endl;
            return;
        }
        while (obj->Head != nullptr)
        {
            HashNode<H>* temp;
            temp = obj->Head;
            obj->Head = temp->Next;
            delete temp;
        }
        size--;
        cout << "Deleted index: " << hash_index << endl;
    }
    void deleteAll()
    {
        HashNode<H>* obj;
        for (int i = 0; i < size; i++)
        {
            if (hashTable[i] != nullptr)
            {
                obj = hashTable[i]->Head;
                while (obj->Next != nullptr)
                {
                    obj = obj->Next;
                    delete obj->Previous;
                }
            }
            
        }
        cout << "Deleted." << endl;
        size = 0;
        max_size = 1;
    }
    void displayAll()
    {
        if (hashTable == nullptr)
        {
            cout << "It's empty, nothing here..." << endl;
            return;
        }
        cout << "Max size: " << max_size << endl;
        cout << "Size: " << size << endl;
        int numberOfLists = 0;
        HashList<H>* obj;
        for (int i = 0; i < max_size; i++)
        {
            obj = hashTable[i];
            if (obj != nullptr)
            {
                cout << "[" << i << "]: "; 
                obj->displayList();
                cout << endl;
                numberOfLists++;
            }
        }
        cout << "Empty elemnts: " << max_size-numberOfLists << endl;
        cout << "Non empty elemnts: " << numberOfLists << endl;
    }
};
int main()
{
    HashTable<int>* hasz = new HashTable<int>();
    hasz->insertNode("abc", 2);
    hasz->insertNode("rtg", 5);
    hasz->insertNode("rag", 10);
    hasz->insertNode("rtg", 10);
    hasz->insertNode("elo", 10); // wypierdala sie chuj



    hasz->displayAll();
    hasz->deleteAll();
    return 0;
}