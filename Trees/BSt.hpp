#ifndef _BST_
#define _BST_
#include <iostream>
#include <vector>
using namespace std;
typedef struct node
{
    int data;
    int livel;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data = d;
        livel = 0;
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
    bool isLeaf(node *);
    int somme_Leaf(node *);
    vector<int> Leafs(node *);
    int count_Leaf(node *);
    bool check(vector<int>);
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
    node *current = root;
    int lev = 0;
    while (current != nullptr)
    {
        lev++;
        if (current->data > d)
        {
            if (current->left != nullptr)
            {

                current = current->left;
                continue;
            }
            current->left = new node(d);
            current->left->livel = lev;
            return;
        }
        else
        {
            if (current->right != nullptr)
            {
                current = current->right;
                continue;
            }
            current->right = new node(d);
            current->right->livel = lev;
            return;
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
bool BST ::isLeaf(node *bt)
{
    if (bt->left == nullptr && bt->right == nullptr)
        return true;
    return false;
}
BST::~BST()
{
    delete root;
}

int BST::somme_Leaf(node *bt)
{

    if (bt == nullptr)
        return 0;

    static int res = 0;
    if (isLeaf(bt))
        res += bt->data;

    somme_Leaf(bt->left);
    somme_Leaf(bt->right);
    return res;
}
int BST::count_Leaf(node *bt)
{

    if (bt == nullptr)
        return 0;

    static int res = 0;
    if (isLeaf(bt))
        res += 1;

    count_Leaf(bt->left);
    count_Leaf(bt->right);
    return res;
}

vector<int> BST::Leafs(node *bt)
{
    vector<int> v;
    if (bt == nullptr)
        return v;

    static vector<int> q;
    if (isLeaf(bt))
        q.push_back(bt->livel);

    Leafs(bt->left);
    Leafs(bt->right);
    return q;
}
bool BST::check(vector<int> int_vector)
{
    int level = int_vector[0];
    for (int i = 1; i < int_vector.size(); i++)
    {
        if (level != int_vector[i])
            return false;
    }
    return true;
}
#endif