#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

v64 v, cum;
ll n; 

ll search(ll q) {
    ll l = 0, r = n-1;
    ll result = n;
    while (l <= r) {
        ll mid = l + (r-l) / 2;
        if (q <= cum[mid]) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int main(){
    F_;
    cin >> n;
    v.resize(n);
    cum.resize(n);
    forn (i, 0, n) cin >> v[i];
    forn(i, 1, n) cum[i] = cum[i-1] + v[i-1];
    ll m; cin >> m;
    forn(i, 0, m) {
        ll q; cin >> q;
        cout << search(q) << ln;
    }
    P_; return 0;
}