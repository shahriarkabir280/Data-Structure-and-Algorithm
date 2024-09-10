#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000

struct MinHeap
{
    int heapArr[MAX_SIZE];
    int size = 0;

    void insert(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "Heap is full. Cannot insert." << endl;
            return;
        }
        size++;
        int index = size - 1;
        heapArr[index] = value;

        while (index > 0 && heapArr[index] < heapArr[(index - 1) / 2])
        {
            int temp = heapArr[index];
            heapArr[index] = heapArr[(index - 1) / 2];
            heapArr[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    }

    int deleteMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty. Cannot delete minimum." << endl;
            return INT_MAX; // or any appropriate handling for an empty heap
        }
        int minValue = heapArr[0];
        heapArr[0] = heapArr[size - 1];
        size--;
        min_heapify(0);
        return minValue;
    }

    void deleteElement(int value)
    {
        int index;
        for (index = 0; index < size; index++)
        {
            if (heapArr[index] == value)
                break;
        }

        if (index == size)
        {
            cout << "Element not found in the heap." << endl;
            
        }

        heapArr[index] = heapArr[size - 1];
        size--;
        min_heapify(index);
      
    }

    int getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty." << endl;
            return INT_MAX; 
        }
        return heapArr[0];
    }


    void min_heapify(int index)
    {
        int smallest = index;
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heapArr[left] < heapArr[smallest])
                smallest = left;

            if (right < size && heapArr[right] < heapArr[smallest])
                smallest = right;

            if (smallest != index)
            {
                swap(heapArr[index], heapArr[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    MinHeap* minHeap= new MinHeap();
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
       int x,v;
       cin>>x;
       if(x!=3){
        cin>>v;
       }
       if(x==1){
        minHeap->insert(v);
       }
       else if(x==2){
        minHeap->deleteElement(v);
       }
       else if(x==3){
        cout<<minHeap->getMin()<<"\n";
       }
    }

    return 0;
}
