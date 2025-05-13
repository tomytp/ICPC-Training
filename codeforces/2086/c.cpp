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

void solve() {
    ll n; cin >> n;
    v64 p(n), idx(n), solved(n);
    forn(i, 0, n) cin >> p[i];
    forn(i, 0, n) {
        p[i]--;
        idx[p[i]] = i;
        if (p[i] == i) solved[i] =true;
    }

    ll ans = 0;
    forn(i, 0, n) {
        ll q; cin >> q; q--;
        if (solved[q]) ans++;
        queue<ll> fila;
        fila.push(q);
        while(!fila.empty()) {
            ll curr = fila.front(); fila.pop();
            if (p[curr] == curr) continue;
            fila.push(p[curr]);
            ans++;
            p[curr] = curr; 
        }
        cout << ans << " \n"[i==n-1];
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}