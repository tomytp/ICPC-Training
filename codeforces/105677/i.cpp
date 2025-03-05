#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define MAX 100007

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// Topological Sort
//
// Retorna uma ordenacaoo topologica de g
// Se g nao for DAG retorna um vetor vazio
//
// O(n + m)

vector<ll> g[MAX];

vector<ll> topo_sort(ll n) {
	vector<ll> ret(n,-1), vis(n,0);
	
	ll pos = n-1, dag = 1;
	function<void(ll)> dfs = [&](ll v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (ll i = 0; i < n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();	
	return ret;
}

int main(){
    _;

    ll n; cin >> n;
    vector<set<ll>> vizinhos(n);
    forn(i, 0, n){
        ll c; cin >> c;
        forn(j, 0, c){
            ll v; cin >> v;
            g[i].push_back(v-1);
            vizinhos[i].insert(v-1);
        }
    }

    vector<ll> topsort = topo_sort(n);

    forn(i, 1, n){
        if(vizinhos[topsort[i-1]].find(topsort[i]) == vizinhos[topsort[i-1]].end()){
            cout << 0 << ln;
            return 0;
        }
    }

    cout << 1 << ln;

    return 0;
}