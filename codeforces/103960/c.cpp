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

const ll MAXN = 1010;

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
    ll n; cin >> n;

    p64 current, last;
    cin >> last.first >> last.second;
    map<ll, vector<p64>> horiz, vert; // pos -> evento, type
    vector<vector<bool>> edge_h(MAXN, vector<bool>(MAXN));
    vector<vector<bool>> edge_v(MAXN, vector<bool>(MAXN));

    forn(i, 0, n) {
        cin >> current.first >> current.second;

        if (current.first == last.first) {
            ll a = current.second; ll b = last.second;
            if (a > b) swap(a, b);
            horiz[current.first].emplace_back(a, 1);
            horiz[current.first].emplace_back(b, -1);
        } else {
            ll a = current.first; ll b = last.first;
            if (a > b) swap(a, b);
            vert[current.second].emplace_back(a, 1);
            vert[current.second].emplace_back(b, -1);
        }
        last = current;
    }

    for (auto& [k, v] : vert) {
        sort(v.begin(), v.end());

        ll curr = 0, open_interval = 0;
        forn(i, 0, MAXN) {
            while (curr < v.size() && v[curr].first == i){
                open_interval += v[curr].second;
                curr++;
            }

            if(open_interval > 0) edge_v[i][k] = true;
        }
    }

    for (auto& [k, v] : horiz) {
        sort(v.begin(), v.end());

        ll curr = 0, open_interval = 0;
        forn(i, 0, MAXN) {
            while (curr < v.size() && v[curr].first == i){
                open_interval += v[curr].second;
                curr++;
            }

            if(open_interval > 0) edge_h[k][i] = true;
        }
    }

    dsu sdu(MAXN*MAXN);

    forn(i, 0, MAXN-1) {
        forn(j, 0, MAXN-1) {
            if (!edge_h[i+1][j]) sdu.uni(i*MAXN + j, (i+1)*MAXN+j);
            if (!edge_v[i][j+1]) sdu.uni(i*MAXN + j, i*MAXN+j+1);
        }
    }

    // forn(i, 0, MAXN) {
    //     forn(j, 0, MAXN) {
    //         cout << sdu.find(i*MAXN + j) << " \n"[j==MAXN-1];
    //     }
    // }
    // cout << ln;
    
    ll not_ans = sdu.find(MAXN*MAXN - 2);
    ll ans = 0;
    forn(i, 0, MAXN*MAXN) {
        if (sdu.find(i) == not_ans) continue;
        ans = max(ans, sdu.sz[sdu.find(i)]);
    }

    cout << ans << ln;

    return 0;
}

