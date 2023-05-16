//
//
//
#include <iostream>
#include "linkedList.h"
#include <string>

using namespace std;

template <class H>
class HashTable
{
private:
	int size;
	int maxSize;

public:
	HashTable()
	{
		size = 0;
		maxSize = 100;
		LinkedList<H>* dynamicArray = new LinkedList<H>[maxSize];
	}
	int hash(string key)
	{
		int keyLength = key.length();
		int summary = 0;
		for (int i = 0; i < keyLength; i++)
			summary = summary + (key[i] * (31 ^ (keyLength - (i+1))));
		summary = summary % maxSize;
		return summary;
	}
	void newNode(string key, H value)
	{
		if (dynamicArray->Head == NULL)
		{
			dynamicArray->Head->Data = value;
		}

	}
	ObjectInList<H>* searchByKey(string key) //dobry typ?
	{
		if (size == 0)
		{
			cout << "Your array is EMPTY!" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			if (i == hash(key))
				return dynamicArray[i];
		}
		return NULL;
	}
	void deleteAnElement(string key)
	{
		if (size == 0)
		{
			cout << "Your array is EMPTY!" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			if (i == hash(key))
			{
				delete dynamicArray[i];
				cout << "Data from index:" << i << "has been deleted." << endl;
				size--;
				return;
			}
		}
	}
	void deleteAll()
	{
		if (size == 0)
		{
			cout << "Your array is EMPTY!";
		}
		else
		{
			delete[]dynamicArray;
			size = 0;
			maxSize = 1;
		}
	}

};
int main()
{
	HashTable<int>* miesz = new HashTable<int>();
	miesz->newNode("abc", 10);
	miesz->deleteAll();
	return 0;
}