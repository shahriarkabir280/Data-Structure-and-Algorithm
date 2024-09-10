#include <iostream>

using namespace std;

struct DSU {
    struct node {
        int val;
        node* parent;
        node* next;
    };

    node* head = nullptr;

    void make_set(int x) {
        node* newnode = new node();
        newnode->val = x;
        newnode->parent = newnode;
        newnode->next = head;
        head = newnode;
    }

    node* find_set(node* p) {
        if (p == p->parent) {
            return p;
        }
        return find_set(p->parent);
    }

    node* find_set(int x) {
        node* curr = head;
        while (curr) {
            if (curr->val == x) {
                return find_set(curr);
            }
            curr = curr->next;
        }
        return nullptr;
    }

   /* void union_sets(int x, int y) {
        node* node1 = find_set(x);
        node* node2 = find_set(y);

        if (!node1 || !node2) {
            // One or both elements not found in the disjoint set
            return;
        }

        node* parent1 = find_set(node1);
        node* parent2 = find_set(node2);

        if (parent1 == parent2)
            return;

        node* temp = parent1;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = parent2;
        node2->parent = parent1;
    }*/

    void union_sets(int x, int y) {
    node* node1 = find_set(x);
    node* node2 = find_set(y);

    if (!node1 || !node2) {
        // One or both elements not found in the disjoint set
        return;
    }

    node* parent1 = find_set(node1);
    node* parent2 = find_set(node2);

    if (parent1 == parent2)
        return;

    node* temp = parent2;
    while (temp) {
        temp->parent = parent1;
        temp = temp->next;
    }

    // Attach the set of node2 to the end of the set of node1
    temp = parent1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = parent2;
}

};

int main() {
    DSU* dsu = new DSU();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dsu->make_set(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu->union_sets(x, y);
    }
    int p;
    cin >> p;
    for (int j = 0; j < p; j++) {
        int r, s;
        cin >> r >> s;
        if (dsu->find_set(r) && dsu->find_set(s) && dsu->find_set(r)->val == dsu->find_set(s)->val) {
            // they are in same set
            cout << 1 << "\n";
        } else {
            // they are not in same set
            cout << 0 << "\n";
        }
    }

   
    
    return 0;
}
