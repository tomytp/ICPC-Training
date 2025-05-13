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


ll solve(ll n, ll x, ll y) {
    ll lado = (1 << n);
    ll half = lado/2;
    if (x == half && y == half) {
        return 0;
    }

    if (x > half) x -= half;
    if (y > half) y -= half;
    return 1 + solve(n-1, x, y);
}

int main(){
    _;
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    cout << solve(n, x, y) << ln;
    return 0;
}