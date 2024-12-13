#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) ((ll) (x).size())
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L

#define MAXN 200001
ll vec[MAXN];

int main() {
    fast_cin();
    ll n; cin >> n;
    ll q; cin >> q;

    vec[0] = 0;
    cin >> vec[1];
    forn(i, 2, n+1) {
        cin >> vec[i];
        vec[i] += vec[i-1];
    }

    forn(i, 0, q) {
        ll a, b; cin >> a >> b;
        cout << vec[b] - vec[a-1] << ln;        
    }

    return 0;
}