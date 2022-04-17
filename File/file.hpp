#ifndef _pile_
#define _pile_
#define MAX 10
#include <iostream>
using namespace std;
//----------------------------------------
// implemontation using Array
//----------------------------------------
class File_Array
{
    int begin;
    int size;
    int tab[MAX];

public:
    File_Array()
    {
        begin = 0;
        size = -1;
    }
    void enqueue(int data)
    {
        tab[++size] = data;
    }
    int dequeue()
    {
        return tab[begin++];
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
            return;
        cout << "________________________________________________________________________________________________________\n"
             << endl;
        for (int i = begin; i <= size; i++)
        {
            cout << "| " << tab[i] << " | -->  ";
        }
        cout << "\n________________________________________________________________________________________________________" << endl;
    }
};

//----------------------------------------
// implemontation using LinkedList
//----------------------------------------

typedef struct node
{
    int data;
    struct node *next;
    node(int dat)
    {
        data = dat;
        next = nullptr;
    }
} node;

class file_Linked_List
{
    int size;
    node *front;
    node *rear;

public:
    file_Linked_List()
    {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int data)
    {
        node *temp = new node(data);
        if (isEmpty())
        {
            front = rear = temp;
            size++;
            return;
        }

        rear->next = temp;
        rear = temp;
        size++;
    }
    node dequeue()
    {
        if (isEmpty())
            return *(new node(0));

        size--;
        node temp = *front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        return temp;
    }
    void print()
    {
        if (isEmpty())
            return;
        node *temp = front;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        while (temp != nullptr)
        {
            cout << "| \t" << temp->data << " | -->  ";
            temp = temp->next;
        }

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
};

#endif