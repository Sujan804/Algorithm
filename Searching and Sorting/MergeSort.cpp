#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],const int l, const int mid, const int h){
        int l1 = mid-l+1;
        int l2 = h-mid;
        int arrl[l1];
        int arrr[l2];
        for(int i=0;i<l1;i++){
            arrl[i]=arr[l+i];
        }
        for(int i=0;i<l2;i++){
            arrr[i]=arr[mid+1+i];
        }
        int i=0;
        int j=0;
        int k = l;
        while(i<l1&&j<l2){
            if(arrl[i]<=arrr[j]){
                arr[k]=arrl[i];
                i++;
            }else{
                arr[k]=arrr[j];
                j++;
            }
            k++;
        }
        while(i<l1){
            arr[k]=arrl[i];
            i++;
            k++;
        }
        while(j<l2){
            arr[k]=arrr[j];
            j++;
            k++;
        }   

}
void mergeSort(int arr[],const int l,const int h){
    if(l>=h){
        return;
    }
    int mid = l + (h-l)/2;
    mergeSort(arr, l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
}
signed main(){
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;


}
