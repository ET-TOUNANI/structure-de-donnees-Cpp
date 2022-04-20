#ifndef _BST_
#define _BST_
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
} node;
class BST
{
private:
    /* data */
    node *root;

public:
    BST(/* args */);
    void add(int);
    node *getRoot();
    int depth(node *);
    int taill(node *);
    void infix(node *);
    void prefix(node *);
    void postfix(node *);
    bool isLeaf(node const &);
    ~BST();
};

BST::BST(/* args */)
{
    root = nullptr;
}
int pt = 0;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int BST::depth(node *bt)
{
    if (bt == nullptr)
        return 0;
    return 1 + max(depth(bt->left), depth(bt->right));
}
int BST::taill(node *bt)
{
    if (bt == nullptr)
        return 0;
    return 1 + taill(bt->left) + taill(bt->right);
}
void BST::add(int d)
{
    if (root == nullptr)
    {
        root = new node(d);
        return;
    }

    node *temp = root;
    node *father = nullptr;
    while (1)
    {
        father = temp;
        if (father->data <= d)
        {
            temp = temp->right;
            if (temp == nullptr)
            {
                father->right = new node(d);
                return;
            }
        }
        else
        {
            temp = temp->left;
            if (temp == nullptr)
            {
                father->left = new node(d);
                return;
            }
        }
    }
}
node *BST::getRoot()
{
    return root;
}
void BST::prefix(node *bt)
{
    if (bt == nullptr)
        return;
    cout << bt->data << "  --- ";
    prefix(bt->left);
    prefix(bt->right);
}
void BST::infix(node *bt)
{
    if (bt == nullptr)
        return;
    infix(bt->left);
    cout << bt->data << "  --- ";
    infix(bt->right);
}
void BST::postfix(node *bt)
{
    if (bt == nullptr)
        return;
    postfix(bt->left);
    postfix(bt->right);
    cout << bt->data << "  --- ";
}
bool isLeaf(node const &bt)
{
    if (bt.left == nullptr && bt.right == nullptr)
        return true;
    return false;
}
BST::~BST()
{
    delete root;
}

#endif