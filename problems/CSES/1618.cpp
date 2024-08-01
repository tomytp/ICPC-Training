#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007L


int main() {
    fast_cin();
    ll n; cin >> n;

    ll number = 5;
    ll ans = 0;
    while (number <= n) {
        ans += n / number;
        number *= 5;
    }

    cout << ans << ln;
}