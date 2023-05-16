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
	RBTree() : Root(nullptr){}

	void leftRotation(RBTreeNode<T> obj, RBTreeNode<T> temp) // (rodzic, dziecko)
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
	void rightRotation(RBTreeNode<T> obj, RBTreeNode<T> temp) // (rodzic, dziecko)
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
	void fixColour(RBTreeNode<T> obj)
	{
		RBTreeNode<T> temp;
		while (obj->Parent->Colour == true)
		{
			if (obj->Parent == obj->Parent->Parent->Right)
			{
				temp = obj->Parent->Parent->Left;
				if (temp->Colour == true)
				{
					temp->Colour = false;
					obj->Parent->Colour = false;
					obj->Parent->Parent->Colour = true;
					obj = obj->Parent->Parent;
				}
				else
				{
					if (obj == obj->Parent->Left)
					{
						obj = obj->Parent;
						rightRotation(obj, obj->Left);
					}
					obj->Parent->Colour = false;
					obj->Parent->Parent->Colour = true;
					leftRotation(obj->Parent->Parent, obj->Parent->Parent->Right);
				}
			}
			else
			{
				temp = obj->Parent->Parent->Right;
				if (temp->Colour == true)
				{
					temp->Colour = false;
					obj->Parent->Colour = false;
					obj->Parent->Parent->Colour = true;
					obj = obj->Parent->Parent;
				}
				else
				{
					if (obj == obj->Parent->Right)
					{
						obj = obj->Parent;
						leftRotation(obj, obj->Right);
					}
					obj->Parent->Colour = false;
					obj->Parent->Parent->Colour = true;
					rightRotation(obj->Parent->Parent, obj->Parent->Parent->Left)
				}
			}
		if (obj == Root)
			break;
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
						obj->Left = new RBTreeNode<T>(data);
						obj->Left->Parent = obj;
						obj->Left->Colour = true;
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
						obj->Left->Colour = true;
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
};

int main()
{
	RBTree<int>* RBDrzewo = new RBTree<int>();
	RBDrzewo->insertNode(10);
	RBDrzewo->insertNode(5);
	RBDrzewo->insertNode(14);
	delete RBDrzewo;
	return 0;
}