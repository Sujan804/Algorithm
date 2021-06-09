#include<bits/stdc++.h>
using namespace std;
#define MAX 30000+5
int parent[MAX];
int cnt[MAX];
void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        cnt[i]=1;
    }

}
int Find(int u){
    if(u == parent[u])return u;
    return parent[u]=Find(parent[u]);
}
void Union(int u, int v){
    int p = Find(u);
    int q = Find(v);
    if(p!=q){
        parent[q] = p;
        cnt[p] += cnt[q];
    }
}
int findsize(int u){
    if(u == parent[u])return cnt[u];
    return findsize(parent[u]);
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,m,gm,f,temp;
    while(cin>>n>>m &&(m+n)>0){
        //cin>>n>>m;
        init(n);
        for(int g=1;g<=m;g++){
            int gm;
            cin>>gm;
            cin>>f;
            for(int i=2;i<=gm;i++){
                cin>>temp;
                Union(f,temp);
            }

        }
        cout<<findsize(0)<<endl;

    }




}
