#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)


int main() {
    ll n; cin >> n;
    ll last; cin >> last;
    ll totalMoves = 0;

    forn(i, 1, n) {
        ll current; cin >> current;
        ll diff = last - current;
        if (diff > 0) {
            totalMoves += diff;
        }

        last = max(last, current);
    }
    
    cout << totalMoves << ln;
}