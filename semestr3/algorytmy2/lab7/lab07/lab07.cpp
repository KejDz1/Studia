//ALGO2 IS1 212A LAB07
//Kacper Burzyński
//bk50940@zut.edu.pl
#include <iostream>
#include <string>
using namespace std;

class HeapSort
{
public:
	int size;
	int maxSize;
	int* array;

	HeapSort() : size(0), maxSize(1), array(new int[maxSize]) {}
	HeapSort(int* tempArray, int tempSize, bool choice) : size(tempSize), maxSize(tempSize), array(tempArray)
	{
		if (choice == true)
		{
			for (int i = tempSize; i > 0; i--)
				kopcowanie_w_gore(i);
		}
		else
		{
			for (int i = 0; i < tempSize; i++)
				kopcowanie_w_dol(i);
		}

	}
	/*void insert(H value)
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

		if (i != 0)
			kopcowanie_w_gore(i);
	}
	*/
	int extractMax()
	{
		if (size == 0)
		{
			cout << "Your binary heap is empty...";
			return 0;
		}
		// pobranie roota i zamiana z ostatnim elementem

		int temp = array[0];
		array[0] = array[size - 1];

		size--;
		if (size != 1)
		{
			kopcowanie_w_dol(0);
			kopcowanie_w_dol(0);
		}
		cout << "Your extracted value is: " << temp << endl;
		return temp;
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
			int temp = array[i];
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
		int max;
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
		if (((2 * i) + 1) >= size)
			return;
		else
			kopcowanie_w_dol(i);
	};
	void sort()
	{
		int root;
		int* tempArr = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			root = extractMax();
			tempArr[maxSize - 1 - i] = root;
			displayArr();
		}
		for (int i = 0; i < size; i++)
		{
			tempArr[i] = array[i];
		}
		delete[] array;
		array = tempArr;
		size = maxSize;
	}
	void displayArr()
	{
		for (int i = 0; i < size; i++)
			cout << array[i] << "; ";
		cout << endl;
	}

};
void countSort(int* arrayToSort, int size, int range)
{	

	int* countArr = new int[range+1];
	int* sorted = new int[size];

	for (int i = 0; i <= range + 1; i++)	//zerowanie tablicy liczacej
		countArr[i] = 0;

	for (int i = 0; i < size; i++)	//zliczanie wystapien danych elementow z tablicy do sortowania
		++countArr[arrayToSort[i]];

	for (int i = 1; i <= range; i++) //aktualizacja counta 
		countArr[i] += countArr[i - 1];

	for (int i = size - 1; i >= 0; i--) //wstawienie elementow do nowej tablicy
		sorted[--countArr[arrayToSort[i]]] = arrayToSort[i];

	for (int i = 0; i < size; i++)	//przypisanie posortowanych elementow do oryginalnej tablicy
		arrayToSort[i] = sorted[i];

	for (int i = 0; i < size; i++)	// wypisywanie posortowanej tablicy
		cout << arrayToSort[i] << "; ";
	cout << endl;
	delete[] sorted, countArr;
}
void bucketSortINT(int* arrayToSort, int size, int range)
{
	int min = arrayToSort[0];
	int max = arrayToSort[0];

	for (int i = 1; i < size; i++)
	{
		if (min > arrayToSort[i])
			min = arrayToSort[i];
		if (max < arrayToSort[i])
			max = arrayToSort[i];
	}

	if (max > range)
	{
		cout << "Max element is out of range!" << endl;
		return;
	}

	const int numberOfBuckets = max - min + 1;	//wyznaczanie ilosci potrzebnych kubelkow
	int* buckets = new int[numberOfBuckets];	//tablica kubelkow

	for (int i = 0; i < numberOfBuckets; i++)	//zerowanie tablicy
		buckets[i] = 0;

	for (int i = 0; i < size; i++)	//przydzielanie elementow do kubelkow
		buckets[arrayToSort[i]-min]++; //arrayToSort[i]-min, poniewaz tablica numerowana jest od 0

	for (int i = 0; i < numberOfBuckets; i++)
		cout << buckets[i] << "; ";
	cout << endl;
	int* sorted = new int[size];
	int index = 0;
	for (int i = 0; i < numberOfBuckets; i++)	//przypisywanie elementow do posortowanej tablicy
	{
		while (buckets[i] > 0)
		{
			sorted[index] = i + min;
			buckets[i]--;
			index++;
		}
	}
		
		/*for(int j = buckets[i]; j >= 0 ; j--)
			sorted[index--] = buckets[i] + min;*/

	for (int i = 0; i < size; i++)	// wypisywanie posortowanej tablicy
		cout << sorted[i] << "; ";
	cout << endl;
	delete[] buckets, sorted;
}
template<class B>
void bucketSortTemplate(B* arrayToSort, int size, int range)
{

}
int main()
{
	const int tablicaSize = 5;
	int* tablica = new int[tablicaSize];
	for (int i = 0; i < tablicaSize; i++)
		tablica[i] = (i * 3 + 4);
	HeapSort kopiec(tablica, tablicaSize, true);
	kopiec.display();
	kopiec.sort();
	kopiec.display();
	kopiec.deleteAll();

	int tablica2[5] = { 1, 1, 2, 4, 0 };
	cout << endl;
	countSort(tablica2, tablicaSize, 4);
	cout << endl;
	bucketSortINT(tablica2, tablicaSize, 4);
	//delete[] tablica; //błąd
	return 0;
}