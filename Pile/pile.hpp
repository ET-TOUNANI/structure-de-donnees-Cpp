#ifndef _pile_
#define _pile_
#define MAX 10
#include <iostream>
#include <string>
using namespace std;
//----------------------------------------
// implemontation using Array
//----------------------------------------
class Pile_with_table
{
    int size;
    int tab[MAX];

public:
    Pile_with_table()
    {
        size = -1;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "full !!";
            return;
        }

        tab[++size] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "err !!";
            return 0;
        }

        return tab[size--];
    }
    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        if (size == -1)
            return true;
        return false;
    }
    bool isFull()
    {
        if (size == MAX)
            return true;
        return false;
    }
    void print()
    {
        if (isEmpty())
            cout << "empty pile -_- ! " << endl;
        cout << endl;
        for (int i = size - 1; i >= 0; i--)
        {

            cout << "|  " << tab[i] << " | " << endl;
            cout << "|____|" << endl;
        }
    }
};

//----------------------------------------
// implemontation using LinkedList
//----------------------------------------

template <typename T>
class node
{
public:
    T data;
    struct node *next;
    struct node *prev;
};
template <typename T>
class Pile_with_linkedList
{
    int size;
    node<T> *head;
    node<T> *last;

public:
    Pile_with_linkedList()
    {
        size = 0;
        last = nullptr;
        head = nullptr;
    }

    void push(T data)
    {
        if (isEmpty())
        {
            size++;
            head = new node<T>;
            head->data = data;
            last = head;
            return;
        }
        size++;
        last->next = new node<T>;
        last->next->data = data;
        last->next->next = nullptr;
        last->next->prev = last;
        last = last->next;
    }

    T pop()
    {
        node<T> *RemovedNode = last;
        delete last;
        last = RemovedNode->prev;
        size--;
        return RemovedNode->data;
    }
    T top()
    {
        return last->data;
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
    void print()
    {
        if (isEmpty())
            cout << "empty pile -_- ! " << endl;
        cout << endl;
        node<T> *temp = last;
        while (temp != nullptr)
        {
            cout << "|  " << temp->data << " |" << endl;
            cout << "|____|" << endl;
            temp = temp->prev;
        }
    }
};

#endif