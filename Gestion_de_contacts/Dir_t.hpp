#ifndef _Dir_t_
#define _Dir_t_

#include <iostream>
#include <string>
#include "List_t.hpp"

using namespace std;
class Dir_t
{
    List_t liste[27];
    int nbre;

public:
    void add(string name, string phone, string email = NULL)
    {
        liste[((int)name[0]) - 65].add(name, phone, email);
    }
    void print()
    {
        liste[0].print();
        /*for (int i = 0; i < 27; i++)
        {
            liste[i].print();
        }*/
    }
};
#endif