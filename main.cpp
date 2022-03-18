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
        l.last = (noed *)malloc(sizeof(noed));
        l.head = (noed *)malloc(sizeof(noed));
        l.head->data = e;
        l.last->data = e;
        l.head->next = NULL;
        l.last->next = NULL;
        l.length++;
    }
    element_t get_first_val()
    {
        return l.head->data;
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
            curr->next = (noed *)malloc(sizeof(noed));
            l.last = curr->next;
            l.last->data = e;
            l.last->next = NULL;
            l.length++;
            return;
        }
        l.head = (noed *)malloc(sizeof(noed));
        l.last = (noed *)malloc(sizeof(noed));
        l.head->data = e;
        l.last->data = e;
        l.head->next = NULL;
        l.last->next = NULL;
    }
    void insert_debut(element_t e)
    {
        if (l.length > 0)
        {
            noed *curr = l.head;

            l.head = (noed *)malloc(sizeof(noed));
            l.head->data = e;
            l.head->next = curr;
            l.length++;
            return;
        }
        l.head = (noed *)malloc(sizeof(noed));
        l.last = (noed *)malloc(sizeof(noed));
        l.head->data = e;
        l.last->data = e;
        l.head->next = NULL;
        l.last->next = NULL;
    }
    void read()
    {
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
        noed *curr = l.head, *pred = l.head;
        while (curr != NULL)
        {
            if (curr->data == e && pred == curr)
            {
                pred->next = curr->next;

                l.head = pred->next;
                l.length--;
                free(pred);
                return;
            }
            else if (curr->data == e && curr->next != NULL)
            {
                pred->next = curr->next;
                free(curr);
                l.length--;
                return;
            }
            else if (curr->data == e && curr->next == NULL)
            {
                pred->next = NULL;
                free(curr);
                l.length--;
                return;
            }

            pred = curr;
            curr = curr->next;
        }
    }
    void fesionner2_list(Linked_List *l2)
    {
        while (l2->get_length() > 0)
        {
            this->insert_fin(l2->get_first_val());
            l2->delete_val(l2->get_first_val());
        }
    }
    void trie()
    {

        noed *curr = this->l.head, *suiv = this->l.head;
        element_t data;
        while (curr->next != NULL)
        {
            while (suiv != NULL)
            {
                if (curr->data > suiv->data)
                {
                    data = suiv->data;
                    suiv->data = curr->data;
                    curr->data = data;
                }
                suiv = suiv->next;
            }
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
    v->insert_debut(5);
    v->insert_debut(7);
    v->read();
    /*Linked_List *v2 = new Linked_List(770);
    v2->insert_fin(4111);
    v2->insert_fin(11);
    v2->insert_fin(2);
    v->fesionner2_list(v2);
    /*v->detruire();*/
    cout << "vous etes en train de trie la liste :) " << endl;
    v->trie();
    v->read();
    return 0;
}
