#include<bits/stdc++.h>
void countsort(int arr[],int n){
   int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)max=arr[i];
    }
    int carr[max+1]={0};
    for(int i=0;i<n;i++){
        carr[arr[i]]++;
    }

    for(int i=1;i<=max;i++){
        carr[i]+=carr[i-1];
    }

    int outarr[n];
    for(int i=n-1;i>=0;i--){
        outarr[carr[arr[i]]-1]=arr[i];
        carr[arr[i]]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=outarr[i];
    }
}

using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    
    }
    
    countsort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}