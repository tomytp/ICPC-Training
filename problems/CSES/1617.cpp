#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007L

ll fastPower(ll base, ll expo) {
    ll result = 1;

    while (expo) {
        if (expo & 1) {
            result = (result * base) % MOD;
            expo--;
        }

        expo /= 2;
        base = (base * base) % MOD;
    }
    return result;
}

int main() {
    fast_cin();
    ll n; cin >> n;

    cout << fastPower(2L, n) << ln;
}
