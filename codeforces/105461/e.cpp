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

int main(){
    _;
    ll n, m, l; cin >> n >> m >> l;
    v64 p(n);
    forn(i, 0, n) cin >> p[i];
    v64 v(m);
    forn(i, 0, m) cin >> v[i];

    sort(p.begin(), p.end());
    sort(v.begin(), v.end());

    ll md = max(p[0] * 2, (l - p[n-1]) * 2);
    forn(i, 0, n-1) {
        md = max(md, p[i+1] - p[i]);
    }

    auto it = lower_bound(v.begin(), v.end(), (md + 1) / 2);
    if (it == v.end()) {
        cout << -1 << ln;
    } else {
        cout << *it << ln;
    }
    return 0;
}