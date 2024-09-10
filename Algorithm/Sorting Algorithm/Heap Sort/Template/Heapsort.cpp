#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100000

struct MaxHeap
{
    int heapArr[MAX_SIZE];
    int size=0;

    void insert(int val)
    {
        if (size == MAX_SIZE)
        {
            cout << "Heap is full!\n";
            return;
        }

        int current = size;
        heapArr[current] = val;
        size++;

        while (current > 0 && heapArr[(current - 1) / 2] < heapArr[current])
        {

            int temp = heapArr[current];
            heapArr[current] = heapArr[(current - 1) / 2];
            heapArr[(current - 1) / 2] = temp;

            current = (current - 1) / 2;
        }
    }

    int extractMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty!\n";
            return -1;
        }
        int max = heapArr[0];
        heapArr[0] = heapArr[size - 1];
        size--;
       max_heapify(0);
        return max;
    }

    void max_heapify(int i)
    {   
        while (true)
        {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heapArr[left] > heapArr[largest])
            {
                largest = left;
            }

            if (right < size && heapArr[right] > heapArr[largest])
            {
                largest = right;
            }

            if (largest != i)
            {
                int temp= heapArr[i];
                heapArr[i]=heapArr[largest];
                heapArr[largest]=temp;
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
};

void heapSort_Ascending(int arr[], int n)
{
    MaxHeap maxHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.insert(arr[i]);
    }

    for (int i = n-1; i >= 0; --i)
    {
        arr[i] = maxHeap.extractMax();
    }
}

void heapSort_Descending(int arr[], int n)
{
    MaxHeap maxHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.insert(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = maxHeap.extractMax();
    }
}

int main()
{   
    
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {   
        cin >> arr[i];
    }
    heapSort_Ascending(arr, n);

    cout << "[";
    for (int i = 0; i < n - 1; ++i)
    {
        cout << arr[i] << ",";
    }
    cout << arr[n - 1] << "]";

    return 0;
}
