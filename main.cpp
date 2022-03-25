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

typedef int element_t;

typedef struct noed
{
    element_t data;
    struct noed *next;
} noed;
typedef struct liste_t
{
    noed *head;
    noed *last;
    int length;

} liste_t;

// class Linked_
class Linked_List
{
private:
    liste_t l;

public:
    Linked_List()
    {
        l.length = 0;
        l.head = NULL;
        l.last = NULL;
    }

    Linked_List(element_t e)
    {
        l.length = 0;
        l.head = new noed;
        l.head->data = e;
        l.head->next = NULL;
        l.last = l.head;
        l.length++;
    }
    // constructeur par copier
    Linked_List(Linked_List *list)
    {
        l.length = list->get_length();

        noed *curr = list->get_head();
        noed *curr2 = new noed;
        curr2->data = curr->data;
        curr2->next = new noed;
        l.head = curr2;
        while (curr->next != NULL)
        {
            curr2->data = curr->data;
            curr2->next = new noed;
            curr = curr->next;
        }
        l.last->data = curr->next->data;
        l.last->next = NULL;
    }
    bool estVide()
    {
        if (this->l.length > 0)
            return 0; // n'est pas vide
        return 1;     // la liste est vide
    }
    element_t get_first_val()
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!" << endl;
            return -1;
        }

        return l.head->data;
    }
    noed *get_head()
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!" << endl;
            return NULL;
        }

        return this->l.head;
    }
    noed *get_last()
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!" << endl;
            return NULL;
        }

        return this->l.last;
    }
    int get_length()
    {
        return l.length;
    }
    void insert_fin(element_t e)
    {
        if (l.length > 0)
        {
            noed *curr = l.head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new noed;
            l.last = curr->next;
            l.last->data = e;
            l.last->next = NULL;
            l.length++;
            return;
        }
        l.head = new noed;
        l.head->data = e;
        l.head->next = NULL;
        l.last = l.head;
    }
    void insert_debut(element_t e)
    {
        if (l.length > 0)
        {
            noed *curr = l.head;

            l.head = new noed;
            l.head->data = e;
            l.head->next = curr;
            l.length++;
            return;
        }
        l.head = new noed;
        l.head->data = e;
        l.head->next = NULL;
        l.last = l.head;
    }
    void read()
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!";
            return;
        }

        noed *curr = l.head;
        while (curr->next != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << curr->data << endl;
    }
    void delete_val(element_t e)
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!";
            return;
        }

        noed *curr = l.head, *pred = l.head;
        while (curr != NULL)
        {
            if (curr->data == e && pred == curr)
            {
                pred->next = curr->next;

                l.head = pred->next;
                l.length--;
                delete (pred);
                return;
            }
            else if (curr->data == e && curr->next != NULL)
            {
                pred->next = curr->next;
                delete (curr);
                l.length--;
                return;
            }
            else if (curr->data == e && curr->next == NULL)
            {
                pred->next = NULL;
                delete (curr);
                l.length--;
                return;
            }

            pred = curr;
            curr = curr->next;
        }
    }
    void fesionner2_list(Linked_List *l2)
    {
        int nbrElements = l2->get_length();
        noed *curr = l2->get_head();

        while (nbrElements > 0)
        {
            while (curr != NULL)
            {
                this->insert_fin(curr->data);
                curr = curr->next;
            }
            nbrElements--;
        }
    }
    void sortlist()
    {
        if (this->estVide() == 1)
        {
            cout << "la liste est vide !!";
            return;
        }
        // Node current will point to head
        noed *current = get_head(), *index = NULL;
        int temp;

        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->next;
            while (index != NULL)
            {
                // If current node's data is greater than index's
                // noed data, swap the data between them
                if (current->data > index->data)
                {

                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void detruire()
    {
        cout << "attontion vous étes en train de detruire tout la liste ! " << endl;

        while (this->get_length() > 0)
        {
            delete_val(this->get_first_val());
        }
        cout << "tous les élements sont supprimer :(" << endl;
    }
};
class Polynome : public Linked_List
{
};
int main()
{
    Linked_List *v = new Linked_List(40);
    v->insert_fin(1);
    v->insert_fin(5);
    v->insert_fin(7);
    v->insert_fin(50);
    v->insert_fin(71);
    v->insert_debut(44);

    v->read();
    Linked_List *v2 = new Linked_List(v);
    // v->detruire();
    v2->read();
    /*
        pour fesionner deux listes
                Linked_List *v2 = new Linked_List(770);
                v2->insert_fin(4111);
                v2->insert_fin(11);
                v2->insert_fin(2);
                v->fesionner2_list(v2);
        */
    /*
        pour detruire tout la liste
               v->detruire();
    */
    /*
        pour trie  la liste
            cout << "vous etes en train de trie la liste :) " << endl;
            v->sortlist();
    */
    // v->read();
    return 0;
}
