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
    string s = "information de " + name + "\n\t phone : " + phone + " \n\t email : " + email;
    return s;
}
bool Contact_t::compare(const Contact_t &contact) const
{
    if (this->name < contact.name)
    {
        return false;
    }
    else
        return true;
}
bool Contact_t::operator<(const Contact_t &contact)
{
    if (this->name < contact.name)
    {
        return false;
    }
    else
        return true;
}

void Contact_t::print()
{
    cout << toString();
}

class Dir_t
{
    
};

class List_t
{

};

class Node_t
{

};
int main()
{
    Contact_t c("ahmed", "0689971837", "abdo@gmail.com");
    c.print();
    return 0;
}