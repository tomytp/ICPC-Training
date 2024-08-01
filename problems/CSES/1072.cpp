#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L


int main() {
    fast_cin();
    ll n; cin >> n;

    forn(i, 1, n+1) {
        ll n2 = i*i;
        cout << (n2 * (n2-1)) / 2  - ((i - 2) * (i - 1) * 4) << ln;
    }
}
