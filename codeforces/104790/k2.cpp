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

map<pair<ll, ll>, ll> mp;

ll ask(ll x, ll y) {
    assert(available > 0);
    if (mp.count({x, y})) return mp[{x,y}];
    available--;
    cout << "? " << x << " " << y << ln;
    cout.flush();
    ll k; cin >> k;
    ans = max(ans, k);
    return k;
}

void solve_linha() {
    ll midy = (ry + ly) / 2;
    assert(midy < ry);
    
    ll baixo = 0, cima = 0;
    forn(x, lx, rx + 1) {
        baixo = max(baixo, ask(x, midy));
        cima = max(cima, ask(x, midy+1));
    }

    if (cima > baixo) {
        ly = midy+1;
    } else {
        ry = midy;
    }
}

void solve_coluna() {
    ll midx = (rx + lx) / 2;
    assert(midx < rx);

    ll esquerda = 0, direita = 0;
    forn(y, ly, ry + 1) {
        esquerda = max(esquerda, ask(midx, y));
        direita = max(direita, ask(midx+1, y));
    }
    if (direita > esquerda) {
        lx = midx + 1;
    } else {
        rx = midx;
    }
}


int main(){
    _;
    cin >> n;
    lx = 1, rx = n, ly = 1, ry = n;
    available = 5 * n + 10;
    while (available < (1 + rx - lx) * (1 + ry - ly)) {
        if ((rx - lx) < (ry - ly)) {
            solve_linha();
        } else {
            solve_coluna();
        }
    }

    forn(x, lx, rx+1) {
        forn(y, ly, ry+1) {
            ask(x, y);
        }
    }

    cout << "! " << ans << ln;
    cout.flush();

    return 0;
}