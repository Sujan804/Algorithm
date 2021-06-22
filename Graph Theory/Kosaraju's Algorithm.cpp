//Author:Sujan Ahmed
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'

using namespace std;
vi ar[1001];
vi tr[1001];

vi order;
vi scc;

int vis[1001];
void dfs(int n){
    vis[n]=1;
    for(auto u:ar[n]){
       if(!vis[u])
        dfs(u);
    }
    order.push_back(n);
}
void dfs1(int n){
    vis[n]=1;
    scc.push_back(n);
    for(auto u:tr[n]){
        if(!vis[u])
            dfs1(u);
    }
}
int main(){
    int t;
    cin>>t;
    int a,b,m,n;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            vis[i]=0;
            ar[i].clear();
            tr[i].clear();
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            ar[a].push_back(b);
            tr[b].push_back(a);
        }
        order.clear();
        for(int i=1;i<=n;i++){
            if(!vis[i])
                dfs(i);
        }
        for(int i=0;i<=n;i++){
            vis[i]=0;
        }
        for(int i=1;i<n;i++){
            scc.clear();
            if(!vis[order[n-i]]){
                    dfs1(order[n-i]);
                    cout<<"dfs1() called from "<<order[n-i]<<" and printing SCC"<<endl;
                    for(auto u:scc){
                        cout<<u<<' ';
                    }
                    cout<<endl;
                }
            }
        }


    }


