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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    v64 v(n+1, 0);

    for(ll i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            v[i] = v[i+1] + 1;
        } else {
            v[i] = v[i+1] - 1;
        }
    }

    vector<ll> gains;
    for(ll i = 1; i < n; i++) {
        if(v[i] > 0) {
            gains.push_back(v[i]);
        }
    }
    
    sort(gains.rbegin(), gains.rend());
    
    ll total = 0;
    for(ll i = 0; i < gains.size(); i++) {
        total += gains[i];
        if(total >= k) {
            cout << i + 2 << ln;
            return;
        }
    }
    cout << -1 << ln;

}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}