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

void solve() {
    ll n; cin >> n;
    map<tuple<ll,ll,ll>, ll> triples;
    map<p64, ll> fs, ft, st;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n-2) {
        triples[{v[i], v[i+1], v[i+2]}]++;
        fs[{v[i], v[i+1]}]++;
        ft[{v[i], v[i+2]}]++;
        st[{v[i+1], v[i+2]}]++;
    }
    
    ll tot = 0;
    for (auto e : triples) {
        tot += (fs[{get<0>(e.first), get<1>(e.first)}] - e.second) * e.second;
        tot += (ft[{get<0>(e.first), get<2>(e.first)}] - e.second) * e.second;
        tot += (st[{get<1>(e.first), get<2>(e.first)}] - e.second) * e.second;
    }
    cout << tot / 2 << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}