#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<v64> floyd_warshall(vector<v64> d) {
    ll n = d.size();
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    return d;
}

vector<v64> floyd_warshall2(vector<v64>& d) {
    ll n = d.size();
    vector<v64> d2(n, v64(n, INF));
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) {
        if (i == k || k == j) continue;
        d2[i][j] = min(d2[i][j], d[i][k] + d[k][j]);

    }
		
    return d2;
}

int main(){
    _;
    ll n; cin >> n;
    vector<v64> v(n, v64(n));
    forn(i, 0, n)
    forn(j, 0, n) {
        cin >> v[i][j];
    }

    auto g = floyd_warshall(v);
    auto g2 = floyd_warshall2(v);
    // forn(i, 0, n) {
    //     forn(j, 0, n) {
    //         cout << g[i][j] << " \n"[j==n-1];
    //     }
    // }
    // return 0;

    forn(i, 0, n)
    forn(j, 0, n) {
        if (g[i][j] != v[i][j]) {
            cout << -1 << ln;
            return 0;
        }
    }

    ll ans = 0;
    forn(i, 0, n)
    forn(j, i+1, n) {
        if (v[i][j] == g2[i][j]) ans++;
    }
    cout << ans << ln;

    return 0;
}