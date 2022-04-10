#include <string.h>
#include <iostream>
using namespace std;

class contact_t
{
private:
    string name, phone, email;
    contact_t(string, string, string = "");
    // contact_t(string,string);
    ~contact_t();
    string toString() const; // const pour les accesseurs
    bool compare(const contact_t &) const;
    bool operator<(const contact_t &) const;
    void print() const;
    friend class node_t;
    friend class list_t;
    friend class dir_t;
};
contact_t::contact_t(string n, string p, string e)
{
    name = n;
    phone = p;
    email = e;
}

contact_t::~contact_t()
{
    cout << "destruction de l'objet" << name << ","
         << "phone:" << phone << "email:" << email;
}
string contact_t::toString() const
{
    return ("le nom est:" + name + "le numero est:" + phone + "l'email" + email);
}
bool contact_t::compare(const contact_t &v) const
{
    return (name < v.name);
}
bool contact_t::operator<(const contact_t &v) const
{
    return (name < v.name);
}

void contact_t::print() const
{
    cout << toString();
}
//#endif
class node_t
{
private:
    contact_t *contact;
    node_t *next;
    node_t *precedant;
    node_t(string, string, string);
    ~node_t();
    string toString() const;
    friend class list_t;
};
node_t::node_t(string n, string p, string e)
{
    contact = new contact_t(n, p, e);
    next = NULL;
    precedant = NULL;
}
node_t::~node_t()
{
    delete (contact);
}
string node_t::toString() const
{
    return ("le nom est:" + contact->name + "le numero est:" + contact->phone + "l'email" + contact->email);
}

class list_t
{
private:
    node_t *head;
    int nbre;
    list_t(string, string, string);
    ~list_t();

public:
    node_t *add(string, string, string = NULL);
    void toString() const;
    void deleteList(); // email
    void search(string) const;
    void print() const;
    bool isEmpty() const;
    void update(string, string, string, node_t *); // Nom, phone
    friend class dir_t;
};
list_t::list_t(string n, string p, string e)
{
    head->contact = new contact_t(n, p, e);
    head->next = NULL;
    head->precedant = NULL;
    nbre = 0;
}

void list_t::toString() const
{
    cout << "le nom est:" << head->contact->name << "le num est:" << head->contact->phone << "l'email:" << head->contact->email;
}
bool list_t::isEmpty() const
{
    if (nbre == 0)
        return (true);
    else
        return (false);
}
void list_t::print() const
{
    toString();
}
void list_t::deleteList()
{
    node_t *N;
    N = head;
    while (N != NULL)
    {
        head = head->next;
        delete (N);
        N = head;
    }
}
node_t *list_t::add(string n, string p, string e)
{
    node_t *nouveau, *courant;
    nouveau = new node_t(n, p, e);
    courant = head;
    if (n < courant->contact->name)
    {
        nouveau->next = head;
        head->precedant = nouveau;
        return (head);
    }
    while (n > courant->contact->name && courant != NULL)
    {
        courant = courant->next;
    }
    if (n < courant->contact->name)
    {
        nouveau->next = courant;
        courant->next = nouveau;
        nouveau->precedant = courant->precedant;
        courant->precedant->next = nouveau;
        return (head);
    }
    if (courant == NULL)
    {
        courant->next = nouveau;
        nouveau->precedant = courant;
        return (head);
    }
}
void list_t::update(string n, string e, string p, node_t *noeud)
{
    noeud->contact->name = n;
    noeud->contact->name = e;
    noeud->contact->name = p;
}

void list_t::search(string n) const
{
    node_t *courant = head;
    while (n != courant->contact->name && courant != NULL)
        courant = courant->next;
    if (courant == NULL)
        cout << "valeur introuvable";
    else
        cout << "le nom est:" << courant->contact->name << "le num est:" << courant->contact->phone << "email est:" << courant->contact->email;
}

class dir_t
{
public:
    list_t *liste;
    int nbre;
};
int main()
{
    
}