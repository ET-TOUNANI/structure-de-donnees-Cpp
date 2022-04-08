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
    int nbre;

public:
    List_t()
    {
        head = NULL;
        nbre = 0;
    }
    void add(string, string, string);
    void toString() const;
    void deleteList(string); // email
    List_t search(string) const;
    void print() const;
    bool isEmpty() const;
    void update(string, string); // Nom, phone
};
void List_t::add(string name, string phone, string email = NULL)
{
    Node_t node(name, phone, email);
    if (isEmpty() == false)
    {

        /*nbre++;
        Node_t *curr = head;
        while (curr != NULL)
        {
            if (curr->next->contact->compare(*node.contact) == true)
            {
                curr->next->prev->next = new Node_t(node.contact->name, node.contact->phone, node.contact->email);
                curr->next->prev->next->next = curr;
                return;
            }
            curr = curr->next;
        }*/
    }
    nbre++;
    cout << nbre;
    head->next = &node;
    head = &node;
    head->next->prev = head;
}
void List_t::toString() const
{
}
void List_t::deleteList(string email)
{
} /*
 List_t List_t::search(string email_or_Phone) const
 {
 }*/
void List_t::print() const
{
}
bool List_t::isEmpty() const
{
    if (this->nbre == 0)
    {
        return true;
    }
    return false;

} /*
 void List_t::update(string name, string phone = NULL)
 {
 }*/
#endif