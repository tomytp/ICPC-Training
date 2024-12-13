#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbg(x) cout << #x << " = " << x << ln

#define MAXN 21

ll v[MAXN];

int main() {
    fast_cin();
    ll n; cin >> n;
    forn(i, 0, n) {
        cin >> v[i];
    }

    ll min_diff = 2e18;
    for(ll mask = 0; mask < (1 << n); mask++) {
        ll a = 0, b = 0;
        forn(i, 0, n) {
            if (mask & (1 << i)) {
                a += v[i];
            } else {
                b += v[i];
            }
        }

        min_diff = min(abs(a-b), min_diff);
    }

    cout << min_diff << ln;
}