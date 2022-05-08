#include "pile.hpp"
using namespace std;

int calDo(int a, char c, int b)
{
    switch (c)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;
    case '/':
        if (b != 0)
            return a / b;
        else
        {
            cout << "\n\tOops ! devision by 0";
            exit(0);
        }

    default:
        return 0;
    }
}
int calcul(string expression)
{
    Pile_with_table p2;
    for (auto i : expression)
    {
        if (i <= '9' && i >= '0')
        {
            p2.push(i - '0');
        }
        else
        {
            int b = p2.pop();
            int a = p2.pop();
            p2.push(calDo(a, i, b));
        }
    }
    return p2.pop();
}
bool expression(string expression)
{
    Pile_with_linkedList<char> p2;
    for (auto i : expression)
    {
        if (p2.isEmpty() || i == '(' || i == '[' || i == '{')
        {
            p2.push(i);
        }
        else
        {
            if (i == ')' && p2.top() != '(' || i == '[' && p2.top() != '[' || i == '}' && p2.top() != '{')
                return false;
            p2.pop();
        }
    }
    return p2.isEmpty();
}

int main()
{
    string e = "34+6*1/3*";
    cout << " result of (" << e << ") est : " << calcul(e);

    /*
    if (expression("()"))
    {
         cout << "true";
    }
    else
        cout << "false";

    //-----------------------------
    /* Pile_with_table p1;
     p1.push(4);
     p1.push(8);
     p1.push(9);
     p1.push(1);
     p1.push(2);
     p1.print();
     p1.pop();
     p1.print();*/
    //-----------------------------
    //-----------------------------
    //-----------------------------
    /*Pile_with_linkedList p2;
    p2.push(4);
    p2.push(8);
    p2.push(9);
    p2.push(1);
    p2.push(2);
    p2.print();
    p2.pop();
    p2.print();*/

    return 0;
}