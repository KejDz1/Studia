#include <iostream>
#include <string>
using namespace std;

template <class H>
class Heap
{
private:
	int size;
	int maxSize;
	H* array;
public:

	Heap() : size(0), maxSize(1), array(new H[maxSize]) {}

	void insert(H value)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] == value)
			{
				cout << "This value (" << value << ") is in array!" << endl;
				return;
			}
		}

		if (size == maxSize)
		{
			maxSize *= 2;
			H* tempArray = new H[maxSize];
			for (int i = 0; i < size; i++)
			{
				tempArray[i] = array[i];
			}
			delete[] array;
			array = tempArray;
		}
		array[size] = value;
		int i = size;
		size++;

		//** fixing order
		if (i != 0)
			kopcowanie_w_gore(i);
	}
	void extractMax()
	{
		if (size == 0)
		{
			cout << "Your binary heap is empty...";
			return;
		}
		//** pobranie roota i zamiana z ostatnim elementem **\\

		H temp = array[0];
		array[0] = array[size-1];
		
		size--;

		//** fixing order 
		kopcowanie_w_dol(0);
		cout << "Your deleted value is: " << temp << endl;

	}
	void deleteAll()
	{
		if (size == 0)
			cout << "Your binary heap is empty..." << endl;
		else
		{
			delete[] array;
			size = 0;
			maxSize = 1;
		}
	}
	void display()
	{
		if (size == 0)
		{
			cout << "Your binary heap is empty..." << endl;
			return;
		}
		if (size <= 50)
		{
			cout << endl;
			cout << to_string(array[0]) << endl;
			int j = 2;
			int k = 0;
			for (int i = 1; i < size; i++)
			{
				k++;
				cout << to_string(array[i]) << "; ";
				if (k % j == 0)
				{
					cout << endl;
					k = 0;
					j *= 2;
				}
			}
		}
		else
		{
			cout << endl;
			cout << to_string(array[0]) << endl;
			int j = 2;
			int k = 0;
			for (int i = 1; i < 50; i++)
			{
				k++;
				cout << to_string(array[i]) << "; ";
				if (k % j == 0)
				{
					cout << endl;
					k = 0;
					j *= 2;
				}
			}
		}
		cout << endl;
	}
	void kopcowanie_w_gore(int i)
	{
		// (i-1) / 2 - index rodzica
		if (array[i] > array[(i - 1) / 2])
		{
			H temp = array[i];
			array[i] = array[(i - 1) / 2];
			array[(i - 1) / 2] = temp;
		}
		else
			return;

		i = ((i - 1) / 2);

		if (i != 0)
		{
			kopcowanie_w_gore(i);
		}

	}
	void kopcowanie_w_dol(int i)
	{
		// 2i+1 lewe dziecko
		// 2i+2 prawe dziecko
		H max;
		if (array[i] < array[(2 * i) + 1])
		{
			max = array[(2 * i) + 1];
			array[(2 * i) + 1] = array[i];
			array[i] = max;
			i = (2 * i) + 1;
		}
		else if (array[i] < array[(2 * i) + 2])
		{
			max = array[(2 * i) + 2];
			array[(2 * i) + 2] = array[i];
			array[i] = max;
			i = (2 * i) + 2;
		}
		else
			return;
		if (((2 * i) + 1) > size)
			return;
		else
			kopcowanie_w_dol(i);
	};
};
int main()
{
	Heap<int>* kopiec = new Heap<int>();
	kopiec->insert(3);
	kopiec->insert(2);
	kopiec->insert(5);
	kopiec->insert(8);
	kopiec->insert(2);


	kopiec->display();
	kopiec->extractMax();
	kopiec->display();

	kopiec->deleteAll();
	return 0;
}