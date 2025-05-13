#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct dsu {
	vector<ll> id, sz;

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

#define forn(i, n) for(int i = 0; i < (n); i++)

signed main(void){
    ios_base::sync_with_stdio(false);cin.tie(NULL);



    return 0;
}
