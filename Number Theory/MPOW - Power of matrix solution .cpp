#include<bits/stdc++.h>
using namespace std;
#define N 101
#define mod 1000000007
#define ll long long
ll ar[N][N],I[N][N];
void printMat(ll A[][N],ll dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
}
void mul(ll A[][N],ll B[0][N],ll dim){
    ll res[dim+1][dim+1];
      for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                res[i][j]=0;
                for(int k=0;k<dim;k++){
                    //res[i][j] += (A[i][k]*B[k][j])%mod;
                    res[i][j] = (res[i][j] % mod + ((A[i][k] % mod) * (B[k][j] % mod) % mod)) % mod;
                    //res[i][j] %= mod;
                }
            }

        }
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                A[i][j]= res[i][j];
            }
        }
}
void power(ll A[][N],int dim,int n){
      for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                if(i==j)
                    I[i][j]=1;
                else
                    I[i][j]=0;
            }
        }
        /*for(int i=0;i<n;i++){
            mul(I, A, n);
        }*/
        while(n){
            if(n&1){
                mul(I,A,dim);
                n--;
            }else{
                mul(A,A,dim);
                n /= 2;
            }
        }
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++)
                A[i][j]=I[i][j];
        }

}
int main(){
    int t,dim,n;
    cin>>t;
    while(t--){
        cin>>dim>>n;
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++)
                cin>>ar[i][j];
        }
        power(ar,dim,n);
        printMat(ar, dim);
    }
}
