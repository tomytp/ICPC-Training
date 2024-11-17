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

ll n, a, b, c; 
map<ll, ll> mp;

ll solve(ll n) {
    if (n == 0) return 0;
    if (n < 0) return -100000;

    auto cached = mp.find(n);
    if (cached != mp.end()) {
        return cached->second;
    }

    ll r = solve(n-a);
    r = max(r, solve(n-b));
    r = max(r, solve(n-c));
    mp[n] = r+1;
    return r + 1;
}

int main(){
    F_;
    cin >> n >> a >> b >> c;

    cout << solve(n) << ln;

    P_; return 0;
}