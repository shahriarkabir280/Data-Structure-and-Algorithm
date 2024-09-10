#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int start = l, end = h;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[l], a[end]);
    return end;
}
void Qsort(int a[],int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        Qsort(a,l,pi-1);
        Qsort(a,pi+1,h);
    }
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   Qsort(arr,0,n-1);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
}