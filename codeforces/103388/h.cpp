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
    ll n, k; cin >> n >> k;
    map<ll, v64> idx, vals;
    forn(i, 0, n) {
        ll val, color; cin >> val >> color;
        idx[color].push_back(i);
        vals[color].push_back(val);
    }
    v64 ans(n);
    for (auto& [color, vec] : vals) {
        sort(vec.begin(), vec.end());
        forn(i, 0, vec.size()) {
            ans[idx[color][i]] = vec[i];
        }
    }

    bool sorted = true;
    forn(i, 1, n) {
        if (ans[i] < ans[i-1]) {
            sorted = false;
            break;
        }
    }

    cout << (sorted? "Y" : "N") << ln;
    return 0;
}