#include "BSt.hpp"

int main()
{
    BST b1;
    b1.add(1);
    b1.add(10);
    b1.add(0);
    b1.add(7);
    b1.add(4);
    b1.add(15);
    cout << "\nAfichage prefix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.prefix(b1.getRoot());
    cout << "\nAfichage infix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.infix(b1.getRoot());
    cout << "\nAfichage postfix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.postfix(b1.getRoot());
    cout << "\ndepth is : " << b1.depth(b1.getRoot()) << endl;
}