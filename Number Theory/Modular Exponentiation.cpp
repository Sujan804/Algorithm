#include<bits/stdc++.h>
using namespace std;
int modularExponentiation( int x, int n, int M){
    int result =1;
    while(n>0){
        if(n&1){// bitwise check is n is odd
            result = (result * x)%M;
        }
        x = (x*x)%M;
        n >>= 1;//Bitwise right shift to make half of n
    }
    return result;

}
int main(){
    int x,n,M;
    cin>>x>>n>>M;
    int result = modularExponentiation(x,n,M);
    cout<<result<<endl;

}
