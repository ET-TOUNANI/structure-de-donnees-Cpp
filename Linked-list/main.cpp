/*
    Donner la declaration des types et opération relatifs à une liste simplement chainé dans les élements
    sont de type générique  "element_t"
    la liste sera representée par
        -  la tete     = @ du 1er élement
        -  la queue    = @ du dernier élement
        -  la langueur = nombre des élements
    2) Donner l'implémentation des opérations
    3) Appliquer ce type abstrait de donnés pour réaliser les opérations de calculs sue des polynomes
       à coefficion réels constants :
            -   créer
            -   insérer un monome
            -   afficher
            -   add
            -   produit
            -   derivée
            -   primitive
    P(x) = a0 + a1 * x + a2 * x^2 + .....

    Rommarque :
        les mononmes sont ordonnés en ordere croissent de leur degré




À voir :
    les testes unitaires
    memcpy : copier deux block memoires (    )   copier (   )
    creer une liste dans une nouvell liste
    constructeur par copier
    size_t <==> unsighned long  dirhom bzoj we thana

    standars C les declarations au debut au block
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// type Node

struct monome
{
    float coef;
    int deg;
};
class node
{
public:
    monome m;
    node *next;
    node(monome a)
    {
        m.coef = a.coef;
        m.deg = a.deg;
        next = nullptr;
    }
    void print()
    {
        cout << m.coef << "X^" << m.deg;
    }
};

// template <class T>

// class Linked_
class Linked_List
{
protected:
    node *head;
    node *rear;
    int size;

public:
    Linked_List()
    {
        size = 0;
        head = nullptr;
        rear = nullptr;
    }

    void push(monome m)
    {
        if (estVide())
        {
            head = new node(m);
            rear = head;
            size++;
            return;
        }

        rear->next = new node(m);
        rear = rear->next;
        size++;
    }
    void push(node *n, monome m)
    {
        if (n == nullptr)
        {
            return;
        }
        node *temp = n->next;
        n->next = new node(m);
        n->next->next = temp;
        size++;
    }
    bool estVide()
    {
        if (size == 0)
            return true; // n'est pas vide
        return false;    // la liste est vide
    }

    void insert_debut(monome e)
    {
        node *temp = head;
        head = new node(e);
        head->next = temp;
        size++;
    }
    void print()
    {
        if (estVide())
        {
            cout << "la liste est vide !!";
            return;
        }

        node *curr = head;
        while (curr->next != nullptr)
        {
            curr->print();
            cout << " + ";
            curr = curr->next;
        }
        curr->print();
        cout << endl;
    }
};
class Polynome : public Linked_List
{
public:
    void add(monome e)
    {

        if (estVide())
        {
            head = new node(e);
            rear = head;
            size++;
            return;
        }
        else
        {
            node *temp = head;
            node *prev = nullptr;
            int count = 1;
            while (temp != nullptr)
            {
                if (temp->m.deg > e.deg && prev == nullptr)
                {
                    insert_debut(e);
                    return;
                }
                else if (temp->m.deg > e.deg && prev != nullptr)
                {
                    prev->next = new node(e);
                    prev->next->next = temp;
                    size++;
                    return;
                }
                else if (temp->m.deg == e.deg && prev == nullptr)
                {
                    temp->m.coef += e.coef;
                    if (temp->m.coef == 0)
                    {
                        head = temp->next;
                        delete temp;
                        size--;
                    }
                    return;
                }
                else if (temp->m.deg == e.deg && prev != nullptr)
                {
                    temp->m.coef += e.coef;
                    if (temp->m.coef == 0)
                    {
                        prev->next = temp->next;
                        delete temp;
                        size--;
                    }
                    return;
                }
                else if (temp->m.deg < e.deg && count == size)
                {
                    temp->next = new node(e);
                    rear = temp->next;
                    size++;
                    return;
                }
                else if (temp->m.deg < e.deg && temp->m.deg + 1 == e.deg)
                {
                    push(temp, e);
                    return;
                }
                count++;
                prev = temp;
                temp = temp->next;
            }
        }
    }
};
monome create(float cf, int dg)
{
    monome m;
    m.coef = cf;
    m.deg = dg;
    return m;
}
int main()
{
    Polynome p;

    p.add(create(7, 1));
    p.add(create(2.3, 2));
    p.add(create(8, 5));
    p.add(create(-7, 1));
    p.add(create(-8, 5));
    p.print();

    return 0;
}
