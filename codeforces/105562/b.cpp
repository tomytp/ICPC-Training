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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    vector<v64> g(2*n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        if (v[a] == v[b]) {
            g[a].push_back(b+n);
            g[b].push_back(a+n);
        } else {
            g[a+n].push_back(b);
            g[b+n].push_back(a);
        }
    }

    v64 topo = topo_sort(g);
    reverse(topo.begin(), topo.end());

    if (topo.size() < 2*n) {
        cout << "infinity" << ln;
        return 0;
    }

    v64 dp(2*n);
    v64 max_pat(4);
    for (auto x : topo) {
        ll h_max = 0;
        for(auto filho : g[x]) {
            h_max = max(h_max, dp[filho]);
        }
        dp[x] = h_max + 1;
        if (v[x%n] == 0 && x >= n) max_pat[0] = max(max_pat[0], dp[x]);
        if (v[x%n] == 1 && x >= n) max_pat[1] = max(max_pat[1], dp[x]);
        if (v[x%n] == 0 && x < n) max_pat[2] = max(max_pat[2], dp[x]);
        if (v[x%n] == 1 && x < n) max_pat[3] = max(max_pat[3], dp[x]);
    }

    cout << *min_element(max_pat.begin(), max_pat.end()) + 1 << ln;

    // for(auto x : dp) cout << x << ln;

    return 0;
}