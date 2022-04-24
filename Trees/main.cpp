#include "BSt.hpp"
//#include "test.hpp"
int main()
{
    BST b1;
    b1.add(4);
    b1.add(10);
    b1.add(2);
    b1.add(3);
    b1.add(1);
    b1.add(7);

    b1.add(12);
    b1.add(-3);
    b1.add(3);

    // b1.add(4);
    b1.add(10);
    cout << "******************affichage infix **************** \n";
    b1.infix(b1.getRoot());
    cout << "\n******************affichage postfix **************** \n";
    b1.postfix(b1.getRoot());
    cout << "\n******************affichage prefix **************** \n";
    b1.prefix(b1.getRoot());

    if (b1.check(b1.Leafs(b1.getRoot())))
        cout
            << "\nleafs in the same level " << endl;
    else
        cout << "\nleafs not in the same level" << endl;

    cout << "\nAfichage prefix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.prefix(b1.getRoot());
    cout << "\nAfichage infix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.infix(b1.getRoot());
    cout << "\nAfichage postfix : taill (" << b1.taill(b1.getRoot()) << ")" << endl;
    b1.postfix(b1.getRoot());
    cout << "\ndepth is : " << b1.depth(b1.getRoot()) << endl;
}