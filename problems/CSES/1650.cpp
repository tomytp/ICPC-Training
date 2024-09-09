#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln

v64 vec;

int main() {
    fast_cin();
    ll n, q; cin >> n >> q;
    vec.resize(n+1);
    forn(i, 1, n+1) {
        ll aux; cin >> aux;
        vec[i] = vec[i-1]^aux;
    }
    forn(i, 0, q) {
        ll a, b; cin >> a >> b;
        cout << (vec[a-1]^vec[b]) << ln;
    }    
}