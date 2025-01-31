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
    set<ll> zeros, ones;
    forn(i, 0, n) {
        ll x, y; cin >> x >> y;
        if (y) ones.insert(x);
        else zeros.insert(x);
    }
    ll r = 0;
    for (auto x : zeros) {
        if (ones.find(x) != ones.end()) {
            r += zeros.size() -1;
        }
        if (ones.find(x-1) != ones.end() && ones.find(x+1) != ones.end()) {
            r += 1;
        }
    }
    for (auto x : ones) {
        if (zeros.find(x) != zeros.end()) {
            r += ones.size() -1;
        }
        if (zeros.find(x-1) != zeros.end() && zeros.find(x+1) != zeros.end()) {
            r += 1;
        }
    }
    cout << r << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}