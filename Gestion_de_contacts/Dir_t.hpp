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
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Dir_t()
    {
        liste = new List_t[27];
        nbre = 0;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void add(string name, string phone, string email = NULL)
    {
        nbre++;
        liste[((int)name[0]) - 65].add(name, phone, email);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void deleteList(string email, string name)
    {

        int index = (int)name[0] - 65;
        Node_t *ForDelete = liste[index].search(email);

        if (ForDelete->contact == nullptr)
        {
            cout << "there is no contact with this email" << endl;
            return;
        }

        liste[index].deleteList(email);
        nbre--;
        return;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void
    update(string name, string email, string phone = "")
    {
        int index = (int)name[0] - 65;
        Node_t *ForUpdate = liste[index].search(email);
        if (ForUpdate->contact == nullptr)
        {
            cout << "there is no contact with this email" << endl;
            return;
        }
        liste[index].update(name, email, phone);
        return;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    string toString() const
    {
        if (isEmpty())
            return "No contact in the Dir";

        string result;
        for (int i = 0; i < 26; i++)
        {
            if (liste[i].isEmpty())
                continue;

            result += "---------------------------\n";
            result += liste[i].toString();
            result += "---------------------------\n";
        }
        return result;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void print()
    {
        cout << this->toString();
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool isEmpty() const
    {
        if (nbre == 0)
            return true;
        return false;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};
#endif