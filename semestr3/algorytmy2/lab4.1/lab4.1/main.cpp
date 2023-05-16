//ALGO2 IS1 212A LAB04
//Kacper Burzyñski
//bk50940@zut.edu.pl
#include <iostream>

using namespace std;

template <class T>

class RBTreeNode
{
public:
	T Data;
	bool Colour; // true - red, false - black

	RBTreeNode<T>* Left;
	RBTreeNode<T>* Right;
	RBTreeNode<T>* Parent;

	RBTreeNode(T value) : Data(value), Parent(nullptr), Right(nullptr), Left(nullptr), Colour(true) {}

};

template <class T>

class RBTree
{
public:
	RBTreeNode<T>* Root;
	RBTree() : Root(nullptr) {}

	void leftRotation(RBTreeNode<T>* obj, RBTreeNode<T>* temp) // (rodzic, dziecko)
	{
		obj->Right = temp->Left;
		if (temp->Left != nullptr)
			temp->Left->Parent = obj;
		temp->Parent = obj->Parent;
		if (obj->Parent == nullptr)
			this->Root = temp;
		else if (obj == obj->Parent->Left)
			obj->Parent->Left = temp;
		else
			obj->Parent->Right = temp;
		temp->Left = obj;
		obj->Parent = temp;
	}
	void rightRotation(RBTreeNode<T>* obj, RBTreeNode<T>* temp) // (rodzic, dziecko)
	{
		obj->Left = temp->Right;
		if (temp->Right != nullptr)
			temp->Right->Parent = obj;
		temp->Parent = obj->Parent;
		if (obj->Parent == nullptr)
			this->Root = temp;
		else if (obj == obj->Parent->Right)
			obj->Parent->Right = temp;
		else
			obj->Parent->Left = temp;
		temp->Right = obj;
		obj->Parent = temp;
	}
	void fixColour(RBTreeNode<T>* child)
	{
		RBTreeNode<T>* par = nullptr;
		RBTreeNode<T>* gpar = nullptr;
		RBTreeNode<T>* uncL = nullptr;
		RBTreeNode<T>* uncR = nullptr;
		while ((child->Parent->Colour == true) && (child != Root))
		{
			par = child->Parent;
			gpar = par->Parent;
			uncL = gpar->Left;
			uncR = gpar->Right;
			// rodzic jest lewym dzieckiem dziadka:
			if (par == uncL)
			{
				// prawy wujek te¿ jest czerwony
				if ((uncR != nullptr) && (uncR->Colour == true))
				{
					gpar->Colour = true;
					par->Colour = false;
					uncR->Colour = false;
				}
				else
				{
				// dziecko jest prawym dzieckiem rodzica
					if (child == par->Right)
					{
						leftRotation(par, par->Right);
					}
				// dziecko jest lewym dzieckiem rodzica
					rightRotation(gpar, gpar->Left);
					swap(par->Colour, gpar->Colour);
				}
			}
			// rodzic dziecka jest prawym dzieckiem dziadka
			else
			{
				// lewy wujek dziecka te¿ jest czerwony
				if ((uncL != nullptr) && (uncL->Colour == true))
				{
					gpar->Colour = true;
					par->Colour = false;
					uncL->Colour = false;
				}
				else
				{
					// dziecko jest lewym dzieckiem rodzica
					if (child == par->Left)
					{
						rightRotation(par, par->Left);
					}
					// dziecko jest prawym dzieckiem rodzica
					leftRotation(gpar, gpar->Right);
					swap(par->Colour, gpar->Colour);
				}
			}
		}
		Root->Colour = false;
	}
	void insertNode(T value)
	{
		if (Root == nullptr)
		{
			Root = new RBTreeNode<T>(value);
			Root->Colour = false;
		}
		else
		{
			RBTreeNode<T>* obj = Root;
			while (true)
			{
				if (value < obj->Data)
				{
					if (obj->Left == nullptr)
					{
						obj->Left = new RBTreeNode<T>(value);
						obj->Left->Parent = obj;
						fixColour(obj->Left);
						break;
					}
					else
					{
						obj = obj->Left;
					}
				}
				else if (value > obj->Data)
				{
					if (obj->Right == nullptr)
					{
						obj->Right = new RBTreeNode<T>(value);
						obj->Right->Parent = obj;
						fixColour(obj->Right);
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
	void displayRBTree(RBTreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		else if (obj->Parent == NULL)
			cout << "(Parent: NONE, Colour: "<< getColour(obj) << "): " << getData(obj) << endl;
		else
			cout << "(Parent: " << getParent(obj) << ", Colour: " << getColour(obj) << "): " << getData(obj) << endl;
		displayRBTree(obj->Left);
		displayRBTree(obj->Right);
		

	}
	int getParent(RBTreeNode<T>* obj)
	{
		return obj->Parent->Data;
	}
	string getColour(RBTreeNode<T>* obj)
	{
		if (obj->Colour == true)
			return "RED";
		else
			return "BLACK";
	}
	int getData(RBTreeNode<T>* obj)
	{
		return obj->Data;
	}


	void deleteRBTree(RBTreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		deleteRBTree(obj->Left);
		deleteRBTree(obj->Right);
		delete obj;
	}
	int heightOfRBTree(RBTreeNode<T>* obj)
	{
		if (obj == NULL)
			return -1;
		else
		{
			int leftH = heightOfRBTree(obj->Left);
			int rightH = heightOfRBTree(obj->Right);

			if (leftH > rightH)
				return (leftH + 1);
			else
				return (rightH + 1);
		}
	}
	void preorder(RBTreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		cout << obj->Data << ", ";
		preorder(obj->Left);
		preorder(obj->Right);
	}
	void inorder(RBTreeNode<T>* obj)
	{
		if (obj == NULL)
			return;
		inorder(obj->Left);
		cout << obj->Data << ", ";
		inorder(obj->Right);
	}
	RBTreeNode<T>* search(T data)
	{
		if (Root->Data == data)
		{
			return Root;
		}
		else
		{
			RBTreeNode<T>* obj = Root;
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

};

int main()
{
	RBTree<int>* RBDrzewo = new RBTree<int>();
	RBDrzewo->insertNode(10);
	RBDrzewo->insertNode(5);
	RBDrzewo->insertNode(14);
	RBDrzewo->insertNode(16);
	RBDrzewo->insertNode(12);
	RBDrzewo->insertNode(3);
	RBDrzewo->insertNode(2);
	RBDrzewo->insertNode(20);
	RBDrzewo->insertNode(21);


	RBDrzewo->displayRBTree(RBDrzewo->Root);
	RBDrzewo->deleteRBTree(RBDrzewo->Root);
	return 0;
}