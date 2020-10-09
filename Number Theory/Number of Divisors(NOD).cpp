#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,ct=0,i,cntD=1;
    vector <int> vec;
    cin>>n;
    int sq = sqrt(n);
    for(i=2;i<=sq;i++){
            ct=0;
        while(n%i==0){
            ct++;
            n /= i;
        }
        if(ct)
             vec.push_back(ct);

    }
    if(n!=1){
        vec.push_back(1);
    }
    int l = vec.size();
    for(i=0;i<l;i++){
        cntD *= vec[i]+1;
    }
    cout<<cntD<<endl;



}
