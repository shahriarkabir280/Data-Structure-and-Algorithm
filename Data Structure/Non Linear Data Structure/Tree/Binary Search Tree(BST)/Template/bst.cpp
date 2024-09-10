#include <bits/stdc++.h>
using namespace std;
struct BST
{
    struct node
    {
        int val;
        node *parent;
        node *left;
        node *right;
    };
    node *root = NULL;
    void insert(node *p, int x)
    {
        node *newnode = new node();
        newnode->val = x;
        newnode->parent = p;
        newnode->left = NULL;
        newnode->right = NULL;
        if (p == NULL)
        {
            root = newnode;
        }
        else if (x < p->val)
        {
            if (p->left == NULL)
            {
                p->left = newnode;
            }
            else
            {
                insert(p->left, x);
            }
        }
        else if (x > p->val)
        {
            if (p->right == NULL)
            {
                p->right = newnode;
            }
            else
            {
                insert(p->right, x);
            }
        }
    }
    node *minValueNode(node *r)
    {
        if (r == NULL)
            return NULL;
        while (r->left != NULL)
            r = r->left;
        return r;
    }
    node *deletenode(node *p, int x)
    {

        if (p == NULL)
        {
            return p;
        }
        else if (x < p->val)
        {
            p->left = deletenode(p->left, x);
        }
        else if (x > p->val)
        {
            p->right = deletenode(p->right, x);
        }
        else
        {
            if (p->left == NULL)
            {
                node *temp = p->right;
                free(p);
                return temp;
            }
            else if (p->right == NULL)
            {
                node *temp = p->left;
                free(p);
                return temp;
            }
            else
            {
                node *succParent = p;
                node *succ = p->right;
                while (succ->left != NULL)
                {
                    succParent = succ;
                    succ = succ->left;
                }
                p->val = succ->val;
                if (succ->left == succ)
                {
                    succParent->left = succ->left;
                }
                else
                {
                    succParent->right = succ->right;
                }
                free(succ);
                return p;
            }
        }
    }
    node *search(node *p, int x)
    {
        if (p == NULL || p->val == x)
            return p;
        else if (x < p->val)
        {
            return search(p->left, x);
        }
        else
        {
            return search(p->right, x);
        }
        return p;
    }
    void inorder(node *p)
    {
        // Your code starts here - 002
        if (p != NULL)
        {
            inorder(p->left);
            cout << p->val << " ";

            inorder(p->right);
        }
        // Your code ends here - 002
    }
};
int main()
{
    BST *bst = new BST();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bst->insert(bst->root, x);
    }
    bst->inorder(bst->root);
    cout << "\n";
    bst->deletenode(bst->root, 40);
    bst->inorder(bst->root);
    cout << "\n";
    if (bst->search(bst->root, 5))
        cout << "found\n";
    else
        cout << "not found\n";
}