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

map<ll, ll> factors(ll n) {
    map<ll, ll> mp;
    for(ll i = 2; i*i <= n; i++) {
        while (n%i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

void solve() {
    ll a, b; cin >> a >> b;
    map<ll, ll> out, ma, mb;
    ma = factors(a);
    mb = factors(b);
    for(auto [k, v] : ma) {
        out[k] = max(out[k], v);
    }
    for(auto [k, v] : mb) {
        out[k] = max(out[k], v);
    }
    ll ans = 1;
    for (auto [k, v] : out) {
        forn(i, 0, v) {
            ans *= k;
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