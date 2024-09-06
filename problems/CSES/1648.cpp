#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007L

#define MAXN 200002

ll bit[MAXN];
ll vec[MAXN];

void add(ll p, ll v) {
    for (; p<MAXN; p+=p&-p) bit[p] += v;
}

ll query(ll p) {
    ll r = 0;
    for (; p; p-=p&-p) r += bit[p];
    return r;
}

int main() {
    fast_cin();
    ll n; cin >> n;
    ll q; cin >> q;
    forn(i, 1, n+1) {
        cin >> vec[i];
        add(i, vec[i]);
    }

    forn(i, 0, q) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            add(a, b - vec[a]);
            vec[a] = b;
        } else {
            cout << query(b) - query(a-1) << ln;
        }
    }
}