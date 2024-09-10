#include <iostream>
using namespace std;

struct AVLtree
{
    struct node
    {
        int val;
        node *parent;
        node *left;
        node *right;
        int height;
    };
    node *root = NULL;

    int getheight(node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int getBalance(node *N)
    {
        if (N == NULL)
            return 0;
        return getheight(N->left) - getheight(N->right);
    }

    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getheight(y->left), getheight(y->right)) + 1;
        x->height = max(getheight(x->left), getheight(x->right)) + 1;

        x->parent = y->parent;
        y->parent = x;
        if (T2)
            T2->parent = y;

        return x;
    }

    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getheight(x->left), getheight(x->right)) + 1;
        y->height = max(getheight(y->left), getheight(y->right)) + 1;

        y->parent = x->parent;
        x->parent = y;
        if (T2)
            T2->parent = x;

        return y;
    }

    void insert(node *&p, int x)
    {
        node *newnode = new node();
        newnode->val = x;
        newnode->height = 1;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;

        if (p == NULL)
        {
            p = newnode;
            return;
        }

        if (x < p->val)
        {
            if (p->left == NULL)
            {
                p->left = newnode;
                newnode->parent = p;
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
                newnode->parent = p;
            }
            else
            {
                insert(p->right, x);
            }
        }

        p->height = 1 + max(getheight(p->left), getheight(p->right));

        int balance = getBalance(p);

        if (balance > 1 && x < p->left->val)
        {
            p = rightRotate(p);
        }
        else if (balance < -1 && x > p->right->val)
        {
            p = leftRotate(p);
        }
        else if (balance > 1 && x > p->left->val)
        {
            p->left = leftRotate(p->left);
            p = rightRotate(p);
        }
        else if (balance < -1 && x < p->right->val)
        {
            p->right = rightRotate(p->right);
            p = leftRotate(p);
        }
    }

    node *deletenode(node *p, int x)
    {
        if (p == NULL)
        {
            return p;
        }

        if (x < p->val)
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
                node *succParent = p->right;
                node *succ = p->right;
                while (succ->left != NULL)
                {
                    succParent = succ;
                    succ = succ->left;
                }
                p->val = succ->val;
                succParent->left = deletenode(succParent->left, succ->val);
            }
        }

        p->height = 1 + max(getheight(p->left), getheight(p->right));
        int balance = getBalance(p);

        if (balance > 1 && getBalance(p->left) >= 0)
        {
            return rightRotate(p);
        }
        else if (balance > 1 && getBalance(p->left) < 0)
        {
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }
        else if (balance < -1 && getBalance(p->right) <= 0)
        {
            return leftRotate(p);
        }
        else if (balance < -1 && getBalance(p->right) > 0)
        {
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }

        return p;
    }

    void preOrder(node *p)
    {
        if (p != NULL)
        {
            cout << p->val << " ";
            preOrder(p->left);
            preOrder(p->right);
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
};

int main()
{
    AVLtree *avt = new AVLtree();
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        avt->insert(avt->root, x);
    }

    avt->preOrder(avt->root);
    cout << "\n";

    int deleteValue;

    cin >> deleteValue;
    avt->root = avt->deletenode(avt->root, deleteValue);

    avt->preOrder(avt->root);
    cout << "\n";
    if (avt->search(avt->root, 5))
        cout << "found\n";
    else
        cout << "not found\n";

    return 0;
}
