#include<bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
   int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n){
	int min_ind,j;
	for(int i=0;i<n-1;i++){
		min_ind = i;
		for(int j=i+1;j<n;j++)
			if(arr[min_ind]>arr[j])
				min_ind = j;
		swap(&arr[min_ind],&arr[i]);
	}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Befor Sorting:"<<endl;
	printArray(arr,n);
	selectionSort(arr,n);
	cout<<"After Sorting:"<<endl;
	printArray(arr,n);
	return(0);
}
