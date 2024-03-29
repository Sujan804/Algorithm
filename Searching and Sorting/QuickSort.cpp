#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int l,int h){
    int pivot = arr[h];
    int i =l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return (i+1);
}
void quickSort(int arr[],int l, int h){
    if(l<=h){
        int p = partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array befor sorted : "<<endl;
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"Array after sorted :"<<endl;
    printArray(arr,n);
    return 0;
}
