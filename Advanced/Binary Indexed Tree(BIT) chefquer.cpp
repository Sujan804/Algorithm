/** PUSH YOURSELF TO THE LIMIT**/
/*** Sujan Ahmed ***/
/**** Updated: 10-06-21||10:24 PM **/
/*** Last Edit: #define **/
#include<bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);cout.tie(nullptr);
//#define endl "\n"
#define l64 __int64
//#define MOD 100000007
#define maxN 1000000
#define maxN 1000000
#define PB push_back
#define rsort(vec) vec.rbegin(),vec.rend()
#define bset(n) bitset<n>
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define repw(i,a,b) for( int i=a;a<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define TC int testcase, CT=0; cin>>testcase;while(testcase--)
#define test  cout<<"Okay"<<endl;

#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define f0(x)             __builtin_clz(x)
#define l0(x)             __builtin_ctz(x)
#define isEven(x)         __builtin_parity(x)



using namespace std;
using ll= long long;

using pii = pair<int,int>;
using pll = pair<long long,long long>;
using pcc = pair<char ,char>;
using pdd = pair<double,double>;
using pci = pair<char,int>;
using si = set<int>;
using s = string;

using seti = set<int>;
using useti = unordered_set<int>;
using mseti = multiset<int>;
using umseti = unordered_multiset<int>;


using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;

using msi = map<string,int>;
using mii = map<int,int>;
using mci = map<char,int>;
using umsi = unordered_map<string,int>;

const int mod = (int)1e9+7;
const int maxn = (int)2e5+5;
const int inf = 1e9+9;
const ll INF = 1e18;
const double pi = 3.141592653589793;
const ll MOD = (ll)1e9 + 7;

ll binPow(ll a, ll q, ll MOD = 1e9 + 7) {
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, MOD)) % MOD;
}
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,-1,1,-1,1};
ll dyy[]={1,0,-1,0,-1,1,1,-1};

struct FenwickTree {
	vector<int> bit;  // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0ll);
	}

	void add(int idx, int val) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += val;
	}

	void range_add(int l, int r, int val) {
		add(l, val);
		add(r + 1, -val);
	}

	int get(int idx) { //
		int ret = 0;
		for (++idx; idx > 0ll; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	FenwickTree B1(n), B2(n), B3(n);

	while (q--) {
		int type;; cin >> type;
		if (type == 1) {
			int l, r, x; cin >> l >> r >> x;
			int y = x - l;
			l--, r--;		
			B1.range_add(l, r, y * y);
			B2.range_add(l, r, y * 2);
			B3.range_add(l, r, 1ll);
		}
		else {
			int i; cin >> i;
			int ans = a[i - 1] + B1.get(i - 1) + i * B2.get(i - 1) + i * i * B3.get(i - 1);
			cout << ans << '\n';
		}
	}
}

//#define LOCAL szn_qwerty
//#define TestCase szn_qwert
//#define Kick szn_qwert
int main(){
    //IO
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif
    #ifdef TestCase
    TC
    {
        #ifdef Kick
            cout << "Case #" << ++CT <<": " ;
        #endif // Kick
        solve();
    }
    #endif // TestCase
    #ifndef TestCase
    solve();
    #endif // TestCase
    return 0;

}



