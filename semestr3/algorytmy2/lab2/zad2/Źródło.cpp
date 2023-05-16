#include <iostream>
#include <time.h>
#include <string> 

using namespace std;

template <class A>

class DynamicArray
{
private:
	int Size;
	int MaxSize;
	A *Array;

public:
	DynamicArray()
	{
		Size = 0;
		MaxSize = 1;
		Array = new A[MaxSize];
	}


	void AddLast(A data)
	{
		if (Size == MaxSize)
		{
			MaxSize *= 2;
			A* arr = new A[MaxSize];
			for (int i = 0; i < Size; i++)
			{
				arr[i] = Array[i];
			}
			delete [] Array;
			Array = arr;
		}		
		Array[Size] = data;
		Size++;
	}

	A DisplayByIndex(int index)
	{
		return Array[index];
	}

	void ChangeValueByIndex(int index, A value)
	{
		Array[index] = value;
	}

	void DeleteAll()
	{
		if (Size == 0)
		{
			cout << "Your array is empty!";
		}
		else
		{
		delete[]Array;
		Size = 0;
		MaxSize = 1;
		}
	}

	void DisplayWholeArray()
	{
		if (Size <= 50)
		{
			for (int i = 0; i < Size; i++)
			{
				cout << to_string(Array[i]) << ";  ";
			}
			cout << "\n";
		}
		else
		{
			for (int i = 0; i < 50; i++)
			{
				cout << to_string(Array[i]) << ";  ";
			}
		}
	}
	void BubbleSort()
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = 0; j < Size - i - 1; j++)
			{
				if(Array[j] > Array[j+1])
					swap(Array[j], Array[j + 1]);
			}
		}
	}
};

int main()
{
	DynamicArray<int>* Tablica = new DynamicArray<int>();
	Tablica->AddLast(10);
	Tablica->AddLast(5);
	Tablica->AddLast(20);
	Tablica->AddLast(30);
	Tablica->AddLast(3);


	Tablica->DisplayWholeArray();

	Tablica->BubbleSort();
	Tablica->DisplayWholeArray();

	Tablica->DeleteAll();
	return 0;
}