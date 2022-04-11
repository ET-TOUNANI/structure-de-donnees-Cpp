#ifndef _Node_t_
#define _Node_t_
#include <iostream>
#include <string>
#include "Contact_t.hpp"
using namespace std;

class Node_t
{
private:
    Node_t *prev, *next;
    Contact_t *contact;
    Node_t(Node_t &);
    Node_t() : prev(nullptr), next(nullptr), contact(nullptr) {}
    Node_t(string, string, string);
    ~Node_t();
    string toString() const;
    friend class List_t;
    friend class Dir_t;
};
Node_t::Node_t(string name, string phone, string email = " ")
{
    next = nullptr;
    prev = nullptr;
    this->contact = new Contact_t(name, phone, email);
}
Node_t::Node_t(Node_t &node)
{
    next = nullptr;
    prev = nullptr;
    this->contact = new Contact_t(node.contact->name, node.contact->phone, node.contact->email);
}
Node_t::~Node_t()
{
    delete contact;
}
string Node_t::toString() const
{
    return contact->toString();
}

#endif