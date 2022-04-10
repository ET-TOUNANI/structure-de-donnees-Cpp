#ifndef _Dir_t_
#define _Dir_t_

#include <iostream>
#include <stdio.h>
#include <string>
#include "List_t.hpp"

using namespace std;
class Dir_t
{
    List_t *liste;
    int nbre;

public:
    Dir_t()
    {
        liste = new List_t[27];
        nbre = 0;
    }
    void add(string name, string phone, string email = NULL)
    {
        nbre++;
        liste[((int)name[0]) - 65].add(name, phone, email);
    }
    void deleteList(string email)
    {
        nbre--;
        for (int i = 0; i < 26; i++)
        {
            if (liste[i].search(email) == true)
            {
                liste[i].deleteList(email);
                return;
            }
        }
        cout << "there is no contact with this email" << endl;
    }

    void print()
    {
        for (int i = 0; i < 26; i++)
        {
            printf("%c : \n", i + 65);
            cout << "---------------------------" << endl;
            liste[i].print();
            cout << "---------------------------" << endl;
        }
    }
};
#endif