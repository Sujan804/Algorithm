#include<bits/stdc++.h>
using namespace std;

void prime_fact(int n){
    int ct,i, sq = sqrt(n);
    for(i=2;i<=sq;i++){
            ct=0;
        while(n%i==0){
            ct++;
            n /= i;

        }
        if(ct>0)
        cout<<i<<'^'<<ct<<' ';
    }
    if(n!=1)
        cout<<n;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    prime_fact(n);

}
