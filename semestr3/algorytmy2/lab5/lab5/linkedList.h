#pragma once

#include <iostream>
#include <string> 

using namespace std;

template <class L>

class ObjectInList
{
public:

    L Data;
    ObjectInList<L>* Next;
    ObjectInList<L>* Previous;

    ObjectInList()
    {
        Next = nullptr;
        Previous = nullptr;
    }
};

template <class L>
class LinkedList
{
private:
    int Size;

    ObjectInList<L>* Head;
    ObjectInList<L>* Tail;

public:
    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
    }
    void AddOnBack(L data)
    {
        ObjectInList<L>* obj = new ObjectInList<L>();
        if (Head == nullptr)
        {
            Head = obj;
            Tail = obj;
            obj->Data = data;
            Size++;
        }
        else
        {
            Tail->Next = obj;
            obj->Previous = Tail;
            Tail = obj;
            obj->Data = data;
            Size++;
        }

    }
    void AddOnFront(L data)
    {
        ObjectInList<L>* obj = new ObjectInList<L>();
        if (Head == nullptr)
        {
            Head = obj;
            Tail = obj;
            obj->Data = data;
            Size++;
        }
        else
        {
            obj->Next = Head;
            Head->Previous = obj;
            Head = obj;
            obj->Data = data;
            Size++;
        }
    }
    void DisplayList()
    {
        ObjectInList<L>* temp;
        cout << Head->Data << endl;
        temp = Head->Next;
        while (temp != Tail)
        {
            cout << temp->Data << endl;
            temp = temp->Next;
        }
        cout << Tail->Data << endl;
    }
    void EraseLastObject()
    {
        ObjectInList<L>* temp;
        temp = Tail;
        Tail = temp->Previous;
        Size--;
        delete temp;
    }
    void EraseFirstObject()
    {
        ObjectInList<L>* temp;
        temp = Head;
        Head = temp->Next;
        Size--;
        delete temp;
    }
    void DisplayAnElement(int element) // od 0 do size
    {
        if (element > Size)
        {
            cout << "There is no element with that index: " << element << endl;
        }
        else
        {
            if (element == 0)
            {
                cout << "The data from element(" << element << ") is: " << Head->Data << endl;
            }
            else if (element == Size)
            {
                cout << "The data from element(" << element << ") is: " << Tail->Data << endl;
            }
            else
            {
                ObjectInList<L>* temp;
                temp = Head->Next;
                int i = 1;
                while (i != element)
                {
                    temp = temp->Next;
                    i++;
                }
                cout << "The data from element(" << element << "): " << temp->Data << endl;
            }
        }

    }
    void ChangeA_Value(int element, L newValue)
    {
        if (element > Size)
        {
            cout << "There is no element with that index: " << element << endl;
        }
        else
        {
            if (element == 0)
            {
                Head->Data = newValue;
            }
            else if (element == Size)
            {
                Tail->Data = newValue;
            }
            else
            {
                ObjectInList<L>* temp;
                temp = Head->Next;
                int i = 1;
                while (i != element)
                {
                    temp = temp->Next;
                    i++;
                }
                temp->Data = newValue;
            }
        }
    }
    void SearchByKey(L key)
    {
        ObjectInList<L>* temp;
        temp = Head;

        if (key == temp->Data)
            cout << "Your word has been found, element(0). Pointer: " << &temp << endl;
        else
        {
            temp = Head->Next;
            int i = 1;
            while (i != Size)
            {
                if (key == temp->Data)
                {
                    cout << "Your word has been found, element(" << i << "). Pointer: " << temp << endl;
                    break;
                }
                else
                {
                    temp = temp->Next;
                }
                i++;
            }
            if (i == Size)
            {
                cout << "NULL" << endl;
            }
        }
    }
    void EraseByKey(L key)
    {
        ObjectInList<L>* temp;
        temp = Head;
        if (Size == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (key == temp->Data)
        {
            Head = temp->Next;
            if (temp->Next == nullptr)
                temp->Previous = nullptr;
            else
                temp->Next->Previous = nullptr;

            temp->Next = nullptr;

            delete temp;
            Size--;
            cout << "Found and erased." << endl;
        }
        else
        {
            temp = Head->Next;
            int i = 1;
            while (i != Size)
            {
                if (key == temp->Data)
                {
                    if (temp->Next == nullptr)
                    {
                        Tail = temp->Previous;
                        temp->Previous->Next = nullptr;
                    }
                    else
                        temp->Next->Previous = temp->Previous;

                    temp->Previous->Next = temp->Next;


                    delete temp;
                    Size--;
                    cout << "Found and erased." << endl;
                    break;
                }
                else
                {
                    temp = temp->Next;
                }
                i++;
            }
            if (i == Size)
            {
                cout << "NULL" << endl;
            }
        }
    }
    void AddByIndex(int element, L data)
    {
        ObjectInList<L>* obj = new ObjectInList<L>();
        ObjectInList<L>* temp;
        if (element > Size)
            cout << "Wrong index, bigger than " << Size << ")" << endl;
        else if (element < 1)
            cout << "Wrong index, smaller than 1" << endl;
        else
        {
            temp = Head;
            if (element == 0)
            {
                if (Head == nullptr)
                {
                    Head = obj;
                    Tail = obj;
                    obj->Data = data;
                    Size++;
                }
                else
                {
                    obj->Next = Head;
                    Head->Previous = obj;
                    Head = obj;
                    obj->Data = data;
                    Size++;
                }
            }
            else if (element == Size)
            {

                if (Head == nullptr)
                {
                    Head = obj;
                    Tail = obj;
                    obj->Data = data;
                    Size++;
                }
                else
                {
                    Tail->Next = obj;
                    obj->Previous = Tail;
                    Tail = obj;
                    obj->Data = data;
                    Size++;
                }
            }
            else if (element - 1 == Size)
            {
                temp = Tail;
                obj->Previous = temp->Previous;
                obj->Next = temp;

                temp->Previous->Next = obj;

                obj->Data = data;
                Size++;
            }
            else
            {
                int i = 1;
                while (element != i)
                {
                    temp = temp->Next;
                    i++;
                }
                obj->Previous = temp->Previous;
                obj->Next = temp;

                temp->Previous->Next = obj;
                temp->Next->Previous = obj;

                obj->Data = data;
                Size++;
            }
        }

    }
    void EraseAll()
    {
        while (Head != nullptr)
        {
            ObjectInList<L>* temp;
            temp = Head;
            Head = temp->Next;
            Size--;
            delete temp;
        }
        cout << "Your list has been cleared." << endl;
    }
    void DisplayLinkedList(int index)
    {
        cout << "The size of list is: " << Size << endl;
        if (index > Size)
        {
            cout << "Number is out of size..." << index << " > " << Size << endl;
        }
        else if (index == 0)
        {
            cout << "0 is out of range..." << endl;
        }
        else
        {
            ObjectInList<L>* temp;
            cout << to_string(Head->Data) << endl;
            temp = Head->Next;
            int i = 1;
            while (i != index)
            {
                cout << to_string(temp->Data) << endl;
                temp = temp->Next;
                i++;
            }
        }

    }
};