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
    vector<p64> pts(n);
    forn(i, 0, n) cin >> pts[i].first >> pts[i].second;
    ll minx = INF, miny = INF;
    set<p64> tot_pts;
    forn(i, 0, n) minx = min(minx, pts[i].first), miny = min(miny, pts[i].second), tot_pts.insert(pts[i]);
    sort(pts.begin(), pts.end());
    
    forn(i, 0, n) {
        p64 pt = pts[i];
        tot_pts.emplace(pt.first,t)
    }

    return 0;
}