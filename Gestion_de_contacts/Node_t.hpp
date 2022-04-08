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

    Node_t(string, string, string);
    ~Node_t();
    string toString() const;
    friend class List_t;
};
Node_t::Node_t(string name, string phone, string email = " ")
{
    this->contact = new Contact_t(name, phone, email);
}
Node_t::~Node_t()
{
}
string Node_t::toString() const
{
    return contact->toString();
}

#endif