#include<bits/stdc++.h>
using namespace std;

void countsort(int a[],int n,int exp){
    int carr[10]={0};
    for(int i=0;i<n;i++){
        carr[(a[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        carr[i]+=carr[i-1];

    }
    int outarr[n];
    for(int i=n-1;i>=0;i--){
        outarr[carr[(a[i]/exp)%10]-1]=a[i];
        carr[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=outarr[i];
    }
}

void radixsort(int a[],int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max)max=a[i];
    }
    for(int exp=1;max/exp>0;exp*=10){
        countsort(a,n,exp);
    }
}

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    radixsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


}