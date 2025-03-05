#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;


void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll a = -1, b = -1, mm_saldo = 0;
    forn(i, 0 , n) {
        ll saldo = 0;
        ll max_saldo = 0;
        ll r = i;
        forn (j, i+1, n) {
            if (v[i] > v[j]) saldo++;
            else if (v[i] < v[j]) saldo--;
            if (saldo > max_saldo) {
                max_saldo = saldo;
                r = j;
            }
        }
        debug(i);
        debug(max_saldo);
        if (max_saldo > mm_saldo) {
            mm_saldo = max_saldo;
            a = i;
            b = r;
        }
    }
    if (a == -1) {
        cout << 1 << " " << 1 << ln;
        return; 
    }
    cout << a+1 << " " << b+1 << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}