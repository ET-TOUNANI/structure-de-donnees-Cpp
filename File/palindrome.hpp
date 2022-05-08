#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Noed
{
private:
    /* data */
    T data;
    Noed *next;

public:
    Noed(/* args */)
    {
        data = "";
        next = nullptr;
    }
    Noed(T d)
    {
        data = d;
        next = nullptr;
    }
    ~Noed() {}
    friend class Palindrome;
};

class Palindrome
{
private:
    /* data */
    Noed<char> *front;
    Noed<char> *rear;
    int size;

public:
    Palindrome(/* args */) : front(nullptr), rear(nullptr), size(0) {}
    template <typename T>
    void enqueue(T d)
    {
        if (size == 0)
        {
            front = rear = new Noed<char>(d);
            size++;
            return;
        }
        rear->next = new Noed<char>(d);
        rear = rear->next;
        size++;
    }
    void insert(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            enqueue<char>(s[i]);
        }
    }
    template <typename T>
    T dequeue()
    {
        Noed<char> *temp = front;
        front = temp->next;
        size--;
        T res = temp->data;
        delete temp;
        return res;
    }
    template <typename T>
    T dequeueRear()
    {
        Noed<char> *curr = front;
        while (curr->next != rear)
        {
            curr = curr->next;
        }
        rear = curr;
        T res = curr->next->data;
        size--;
        delete curr->next;
        return res;
    }
    template <typename T>
    T getFront()
    {
        return front->data;
    }
    template <typename T>
    T getRear()
    {
        return rear->data;
    }
    int getSize()
    {
        return size;
    }

    void copier(Palindrome &p)
    {
        if (p.size == 0)
        {
            size = 0;
            front = rear = nullptr;
            return;
        }
        Noed<char> *curr = p.front;
        while (curr != nullptr)
        {
            enqueue<char>(curr->data);
            curr = curr->next;
        }
    }
    void print()
    {
        if (size == 0)
            return;
        Noed<char> *curr = front;
        while (curr != nullptr)
        {
            cout << curr->data << "  --> ";
            curr = curr->next;
        }
    }

    ~Palindrome();
};

Palindrome::~Palindrome()
{
}
bool isPolindrome(Palindrome f)
{
    Palindrome p;
    p.copier(f);
    int res = 0;
    while (res < p.getSize() / 2)
    {
        if (p.dequeue<char>() != p.dequeueRear<char>())
            return false;
        res++;
    }
    return true;
}