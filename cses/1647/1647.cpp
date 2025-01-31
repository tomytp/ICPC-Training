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
#define LOG 20
ll vec[MAXN][LOG];

int main() {
    fast_cin();
    ll n; cin >> n;
    ll q; cin >> q;

    forn(i, 0, n) {
        cin >> vec[i][0];
    }

    forn(j, 1, LOG) {
        forn (i, 0, n - (1 << j) + 1) {
            vec[i][j] = min(vec[i][j - 1], vec[i + (1 << (j - 1))][j - 1]);
        }
    }

    forn(i, 0, q) {
        ll a, b; cin >> a >> b;
        a--;b--;
        ll low = (ll) log2(b-a + 1);
        cout << min(vec[a][low], vec[b - (1 << low) + 1][low]) << ln;
    }

    return 0;
}