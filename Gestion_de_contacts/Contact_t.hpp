#ifndef _Contact_t_
#define _Contact_t_

#include <iostream>
#include <string>
using namespace std;

class Contact_t
{
private:
    string name, phone, email;

public:
    Contact_t(string, string, string);

    ~Contact_t();
    string toString();
    bool compare(const Contact_t &) const;
    bool operator<(const Contact_t &);

    void print();

    friend class Node_t;
    friend class Dir_t;
    friend class List_t;
};

Contact_t::Contact_t(string name, string phone, string email = " ")
{
    this->name = name;
    this->phone = phone;
    this->email = email;
}

Contact_t::~Contact_t()
{
}
string Contact_t::toString()
{
    string s = "|\t name : " + name + "\n|\t phone : " + phone + " \n|\t email : " + email;
    return s;
}
bool Contact_t::compare(const Contact_t &contact) const
{
    return this->name < contact.name;
}
bool Contact_t::operator<(const Contact_t &contact)
{
    return this->name < contact.name;
}

void Contact_t::print()
{
    cout << toString();
}

#endif