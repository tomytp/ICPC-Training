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
	vector<ll> id, sz;
    ll tot_s, biggest;

	dsu(ll n) : id(n), sz(n, 1), tot_s(n), biggest(1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
        tot_s--;
        biggest = max(biggest, sz[a]);
	}
};

int main(){
    _;
    ll n, m; cin >> n >> m;
    dsu dus(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;

        dus.uni(a, b);
        cout << dus.tot_s << " " << dus.biggest << ln;
    }
    
    return 0;
}