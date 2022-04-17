#include "pile.hpp"

int main()
{
    //-----------------------------
    Pile_with_table p1;
    p1.push(4);
    p1.push(8);
    p1.push(9);
    p1.push(1);
    p1.push(2);
    p1.print();
    p1.pop();
    p1.print();
    //-----------------------------
    //-----------------------------
    //-----------------------------
    Pile_with_linkedList p2;
    p2.push(4);
    p2.push(8);
    p2.push(9);
    p2.push(1);
    p2.push(2);
    p2.print();
    p2.pop();
    p2.print();
    return 0;
}