#include "palindrome.hpp"

int main()
{

    Palindrome f1;
    /* f1.insert("tot");
    f1.print();
    cout << endl;
    if (isPolindrome(f1))
        cout << "yes ,it's a palindrome Number" << endl;
    else
        cout << "No :(" << endl;
    f1.print();*/
    f1.enqueue(10);
    f1.enqueue(2);
    f1.enqueue(4);
    //.dequeue();
    f1.enqueue(8);
    f1.enqueue(6);
    // f1.print();
    //  f1.dequeue();
    //  f1.dequeue();
    cout << endl;
    f1.print();
}