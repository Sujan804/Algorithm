#include<bits/stdc++.h>
using namespace std;
int M = 200000;
//vector<int>memo[M];
int memo[200000];
int fi(int n){
    if(n==0)
        return memo[0];
    if(n==1)
        return memo[1];
    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n] =  fi(n-1)+fi(n-2);
    return memo[n];


}
int main(){
    memset(memo,-1,M);
    memo[0]=0;
    memo[1]=1;
    int n;
    cin>>n;
    fi(n);
    for(int i=0;i<n;i++){
        cout<<memo[i]<<' ';
    }
}
