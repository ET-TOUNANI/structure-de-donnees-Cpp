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
    /*void delete_()
    {
    }*/
};
int main()
{
    Linked_List *v = new Linked_List(55);
    v->insert_fin(41);
    v->insert_fin(47);
    v->insert_fin(44);
    v->insert_fin(40);
    v->read();
    return 0;
}
