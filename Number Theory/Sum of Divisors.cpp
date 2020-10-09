#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ct,i,result=1;
    vector <int> vecCT;
    vector <int> vecN;
    cin>>n;
    int sq = sqrt(n);

    for(i = 2; i<= sq ;i++){
        ct =0;
        while(n%i==0){
            ct++;
            n /= i;
        }
        if(ct){
            vecN.push_back(i);
            vecCT.push_back(ct);
        }



    }
    if(n!=1){
        vecN.push_back(n);
        vecCT.push_back(1);
    }
    for(i=0;i<vecN.size();i++){
        result *= ((pow(vecN[i],(vecCT[i]+1)))-1)/(vecN[i]-1);
    }
    cout<<result<<endl;
}
