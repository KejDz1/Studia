#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
public:

	T Data;

	TreeNode<T>* Parent;
	TreeNode<T>* Left;
	TreeNode<T>* Right;

	TreeNode(T value) :Data(value), Parent(nullptr), Left(nullptr), Right(nullptr) {}
};

template<class T>

class Tree
{
private:
	int Size = 0;
public:
	TreeNode<T>* Root;
	Tree() :Root(nullptr) {}

	void insertNode(T data)
	{
		if (Root == nullptr)
		{
			Root = new TreeNode<T>(data);
		}
		else
		{
			TreeNode<T>* obj = Root;
			while (true)
			{
				if (data < obj->Data)
				{
					if (obj->Left == nullptr)
					{
						obj->Left = new TreeNode<T>(data);
						obj->Left->Parent = obj;
						break;
					}
					else
					{
						obj = obj->Left;
					}
				}
				else if (data > obj->Data)
				{
					if (obj->Right == nullptr)
					{
						obj->Right = new TreeNode<T>(data);
						obj->Right->Parent = obj;

						break;
					}
					else
					{
						obj = obj->Right;
					}
				}
				else
				{
					break; // juz istnieje node z ta dana
				}
			}
		}
	}
	TreeNode<T>* search(T data)
	{
		if (Root->Data == data)
		{
			return Root;
		}
		else
		{
			TreeNode<T>* obj = Root;
			while (true)
			{
				if (data < obj->Data)
				{
					if (obj->Left == nullptr)
					{
						cout << "NULL";
						break;
					}
					else
					{
						if (obj->Left->Data == data)
						{
							return obj->Left;
						}
						else
						{
							obj = obj->Left;
						}
					}
				}
				else if (data > obj->Data)
				{
					if (obj->Right == nullptr)
					{
						cout << "NULL";
						break;
					}
					else
					{
						if (obj->Right->Data == data)
						{
							return obj->Right;
						}
						else
						{
							obj = obj->Right;
						}
					}
				}
				else
				{
					cout << "NULL";
					break;
				}
			}
		}
	}
	void preorder(TreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		cout << obj->Data << ", ";
		preorder(obj->Left);
		preorder(obj->Right);	
	}
	void inorder(TreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		inorder(obj->Left);
		cout << obj->Data << ", ";
		inorder(obj->Right);
	}
	TreeNode<T>* lowestValue(TreeNode<T>* obj)
	{
		TreeNode<T>* temporary = obj;
		while (temporary->Left != NULL) {
			temporary = temporary->Left;
		}
		return (temporary);
	}
	TreeNode<T>* deleteNode(TreeNode<T>* obj, int value)
	{
		if (obj == NULL)	//sprwadzamy czy drzewo nie jest puste
			return obj;
		else if (value < obj->Data)		//sprawdzamy czy wartosc jest mniejsza od roota
			obj->Left = deleteNode(obj->Left, value);
		else if (value > obj->Data)		//sprawdzamy czy wartosc jest wieksza od roota
			obj->Right = deleteNode(obj->Right, value);
		else
		{
			TreeNode<T>* temporary;
			if (obj->Left == NULL)	//dla jednego dziecka
			{
				temporary = obj->Right;
				delete obj;
				return temporary;
			}
			else if (obj->Right == NULL)	//dla jednego dziecka
			{
				temporary = obj->Left;
				delete obj;
				return temporary;
			}
			else	//dla dwoch dzieci
			{
				temporary = lowestValue(obj->Right);
				obj->Data = temporary->Data;
				obj->Right = deleteNode(obj->Right, temporary->Data);
			}
			return obj;
		}
	}
	int heightOfTree(TreeNode<T>* obj)
	{
		if (obj == NULL)
			return -1;
		else
		{
			int leftH = heightOfTree(obj->Left);
			int rightH = heightOfTree(obj->Right);

			if (leftH > rightH)
				return (leftH + 1);
			else
				return (rightH + 1);
		}
	}
	void deleteTree(TreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		deleteTree(obj->Left);
		deleteTree(obj->Right);
		delete obj;
	}
	void displayTree(TreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		if (obj->Parent == NULL)
			cout << "(Parent: NONE)" << obj->Data << ", ";
		else
			cout << "(Parent: " << obj->Parent->Data << ") " << obj->Data << ", ";
		displayTree(obj->Left);
		displayTree(obj->Right);

	}
};



int main()
{
	Tree<int>* Maokai = new Tree<int>();
	Maokai->insertNode(10);
	Maokai->insertNode(4);
	Maokai->insertNode(14);
	Maokai->insertNode(18);
	Maokai->insertNode(9);
	Maokai->insertNode(3);

	Maokai->displayTree(Maokai->Root);

	Maokai->deleteTree(Maokai->Root);
	return 0;
}