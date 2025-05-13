#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
#define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
#define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll n;
ll lx, ly, rx, ry;
ll available;
ll ans = 0;

unordered_map<ll, ll> mp;

ll ask(ll x, ll y) {
    ll aux = x*n+y;
    if (mp.count(aux)) return mp[aux];
    available--;
    cout << "? " << x << " " << y << ln;
    cout.flush();
    ll k; cin >> k;
    mp[aux] = k;
    ans = max(ans, k);
    return k;
}

void solve_caixa(){
    ll midx = (lx+rx)/2;
    ll midy = (ly+ry)/2;

    ll x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    ask(midx, midy);
    forn(x, lx, midx){
        x1 = max(x1, ask(x, midy));
    }
    forn(x, midx+1, rx){
        x2 = max(x2, ask(x, midy));
    }
    forn(y, ly, midy){
        y1 = max(y1, ask(midx, y));
    }
    forn(y, midy+1, ry){
        y2 = max(y2, ask(midx, y));
    }

    ll maximo = max(x1,max(x2,max(y1,y2)));
    if(maximo == x1) rx = midx;
    if(maximo == x2) lx = midx+1;
    if(maximo == y1) ry = midy;
    if(maximo == y2) ly = midy+1;
} 


int main(){
    _;
    cin >> n;
    lx = 1, rx = n+1, ly = 1, ry = n+1;
    available = 10 * n + 100;
   
    while (available < (1 + rx - lx) * (1 + ry - ly)) {
        solve_caixa();
    }

    forn(x, lx, rx) {
        forn(y, ly, ry) {
            ask(x, y);
        }
    }

    cout << "! " << ans << ln;
    cout.flush();

    return 0;
}