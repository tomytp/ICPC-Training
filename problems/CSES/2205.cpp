#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) ((ll) (x).size())
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L

#define NMAX 1000000

string arr[NMAX];

int main() {
    fast_cin();
    ll n; cin >> n;

    arr[0] = "0";
    arr[1] = "1";

    ll current_ind = 2;
    forn(_, 0, n-1) {
        for (ll j = current_ind - 1; j >= 0; j--) {
            arr[current_ind++] = "1" + arr[j];
            arr[j] = "0" + arr[j];
        }
    }

    forn(i, 0, (1 << n)) {
        cout << arr[i] << ln;
    }

    return 0;
}