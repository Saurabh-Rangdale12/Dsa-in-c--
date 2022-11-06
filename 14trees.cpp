#include <bits/stdc++.h>
// #include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

void printPreorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(node *root)
{
    if (root != NULL)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
    }
}

int isBst(node *root)
{
    node *prev = NULL;
    node *lef = root->left;
    node *rig = root->right;

    if (root != NULL)
    {
        if (!isBst(lef))
        {
            return 0;
        }
        if (root->data <= prev->data)
        {
            return 0;
        }
        prev = root;

        return isBst(rig);
    }
    else
        return 1;
}

int search(node *root, int key)
{
    node *prev = NULL;
    node *lef = root->left;
    node *rig = root->right;

    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int itrsearch(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            cout << root->data << endl;
            return 1;
        }
        else if (root->data > key)
            root = root->left;
        else if (root->data < key)
            root = root->right;
    }
    return 0;
}

void insert(int data, node *root)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data > data)
        {
            root = root->left;
        }
        else if (root->data < data)
        {
            root = root->right;
        }
        else
        {
            cout << "Cannot be insert, already present in BST.";
            return;
        }
    }
    cout << prev->data << endl;
    node *newnode = new node(data);
    if (data < prev->data)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }
}

node *inOrderPredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *deletenode(node *root, int value)
{
    node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletenode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    node *s = new node(67);
    node *s1 = new node(50);
    node *s2 = new node(72);
    node *s3 = new node(43);
    node *s4 = new node(54);

    s->left = s1;
    s->right = s2;
    s1->left = s3;
    s1->right = s4;

    printInorder(s);
    cout << endl;
    // printPreorder(s);
    // cout << endl;
    // printPostorder(s);

    // if (isBst(s))
    // {
    //     cout << "it is bst." << endl;
    // }
    // else
    //     cout << "it is not bst." << endl;

    if (search(s, 72))
        cout << "search found" << endl;
    else
        cout << "search not found" << endl;

    cout << itrsearch(s, 43) << endl;
    if (itrsearch(s, 43))
        cout << "search found" << endl;
    else
        cout << "search not found" << endl;

    insert(62, s);
    printInorder(s);
    cout << endl
         << (((s->left)->right)->right)->data << endl;

    deletenode(s, 43);
    printInorder(s);
    return 0;
}

/*
        67
       /  \
      50    72
     /  \
    43   54

This is Bst!!
*/