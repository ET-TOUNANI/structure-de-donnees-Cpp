#ifndef _pile_
#define _pile_
#define MAX 10
#include <iostream>
using namespace std;
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
        tab[++size] = data;
    }
    int pop()
    {
        return tab[size--];
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
        for (int i = 0; i < size; i++)
        {
            cout << tab[i] << " --> " << endl;
        }
    }
};
class Pile_with_linkedList
{
};

#endif