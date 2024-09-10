#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln

ll n;
ll n1;
v64 vec;
v64 diff;
v64 bit;

void add(ll p, ll v) {
    for (; p<n1; p+=p&-p) bit[p] += v;
}

ll query(ll p) {
    ll r = 0;
    for (; p; p-=p&-p) r += bit[p];
    return r;
}

int main() {
    fast_cin();
    ll n, q; cin >> n >> q;
    n1 = n+1;
    vec.resize(n1);
    diff.resize(n1);
    bit.resize(n1);
    forn(i, 1, n1) {
        cin >> vec[i];
        diff[i] = vec[i] - vec[i-1];        
    }

    forn (i, 1, n1) {
        add(i, diff[i]);
    }
    
    forn(i, 0, q) {
        ll t; cin >> t;
        if (t == 2) {
            ll k; cin >> k;
            cout << query(k) << ln;
        } else {
            ll a, b, u; cin >> a >> b >> u;
            add(a, u);
            add(b + 1, -u);
        }
    }
}