#ifndef _List_t_
#define _List_t_
#include <iostream>
#include <string>
#include "Node_t.hpp"
using namespace std;

class List_t
{
private:
    Node_t *head;
    int size;

public:
    List_t() : size(0), head(nullptr) {}
    ~List_t()
    {
        Node_t *curr = head;
        while (head != nullptr)
        {
            head = head->next;
            delete curr;
        }
    }
    void add(string, string, string);
    void toString() const;
    void deleteList(string); // email
    bool search(string) const;
    void print() const;
    bool isEmpty() const;
    void update(string, string); // Nom, phone
};
void List_t::add(string name, string phone, string email = " ")
{

    Node_t newNode(name, phone, email);

    if (isEmpty() == false)
    {
        Node_t *curr = head;
        while (curr->next != nullptr)
        {
            if (name < curr->contact->name)
            {
                Node_t *prevPrim = curr->prev;
                curr->prev = new Node_t(newNode);
                prevPrim->next = (Node_t *)&curr->prev;
                return;
            }
            curr = curr->next;
        }
        if (curr->next == nullptr)
        {
            curr->next = new Node_t(newNode);
            curr->next->prev = (Node_t *)&curr;
            return;
        }
    }
    else
    {
        head = new Node_t(newNode);
        head->next = new Node_t(newNode);
        head->next->prev = (Node_t *)&head;
    }

    size++;
}
void List_t::deleteList(string email)
{
    if (size == 1)
    {
        head->next->~Node_t();
        head->next = nullptr;
        head->~Node_t();
        return;
    }
    Node_t *curr = head;
    size--;
    while (curr != nullptr)
    {
        if (curr->contact->email == email)
        {

            curr->~Node_t();
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        curr = curr->next;
    }
}
bool List_t::search(string email_or_Phone) const
{
    Node_t *curr = head;
    while (curr != nullptr)
    {
        if (curr->contact->email == email_or_Phone || curr->contact->name == email_or_Phone)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
void List_t::print() const
{
    if (isEmpty() == false)
    {
        Node_t *curr = head->next;
        while (curr != nullptr)
        {
            cout << curr->toString() << endl;
            cout << "__________________________" << endl;
            curr = curr->next;
        }
        return;
    }
    cout << "there is no concats here !" << endl;
    return;
}
bool List_t::isEmpty() const
{
    if (this->size == 0)
        return true;
    return false;
}
/*void List_t::update(string name, string phone = NULL)
{
}*/
#endif