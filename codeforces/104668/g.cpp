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
	vector<ll> id, sz, parent;

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); parent = id; }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
        parent[a] = max(parent[a], parent[b]);
	}
};

const ll XMAX = 50;
const ll YMAX = 100'005;

int main(){
    _;
    ll n; cin >> n;
    dsu grid(XMAX*YMAX);
    vector<vector<bool>> is_water(XMAX, vector<bool>(YMAX));
    vector<dsu> cols(XMAX, dsu(YMAX));
    ll steps = 0;
    forn(i, 0, n) {
        ll t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        if (t == 1) {
            if (!is_water[x1][y1] || !is_water[x2][y2]) {
                cout << 0 << ln;
                continue;
            }
            cout << (grid.find(YMAX*x1 + y1) == grid.find(YMAX*x2 + y2)) << ln;
            continue;
        }

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        forn(x, x1, x2 + 1) {
            ll y = y1;
            while(y <= y2) {
                if (is_water[x][y]) {
                    y = cols[x].parent[cols[x].find(y)] + 1;
                    continue;
                }

                is_water[x][y] = true;
                steps++;
                if (x-1 >= 0 && is_water[x-1][y]) {
                    grid.uni(YMAX*x + y, YMAX*(x-1) + y);
                }
                if (x+1 < XMAX && is_water[x+1][y]) {
                    grid.uni(YMAX*x + y, YMAX*(x+1) + y);
                }
                if (y-1 >= 0 && is_water[x][y-1]) {
                    grid.uni(YMAX*x + y, YMAX*x + y-1);
                    cols[x].uni(y, y-1);
                }
                if (y+1 < YMAX && is_water[x][y+1]) {
                    grid.uni(YMAX*x + y, YMAX*x + y+1);
                    cols[x].uni(y, y+1);
                }
                y++;
            }
        }
    }
    
    return 0;
}