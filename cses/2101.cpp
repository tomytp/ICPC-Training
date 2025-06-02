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

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

int main(){
    _;
    ll n, m, q; cin >> n >> m >> q;
    vector<p64> arestas(m);
    forn(i, 0, m) {
        cin >> arestas[i].first >> arestas[i].second;
        arestas[i].first--; arestas[i].second--;
    }

    vector<p64> queries(q);
    v64 l(q, 0), r(q, m-1), mid(q, (m-1)/2), ans(q,-2);
    vector<v64> mid_to_idx(m);
    
    forn(i, 0, q) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; queries[i].second--;

        if (queries[i].first == queries[i].second) {  
            ans[i] = -1;
            l[i]  = 1; r[i] = 0, mid[i] = -1;
            continue;
        }
        mid_to_idx[(m-1)/2].push_back(i);
    }

    forn(i, 0, 25) {
        dsu sdu(n);
        forn(j, 0, m) {
            sdu.uni(arestas[j].first,arestas[j].second);
            for(ll k: mid_to_idx[j]){
                auto [u, v] = queries[k];

                if(sdu.find(u) == sdu.find(v)){
                    ans[k] = j;
                    r[k] = mid[k]-1;
                } else {
                    l[k] = mid[k]+1;
                }

                mid[k] = (r[k] + l[k])/2;
                if (mid[k] != j) {
                    mid_to_idx[mid[k]].push_back(k);
                }
            }
            mid_to_idx[j].clear();
        }
    }

    forn(i,0,q) cout << ans[i]+1 << ln;
    return 0;
}