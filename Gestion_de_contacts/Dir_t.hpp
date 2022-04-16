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
    void deleteList(string email)
    {

        for (int i = 0; i < 26; i++)
        {
            Node_t *ForDelete = liste[i].search(email);
            if (ForDelete->contact == nullptr)
                continue;
            liste[i].deleteList(email);
            nbre--;
            return;
        }
        cout << "there is no contact with this email" << endl;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void update(string name, string email, string phone = "")
    {
        for (int i = 0; i < 26; i++)
        {
            Node_t *ForUpdate = liste[i].search(email);
            if (ForUpdate->contact == nullptr)
                continue;
            liste[i].update(name, email, phone);
            return;
        }
        cout << "there is no contact with this email" << endl;
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