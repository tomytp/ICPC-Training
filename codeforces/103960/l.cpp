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

ll n;
map<ll, ll> totfreq;
v64 colors;
vector<v64> g;
map<p64, ll> ans;

struct P {
    map<ll, ll> freq;
    ll sum = 0;
};

P& merge(P& a, P& b) {
    if (a.freq.size() < b.freq.size()) swap(a, b);

    for(auto& [k, v] : b.freq) {
        a.sum -= a.freq[k] * (totfreq[k] - a.freq[k]);
        a.freq[k] += v;
        a.sum += a.freq[k] * (totfreq[k] - a.freq[k]);
    }
    return a;
}

P dfs(ll u, ll parent) {
    P curr;
    ll visited = 0;
    for (auto v : g[u]) {
        if (v == parent) continue;
        visited++;
        P ret = dfs(v, u);
        curr = merge(curr, ret);
    }

    curr.sum -= curr.freq[colors[u]] * (totfreq[colors[u]] - curr.freq[colors[u]]);
    curr.freq[colors[u]]++;
    curr.sum += curr.freq[colors[u]] * (totfreq[colors[u]] - curr.freq[colors[u]]);
    
    ans[{parent, u}] = curr.sum;
    return curr;
}

int main(){
    _;
    cin >> n;
    colors.resize(n);
    forn(i, 0, n) cin >> colors[i], totfreq[colors[i]]++;
    g.resize(n);
    vector<p64> edges(n-1);
    forn(i, 0, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
    forn(i, 0, n-1) {
        ll resp = max(ans[edges[i]], ans[{edges[i].second, edges[i].first}]);
        cout << resp << " \n"[i==n-2];
    }
    return 0;
}