#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 topo_sort(const vector<v64>& g) {
	v64 indeg(g.size()), q;
	for (auto& li : g) for (int x : li) indeg[x]++;
	forn(i, 0, g.size()) if (indeg[i] == 0) q.push_back(i);
	forn(j, 0, q.size()) for(int x : g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
	return q;
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    auto ans = topo_sort(g);

    if (ans.size() != n) {
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }

    forn(i, 0, n) {
        cout << ans[i] + 1 << " \n"[i==n-1];
    }

    return 0;
}