#ifndef _List_t_
#define _List_t_
#include <iostream>
#include <string>
#include "Node_t.hpp"
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
        while (curr != nullptr)
        {
            head = curr->next;
            delete curr;
        }
    }
    void add(string, string, string);
    string toString() const;
    void deleteList(string);
    Node_t *search(string) const;
    void print() const;
    bool isEmpty() const;
    void update(string, string, string);
    friend class Dir_t;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
                size++;
                curr->prev = new Node_t(newNode, curr->prev, curr);
                return;
            }
            curr = curr->next;
        }
        // avant le dernier noed
        if (name < curr->contact->name)
        {
            size++;
            curr->prev = new Node_t(newNode, curr->prev, curr);
            return;
        }
        // ajouter dans la fin de la liste
        else
        {
            size++;
            curr->next = new Node_t(newNode, curr, nullptr);
            return;
        }
    }
    // la liste est vide
    else
    {

        size++;
        head = new Node_t(newNode, nullptr, nullptr);
        return;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void List_t::deleteList(string email)
{
    // the list contain one element
    if (size == 1 && head->contact->email == email)
    {
        size--;
        head = nullptr;
        return;
    }
    // delete the first noed
    if (head->contact->email == email)
    {
        size--;
        Node_t tempNode(head->next->contact->name, head->next->contact->phone, head->next->contact->email);
        // the list contain just two noeds
        if (head->next->next == nullptr)
        {
            head = new Node_t(tempNode, nullptr, nullptr);
            return;
        }
        // the list contain more then list
        head = new Node_t(tempNode, nullptr, head->next->next);
        head->next->prev = head;

        return;
    }
    Node_t *curr = head;
    while (curr->next != nullptr)
    {
        if (curr->contact->email == email)
        {
            size--;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->~Node_t();
            return;
        }
        curr = curr->next;
    }
    // delete the last noed
    if (curr->contact->email == email)
    {
        size--;
        curr->prev->next = nullptr;
        curr->~Node_t();
        return;
    }
    cout << "there is no contact with this email ! " << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Node_t *List_t::search(string email_or_Phone) const
{

    Node_t *curr = head;
    while (curr != nullptr)
    {
        if (curr->contact->email == email_or_Phone || curr->contact->name == email_or_Phone)
        {
            return curr;
        }
        curr = curr->next;
    }
    Node_t *NoContact = new Node_t();
    return NoContact;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool List_t::isEmpty() const
{
    if (this->size == 0)
        return true;
    return false;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void List_t::update(string name, string email, string phone = " ")
{
    Node_t *modified = search(email);
    modified->contact = new Contact_t(name, phone, email);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string List_t::toString() const
{
    if (isEmpty())
        return "no contacts here";
    string result;
    Node_t *curr = head;
    while (curr != nullptr)
    {
        result += curr->toString();
        result += "\n__________________________\n";
        curr = curr->next;
    }
    return result;
}
#endif