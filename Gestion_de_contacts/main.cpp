#include <iostream>
#include <string>
using namespace std;

//****************************************************************************************************************************************************************************
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
//****************************************************************************************************************************************************************************
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
//****************************************************************************************************************************************************************************
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
//****************************************************************************************************************************************************************************
class Dir_t
{
    List_t liste[27];
    int nbre;

public:
    void add(string name, string phone, string email = NULL)
    {
        liste[((int)name[0]) - 65].add(name, phone, email);
    }
};
//****************************************************************************************************************************************************************************
int main()
{
    // Contact_t c("ahmed", "0689971837", "abdo@gmail.com");
    // c.print();
    Dir_t d;
    d.add("Ahmed", "0689971837", "abdo@gmail.com");

    return 0;
}