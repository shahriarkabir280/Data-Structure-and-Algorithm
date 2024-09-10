#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *prev, *next;
};
Node *head = NULL;
Node *tail = NULL;
void insert_at_first(int x)
{
    Node *newnode = new Node();
    newnode->value = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = head->prev;
    }
}
void insert_at_last(int x)
{
    Node *newnode = new Node();
    newnode->value = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (tail != NULL)
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    else
    {
        head = newnode;
        tail = newnode;
    }
}
void insert_atpos(int newElement, int position)
{
    Node *newNode = new Node();
    newNode->value = newElement;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (position < 1)
    {

        cout << "\nposition should be >= 1.";
    }
    else if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != NULL)
                newNode->next->prev = newNode;
        }
        else
        {
            cout << "\nThe previous node is null.";
        }
    }
}
void delete_first_elem()
{
    if (head == NULL)
    {
        cout << "Linked list is empty.\n";
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->next->prev = NULL;
        free(temp);
    }
    cout << "DELETE\n";
}
void delete_last_element()
{
    if (head == NULL)
    {

        cout << "Linked List is empty.\n";
    }
    else if (head == tail)
    {
        Node *temp;
        temp = head;
        head = NULL;
        tail = NULL;
        temp->prev = NULL;
        free(temp);
    }
    else
    {
        Node *current = head, *temp;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        temp = current->next;
        tail = current;
        tail->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
void delete_first_x(int x)
{
    Node *temp;
    if (head->value == x)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else
    {
        Node *current = head;
        while (current)
        {
            if (current->value == x)
            {
                break;
            }
            current = current->next;
        }
        if (current->next == NULL)
        {
            Node *temp = current, *PreNode = current->prev;
            PreNode->next = NULL;
            tail = PreNode;
            free(temp);
            // cout<<PreNode->value<<"\n";
        }
        else
        {

            temp = current;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        // cout<<current->value<<"\n";
    }
}
void reversing_doublyLinkedList()
{
    Node *temp = tail;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
}
void print()
{
    Node *current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}
int main()
{
    // insert_at_first(2);
    // print();
    /*insert_at_first(3);
    insert_at_last(4);
    insert_at_first(9);
    print();
    insert_at_last(6);
    print();
    insert_at_last(7);
    print();
    insert_atpos(10, 4);
    print();
    delete_first_elem();
    print();
    delete_last_element();
    print();*/
    for (int i = 1; i <= 5; i++)
    {
        insert_at_last(i);
    }
    // insert_at_last(5);
    // print();
    // delete_first_x(5);
    reversing_doublyLinkedList();
    // print();
}