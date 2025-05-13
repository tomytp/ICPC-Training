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

int main(){
    _;
    ll n, m; cin >> n >> m;
    bitset<1005> v;
    vector<bitset<1005>> switches(n);
    ll l; cin >> l;
    forn(i, 0, l) {
        ll aux; cin >> aux;
        aux--;
        v[aux] = true;
    }

    forn(i, 0, n) {
        ll c; cin >> c;
        forn(j, 0, c) {
            ll aux; cin >> aux;
            aux--;
            switches[i][aux] = true;
        }
    }

    if (!v.count()) {
        cout << 0 << ln;
        return 0;
    }

    forn(i, 0, 2*n) {
        v ^= switches[i%n];
        if (!v.count()) {
            cout << i+1 << ln;
            return 0;
        }
    }

    cout << -1 << ln;

    return 0;
}