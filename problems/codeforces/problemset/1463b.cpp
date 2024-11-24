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
    v64 v(n);
    ll oddSum = 0, evenSum = 0;
    forn(i, 0, n) {
        cin >> v[i];
        if (i & 1) oddSum += v[i];
        else evenSum += v[i];
    }

    if (oddSum >= evenSum) {
        forn(i, 0, n) {
            if (i & 1) cout << v[i] << " \n"[i==n-1];
            else cout << 1 << " \n"[i==n-1];
        }
    } else {
        forn(i, 0, n) {
            if (i & 1) cout << 1 << " \n"[i==n-1];
            else cout << v[i] << " \n"[i==n-1];
        }
    }
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}