#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
const int N = 1e5 + 5;
vector<int> adj[N], vis(N), in(N), low(N);
int timer;
unordered_set<int> s;

void dfs(int node, int par = -1) {
	vis[node] = 1;
	low[node] = in[node] = timer++;
	int c = 0;
	for(auto child : adj[node]) {
		if(child == par) continue;

		if(vis[child]) {
			low[node] = min(low[node], in[child]);
		}
		else {
			dfs(child, node);
			low[node] = min(low[node], low[child]);
			if(low[child] >= in[node] and par != -1)
				s.insert(node);
			c++;
		}
	}

	if(par == -1 and c > 1) s.insert(node);
}

int main() {

	fastio;

	while(1) {
		int n, m, u, v;
		cin >> n >> m;

		if(n == 0 and m == 0) break;

		for(int i = 1; i <= n; i++) {
			adj[i].clear();
			vis[i] = 0;
		}

		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		timer = 0;
		s.clear();

		for(int i = 1; i <= n; i++)
			if(!vis[i])
				dfs(i);

		cout << s.size() << "\n";
	}

	return 0;
}
