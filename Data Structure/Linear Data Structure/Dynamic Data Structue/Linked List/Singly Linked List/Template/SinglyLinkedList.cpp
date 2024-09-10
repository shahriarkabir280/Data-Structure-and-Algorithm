// Md.Shahriar Kabir -20
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    struct Node *next;
};
Node *head = NULL;
Node *tail = NULL;
void insert_at_first(int x)
{
    Node *newnode = new Node();
    // Node* newnode= (Node*)malloc(sizeof(Node));
    newnode->value = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insert_at_last(int x)
{
    Node *newnode = new Node();
    newnode->value = x;
    newnode->next = NULL;
    if (tail)
    {
        tail->next = newnode;
        tail = newnode;
    }
    else
    {
        head = newnode;
        tail = newnode;
    }
}
void insert_atpos(int pos, int x)
{
    Node *current = head, *temp;
    Node *newnode = new Node();
    newnode->value = x;
    newnode->next = NULL;
    int flag = 0;
    if (pos == 1 || pos == 0)
    {
        newnode->next = head;

        head = newnode;
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        if (current->next == NULL)
        {
            flag = 1;
        }
        else
        {
            current = current->next;
        }
    }
    if (flag)
    {
        cout << "Invalid Position-Position is greater than the size of linked list.\
n";
        return;
    }
    newnode->next = current->next;
    current->next = newnode;
    return;
}
void delete_first_elem()
{
    if (head == NULL)
    {
        cout << "Linked list is empty.\n";
    }
    else if (head == tail)
    {
        cout << head << "\n";
        free(head);
        head == NULL;
        tail = NULL;
        cout << head << "\n"
             << tail << "\n";
    }
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
void delete_last_element()
{
    if (head == NULL)
    {
        cout << "Linked list is empty.\n";
    }
    else if (head == tail)
    {
        Node *temp = head;
        head == NULL;
        tail == NULL;

        free(temp);
    }
    else
    {
        Node *current = head, *temp;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        tail = current;
        free(current->next);
        tail->next = NULL;
    }
}
void delete_first_x(int x)
{
    if (head == NULL)
    {
        cout << "Linked List is empty.\n";
    }
    else if (head == tail)
    {
        if (head->value == x)
        {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout << "The value doesn't exist in the Linked list.\n";
        }
    }
    else
    {
        Node *temp, *current = head;
        int flag = 0;
        while (current->next)
        {
            if (current->next->value == x)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                flag = 1;
                break;
            }
            current = current->next;
        }
        if (!flag)
        {
            cout << "The value doesn't exist in the linked list.\n";
        }
    }
}

void reversing_linkedlist()
{
    Node *prev = NULL, *current = head, *Next = NULL;
    while (current)
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    head = prev;
}
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_at_last(x);
    }
    print();
    int pos, data;
    cin >> pos >> data;
    insert_atpos(pos, data);
    print();
    delete_first_elem();
    print();
    delete_last_element();
    print();
    insert_at_first(4);
    insert_at_last(5);
    print();
    delete_first_x(3);
    cout << "after deleting first x.\n";
    print();
    cout << "\nAfer reversing the linked List.\n";
    reversing_linkedlist();
    print();
    delete_first_x(3);
    return 0;
}