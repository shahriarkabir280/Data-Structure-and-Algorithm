#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    struct node
    {
        int val;
        int priority;
        node *next;
    };
    
     node* front=NULL;

    void push (int x,int p){
        node* newnode= new node();
        newnode->val=x;
        newnode->priority=p;
        newnode->next=NULL;
        if(front->priority>p){
            newnode->next=front;
            front=newnode;
        }
        else{
           node* temp=front;
           while(temp->next!=NULL && temp->next->priority<p){
            temp=temp->next;
           }
           
           newnode->next= temp->next;
           temp->next=temp;

        }

    }
    
    void pop(){
        node* temp=front;
        front=front->next;
        free(front);
    }

    int peek(){
        return front->val;
    }
    
    bool isEmpty(){
        return (front)?true:false;
    }  

};
int main()
{
   
   Queue q;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int x,p;
    cin>>x>>p;
    q.push(x,p);
   }
   cout<<q.peek()<<" ";
  /* while((q.isEmpty())){
       cout<<q.peek()<<" ";
       q.pop();
   }
   */

return 0;


}