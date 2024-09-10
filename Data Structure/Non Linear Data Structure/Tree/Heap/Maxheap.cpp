#include<bits/stdc++.h>
using namespace std;
#define MaxSize 100000
struct MaxHeap{
       int arr[MaxSize];
       int size=0;

       void insert(int val){
        arr[size]=val;
        int current=size;
        size++;
        while (current>0 && arr[current]>arr[(current-1)/2])
        {
            swap(arr[current],arr[(current-1)/2]);
            current=(current-1)/2;
        }
        
       }

       void maxheapify(int i){
        int largest=i;
        while (true)
        {
            int left =2*i+1;
            int right=2*i+2;
            if(left<size && arr[left]>arr[largest]){
                largest =left;
            }
            if(right<size && arr[right]>arr[largest]){
                largest =right;
            }
            if(largest!=i){
               swap(arr[largest],arr[i]);
               i=largest;
            }
            else {
                break;
            }
        }
        
       }

      int extracMax(){
        int Max=arr[0];
        arr[0]=arr[size-1];
        size--;
        maxheapify(0);
        return Max;
      }

      int deleteelem(int val){
        int index;
        for(int i=0;i<size;i++){
            if(arr[i]==val){
                index=i;
                break;

            }
        }
        int delelem=arr[index];
        arr[index]=arr[size-1];
        size--;
        maxheapify(index);
        return delelem;
      }

        void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

};
int main(){
    MaxHeap* mx= new MaxHeap() ;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mx->insert(x);
    }
    mx->print();
    cout<<"\n";
    cout<<mx->extracMax();
    cout<<"\n";
    mx->print();
    cout<<"\n";
    cout<<mx->deleteelem(5)<<"\n";
    mx->print();
}