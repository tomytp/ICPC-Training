#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

ll getMiddleValue(ll i) {
    // return 1 + (2 + 2 * (i-1)) * (i-1)/2;
    return i * (i-1) + 1;
}

int main() {
    fast_cin();
    ll n; cin >> n;
    ll y, x, i;

    while(n--) {
        cin >> y >> x;
        i = max(y, x);
        cout << getMiddleValue(i) + ((i&1)? (x-y) : (y-x)) << ln;
    }

    return 0;   
}