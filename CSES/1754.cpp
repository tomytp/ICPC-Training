#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L

void solve() {
    ll a, b; cin >> a >> b;

    if (b > a) swap(a,b);
    bool is_valid = ((a+b) % 3 == 0) && (b*2 >= a);
    cout << (is_valid? "YES" : "NO") << ln;
}

int main() {
    fast_cin();
    ll n; cin >> n;

    while (n--) solve();
}
