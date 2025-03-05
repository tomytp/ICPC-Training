#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;
    ll n; cin >> n;
    vector<v64> v(n, v64(n));
    forn(i, 0, n) forn(j, 0, n) cin >> v[i][j];
    ll m = min(v[0][n-1], v[0][0]);
    m = min(v[n-1][0], m);
    m = min(v[n-1][n-1], m);

    if (m == v[0][0]) {
        cout << 0 << ln;
    }
    if (m == v[0][n-1]) {
        cout << 1 << ln;
    }
    if (m == v[n-1][0]) {
        cout << 3 << ln;
    }
    if (m == v[n-1][n-1]) {
        cout << 2 << ln;
    }
    return 0;
}