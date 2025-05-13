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

struct dsu {
	vector<ll> id, sz, val;

	dsu(ll n) : id(n), sz(n, 1), val(n) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b, ll x) {
        a = find(a), b = find(b);
        if (a == b) return;
        
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
        val[a] = x;
    }
};

void solve(ll idx) {
    ll n, q; cin >> n >> q;
    v64 v(n); map<ll, ll> idx_by_val;
    dsu dus(n);
    forn(i, 0, n) {
        cin >> v[i];
        dus.val[i] = v[i];
        if (idx_by_val.find(v[i]) != idx_by_val.end()) dus.uni(idx_by_val[v[i]], i, v[i]);
        idx_by_val[v[i]] = i;
    }
    cout << "Case " << idx << ":\n";

    forn(i, 0, q) {
        ll type; cin >> type;

        if (type == 1) {
            ll x, y; cin >> x >> y;
            if (x == y) continue;
            if (idx_by_val.find(x) == idx_by_val.end()) continue;
            
            ll x_idx = idx_by_val[x];
            if (idx_by_val.find(y) == idx_by_val.end()) {
                ll rep = dus.find(x_idx);
                dus.val[rep] = y;
                idx_by_val[y] = x_idx;
            } else {
                ll y_idx = idx_by_val[y];
                dus.uni(x_idx, y_idx, y);
            }
            idx_by_val.erase(x);
        } else {
            ll k; cin >> k;
            k--;
            cout << dus.val[dus.find(k)] << ln;
        }
    }

}

int main(){
    _;
    ll t; cin >> t;
    forn(i, 1, t+1) solve(i);
    return 0;
}