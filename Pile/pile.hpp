#ifndef _pile_
#define _pile_
#define MAX 10
#include <iostream>
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
        size = 0;
    }
    void push(int data)
    {
        tab[size++] = data;
    }
    int pop()
    {
        return tab[size--];
    }
    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        if (size == 0)
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

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
class Pile_with_linkedList
{
    int size;
    node *head;
    node *last;

public:
    Pile_with_linkedList()
    {
        size = 0;
        last = nullptr;
        head = nullptr;
    }
    void push(int data)
    {
        if (isEmpty())
        {
            size++;
            head = new node;
            head->data = data;
            last = head;
            return;
        }
        size++;
        last->next = new node;
        last->next->data = data;
        last->next->next = nullptr;
        last->next->prev = last;
        last = last->next;
    }
    node pop()
    {
        node *RemovedNode = last;
        delete last;
        last = RemovedNode->prev;
        size--;
        return *RemovedNode;
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
        node *temp = last;
        while (temp != nullptr)
        {
            cout << "|  " << temp->data << " |" << endl;
            cout << "|____|" << endl;
            temp = temp->prev;
        }
    }
};

#endif