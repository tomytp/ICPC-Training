#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, q; cin >> n >> q;
    map<ll, ll> sneakers_by_size;

    forn(i, 0, n) {
        ll aux; cin >> aux;
        sneakers_by_size[aux]++;
    }

    forn(i, 0, q) {
        ll x; cin >> x;
        auto it = sneakers_by_size.lower_bound(x);
        if (it != sneakers_by_size.end() && it->second > 0) {
            cout << it->first << ln;
            it->second--;
            if (it->second <= 0) sneakers_by_size.erase(it);
        } else {
            cout << -1 << ln;
        }
    }
    return 0;
}