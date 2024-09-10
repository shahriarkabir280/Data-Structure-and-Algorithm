#include<bits/stdc++.h>
#define Size 1000
using namespace std;

//using array
struct Queue{
    int qArr[Size];
    int front,rear;
    Queue(){
        front=-1;
        rear=-1;
    } 

 bool isFull(){
    if(front==0 && rear==Size-1){
        return true;
    }
    else{
        return false;
    }
 }

bool isEmpty(){
    if(front==-1){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int x){
    if(isFull()){
        cout<<"OverFlow.\n";
    }
    else{
        if(front==-1)front=0;
        rear++;
        qArr[rear]=x;
    }
}

int dequeue(){
    if(isEmpty()){
        cout<<"Underflow.\n";
       // return(-1);
    }
    else{
        int x=qArr[front];
        
        if(front>=rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }

        return x;
    }
}


void print(){
    if(isEmpty()){
        cout<<"Underflow.\n";
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<qArr[i]<<" ";
        }
    }
    cout<<"\n";
}

};


//using linked List

struct Queue{
    struct node
    {
        int val;
        node* next;
    };

    node *front=NULL,*rear=NULL;
    void enqueue(int x){
        node* newnode = new node();
        newnode->val=x;
        newnode->next=NULL;
        if(front==NULL){
           front=newnode;
           rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Empty Queue.\n";
        }
        else if(front==rear){
            int x=front->val;
            free(front);
            front=NULL;
            rear=NULL;
           // return x;
        }
        else{
            //int x=front->val;
            node* temp=front;
            front=front->next;
            free(temp);
           // return x;
        }
    }
    
    void print(){
        node* temp=front;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    
};



int main(){
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<4;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();

    return 0;
}