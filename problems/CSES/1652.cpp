#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln

int main() {
    FAST_CIN;
    ll n, q; cin >> n >> q;
    vv64 forest(n+1, v64(n+1));
    forn(i, 1, n+1) {
        forn (j, 1, n+1) {
            char aux; cin >> aux;
            if (aux == '*') forest[i][j] = 1;
            else forest[i][j] == 0;
            forest[i][j] += (forest[i][j-1] + forest[i-1][j]) - forest[i-1][j-1];
        }
    }

    forn(i, 0, q) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << forest[x2][y2] + forest[x1-1][y1-1] - forest[x2][y1-1] - forest[x1-1][y2] << ln;
    }
}