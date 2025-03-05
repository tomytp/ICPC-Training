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

ll getpow(ll n) {
    if (n <= 1) return 0;
    int highestBit = 0;
    ll temp = n;
    while (temp >>= 1) {
        highestBit++;
    }
    return 1LL << highestBit;
}
v64 ind_solve(ll n) {
    if (n == 1) return {1};
    ll nxt = getpow(n);
    if (nxt == n) {
        v64 ans(n, 1);
        return ans;
    }
    v64 ans(n, 0);
    v64 temp = ind_solve(n-nxt);
    forn(i, 0, temp.size()) {
        ans[i] = temp[i];
        ans[n-temp.size()+i] = temp[i];
    }
    return ans;
}

void solve() {
    ll n, k; cin >> n >> k;

    v64 ans = ind_solve(n);
    forn(i, 0, n) cout << (ans[i]? k : 0) << " \n"[i==n-1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}