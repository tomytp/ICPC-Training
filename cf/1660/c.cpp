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
    string s; cin >> s;
    ll n = s.size();
    set<char> pending;
    ll ans = 0;
    forn(i, 0, n) {
        if (pending.find(s[i]) != pending.end()) {
            ans += pending.size() - 1;
            pending.clear();
        } else {
            pending.insert(s[i]);
        }
    }
    ans += pending.size();

    cout << ans << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}