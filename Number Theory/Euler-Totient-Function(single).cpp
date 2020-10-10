#include<bits/stdc++.h>
using namespace std;

int totient_phi(int n){
    if(n==1)
        return 1;
    int res = n;
    for(int i = 2;i<=sqrt(n);i++){
            
            if(n%i==0){
                while(n%i==0){
                    n /= i;
                }
                res -= res/i;
            }
    }
    if(n>1)
        res -= res/n;
    return res;
}
int main(){
    int n;
    cin>>n;

    cout<<totient_phi(n);
}
