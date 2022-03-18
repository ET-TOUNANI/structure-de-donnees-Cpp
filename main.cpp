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
        l.head = (noed *)malloc(sizeof(noed));
        l.head->data = e;
        l.head->next = NULL;
        l.last = l.head;
        l.length++;
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
            return NULL;
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
            curr->next = (noed *)new noed;
            l.last = curr->next;
            l.last->data = e;
            l.last->next = NULL;
            l.length++;
            return;
        }
        l.head = (noed *)new noed;
        l.head->data = e;
        l.head->next = NULL;
        l.last = l.head;
    }
    void insert_debut(element_t e)
    {
        if (l.length > 0)
        {
            noed *curr = l.head;

            l.head = (noed *)new noed;
            l.head->data = e;
            l.head->next = curr;
            l.length++;
            return;
        }
        l.head = (noed *)new noed;
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
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << endl;
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
        } // new delete
    }
    void fesionner2_list(Linked_List *l2)
    {
        int nbrElements = l2->get_length();
        noed *curr = l2->get_head();

        while (nbrElements > 0) //
        {
            while (curr != NULL)
            {
                this->insert_fin(curr->data);
                curr = curr->next;
            }
            nbrElements--;
        }
    }
    void trie()
    {

        noed *curr = this->l.head, *suiv = this->l.head;
        element_t data;
        while (curr != NULL)
        {
            while (suiv != NULL)
            {
                if (curr->data < suiv->data)
                {
                    data = suiv->data;
                    suiv->data = curr->data;
                    curr->data = data;
                }
                suiv = suiv->next;
            }
            suiv = this->l.head;
            curr = curr->next;
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
    v->insert_debut(44);
    v->read();
    /*
    pour fesionner deux listes*/
    Linked_List *v2 = new Linked_List(770);
    v2->insert_fin(4111);
    v2->insert_fin(11);
    v2->insert_fin(2);
    v->fesionner2_list(v2);

    /*
    pour detruire tout la liste
            v->detruire();
    */
    /*
    pour detruire tout la liste
            cout << "vous etes en train de trie la liste :) " << endl;
            v->trie();
    */
    v->read();
    return 0;
}
