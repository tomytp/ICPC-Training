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

v64 a, b;
ll n, m; 
map<p64, ll> mp;

ll solve(ll pa, ll pb) {
    if (pa == n) return 0;
    if (pb == m) return 0;

    auto it = mp.find({pa, pb});
    if (it != mp.end()) {
        return it->second;
    }
    ll ans;

    if (a[pa] < b[pb] - 1) ans = solve(pa+1, pb);
    else if (b[pb] < a[pa] - 1) ans = solve(pa, pb+1);
    else {
        ans = max(solve(pa+1, pb), solve(pa, pb+1));
        ans = max(ans, solve(pa+1, pb+1) + 1);
    }

    mp[{pa, pb}] = ans;
    return ans;
}

int main(){
    F_;
    cin >> n;
    a.resize(n);
    forn(i, 0, n) cin >> a[i];
    cin >> m;
    b.resize(m);
    forn(i, 0, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << solve(0, 0) << ln;
    

    P_; return 0;
}