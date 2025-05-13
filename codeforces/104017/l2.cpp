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
const ll MAX_ANG = 10;
const ll MAX_R = 40;

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

void solve(){
    vector<vector<bool>> maze(MAX_ANG+1, vector<bool> (MAX_R, false));

    ll n; cin >> n;
    forn(ppppp, 0, n){
        char c; cin >> c;
        ll x, y, z; cin >> x >> y >> z;

        if(c == 'C'){
            if(y <= z){
                forn(i, 2*y, 2*z){
                    maze[i][2*x-1] = true;
                }
            } else {
                forn(i, 0, 2*z){
                    maze[i][2*x-1] = true;
                }
                forn(i, 2*y, MAX_ANG){
                    maze[i][2*x-1] = true;
                }
            }
        } else {
            if(z==0) z = MAX_ANG/2;
            forn(i, 2*x - 1, 2*y) maze[2*z-1][i] = true;
        }
    }

    // forn(i, 0, MAX_ANG){
    //     forn(j, 0, MAX_R){
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << ln;
    // }

    dsu sdu(MAX_ANG*MAX_R + 2);
    ll source = MAX_ANG*MAX_R, tink = MAX_ANG*MAX_R + 1;
    forn(i, 0, MAX_ANG){
        sdu.uni(source, MAX_R*i);
        if (!maze[i][MAX_R-1]) {
            sdu.uni(tink, MAX_R*i + (MAX_R-1));
        }
    }
    forn(i, 0, MAX_ANG){
        forn(j, 0, MAX_R-1){
            if(!maze[i][j] and !maze[i][j+1]) sdu.uni(MAX_R*i + j, MAX_R*i + (j+1));
            if(!maze[i][j] and !maze[(i+1)%MAX_ANG][j]) sdu.uni(MAX_R*i + j, MAX_R*((i+1)%MAX_ANG) + j);
        }
    }

    if(sdu.find(source) == sdu.find(tink)){
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

int main(){
    _; ll  t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}