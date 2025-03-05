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
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;

    ll seconds = 0;
    for (auto c : s) {
        if (c == 'R') x++;
        else x--;
        seconds++;
        if (x == 0) break;
        if (seconds == k) {
            cout << 0 << ln;
            return;
        }
    }
    if (x != 0) {
        cout << 0 << ln;
        return;
    }

    ll count_loop = 0;
    for (auto c : s) {
        if (c == 'R') x++;
        else x--;
        count_loop++;
        if (x == 0) break;
    }
    if (x != 0) {
        cout << 1 << ln;
        return;
    }

    ll remaining = k - seconds;
    ll ans = 1 + remaining / count_loop;
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}