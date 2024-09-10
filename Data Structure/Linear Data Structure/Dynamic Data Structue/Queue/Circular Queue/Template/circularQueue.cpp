#include<bits/stdc++.h>
using namespace std;
//#define n 7

//using array
struct Queue{
    int *qArr;
    int front,rear,n;
    Queue(int size){
        n=size;
        qArr=new int[size];
        front=-1;
        rear=-1;
    }

 bool isFull(){
    if(front==0 && rear==n-1){
        return true;
    }
    if(front==rear + 1){
        return true;
    }
    return false;
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
        cout<<"Overflow.\n";
    }
    else{
        if(front==-1)front=0;
        rear=(rear+1)%n;
        qArr[rear]=x;
    }
}

int dequeue(){
    if(isEmpty()){
        cout<<"Underflow.\n";
        return -1;
    }
    else{
        int x= qArr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%n;
        }
        return x;
    }
}

void print(){
    int i;
    for(i=front;i!=rear;i=(i+1)%n){
        cout<<qArr[i]<<" ";
    }
    //cout<<qArr[i];
    cout<<"\n";
}
};


//using Linked List

struct QQueue{
    struct node
    {
        int val;
        node* next;
    };

    node *front=NULL,*rear=NULL;
    void enqueue(int x){
        node* newnode = new node();
        newnode->val=x;
        if(front==NULL){
           front=newnode;
        }
        else{
            rear->next=newnode;
        }

        rear=newnode;
        rear->next=front;
    }

    int dequeue(){
        if(front==NULL){
            cout<<"Empty Queue.\n";
        }
        else if(front==rear){
            int x=front->val;
            free(front);
            front=NULL;
            rear=NULL;
            return x;
        }
        else{
            int x=front->val;
            node* temp=front;
            front=front->next;
            rear->next=front;
            free(temp);
           return x;
        }
    }
    
    void print(){
        node* temp=front;
        while(temp!=rear){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<temp->val;
        cout<<"\n";
    }
    
};




int main(){
  int n;
  cin>>n;
  Queue q(n);
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    q.enqueue(x);
  }
  q.print();
  q.dequeue();
  q.dequeue();

  q.print();
  q.enqueue(9);
  q.enqueue(20);
  q.enqueue(5);
  q.print();
  q.enqueue(22);


}