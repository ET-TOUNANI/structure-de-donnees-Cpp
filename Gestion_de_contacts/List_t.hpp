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
    List_t search(string) const;
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
        while (curr != nullptr)
        {
            if (name < curr->contact->name)
            {
                newNode.next = (Node_t *)&curr;
                newNode.prev = (Node_t *)&curr->prev;
                curr->prev = &newNode;
                return;
            }
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            curr->contact = newNode.contact;
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
} /*
 List_t List_t::search(string email_or_Phone) const
 {
 }*/
void List_t::print() const
{
    if (isEmpty() == false)
    {
        Node_t *curr = head;
        while (curr->next != nullptr)
        {
            cout << curr->toString() << endl;
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
void List_t::update(string name, string phone = NULL)
{
}
#endif