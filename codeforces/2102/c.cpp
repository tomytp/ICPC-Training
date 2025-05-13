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

bool contained (ll x, ll y, ll n) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void solve() {
        ll n; cin >> n;
        vector<v64> g(n, v64(n, -1));
        
        ll val = 0, tot = n * n;
        ll step = 1;
        
        ll r = (n - 1) / 2;
        ll c = (n - 1) / 2;
        g[r][c] = val++;
        while(val < tot){
            forn(i, 0, step){
                c++;
                if(contained(r,c, n)) g[r][c] = val++;
            }
            forn(i, 0, step){
                r++;
                if(contained(r,c, n)) g[r][c] = val++;
            }
            step++;
            forn(i, 0, step){
                c--;
                if(contained(r,c, n)) g[r][c] = val++;
            }
            forn(i, 0, step){
                r--;
                if(contained(r,c, n)) g[r][c] = val++;
            }
            step++;
        }

        forn(i,0,n){
            forn(j,0,n){
                cout << g[i][j] << " ";
            }
            cout << ln;
        }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
