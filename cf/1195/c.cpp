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

int main(){
    F_;
    ll n; cin >> n;
    v64 v1(n), v2(n);
    v64 dp1(n, 0), dp2(n, 0);

    for (auto& x : v1) cin >> x;
    for (auto& x : v2) cin >> x;

    dp1[n-1] = v1[n-1];
    dp2[n-1] = v2[n-1];

    for (ll i = n-2; i >= 0; i--) {
        dp1[i] = max(v1[i] + dp2[i+1], dp1[i+1]);
        dp2[i] = max(v2[i] + dp1[i+1], dp2[i+1]);
    }

    cout << max(dp1[0], dp2[0]) << ln;
    P_; return 0;
}