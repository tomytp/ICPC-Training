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

ll n; 

bool is_valid(ll kk, v64& v) {
    if (kk == 0) return true;
    deque<ll> q;
    forn(i, 0, n) {
        q.push_back(v[i]);
    }

    for (ll k = kk; k >=0; k--) {
        while (!q.empty() && k < q.back()) {
            dbg(q.back());
            dbg(k);
            q.pop_back();
        }
        if (q.empty()) return false;
        q.pop_back();
        if (k == 1) return true;
        if (q.empty()) return false;
        q.pop_front();
    }
    return false;
}

void solve() {
    cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll l = 0, r = n;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r-l) / 2;
        if (is_valid(mid, v)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}