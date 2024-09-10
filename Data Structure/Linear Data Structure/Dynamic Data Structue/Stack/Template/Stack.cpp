// Md.Shahriar Kabir -20
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
// using array
struct Stack
{
    int top;
    int stack_arr[MAX];
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack overflow.\n";
        }
        else
        {
            stack_arr[++top] = x;
        }
    }
    bool isEmpty()
    {
        if (top < 0)
            return true;
        else
            return false;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow.\n";
        }
        else
        {
            int x = stack_arr[top--];
            return x;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "stack underflow.\n";
        }
        else
        {
            int x = stack_arr[top];
            return x;
        }
    }
};
// using Linked List
struct Stack
{
    struct Node
    {
        int value;
        Node *next;
    };
    Node *top = NULL;
    void push(int x)
    {
        Node *newnode = new Node();
        if (newnode == NULL)
        {
            cout << "stack overflow.\n";
            exit(1);
        }
        else
        {
            newnode->value = x;
            newnode->next = top;
            top = newnode;
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow.\n";
        }
        else
        {
            int x = top->value;
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            free(temp);
            return x;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "stack underflow";
        }
        else
        {
            int x = top->value;
            return x;
        }
    }
    void print()
    {
        if (top == NULL)
        {
            cout << "stack underflow.\n";
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
                if (temp != NULL)
                    cout << "->";
            }
        }
    }
};
int main()
{ // stack using array
    struct Stack s;
    for (int i = 1; i <= 7; i++)
    {
        s.push(i);
    }
    cout << "After pop.\n";
    cout << s.pop() << "\n";
    cout << "After peek.\n";
    cout << s.peek() << "\n";
    // stack using linked list
    struct Stack s;
    for (int i = 1; i <= 7; i++)
    {
        s.push(i);
    }
    cout << "After pop.\n";
    cout << s.pop() << "\n";
    cout << "After peek.\n";
    cout << s.peek() << "\n";
    s.print();
    return 0;
}