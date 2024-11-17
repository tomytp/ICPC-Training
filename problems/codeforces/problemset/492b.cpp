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
    ll n, l; cin >> n >> l;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll dist = max(v[0], l-v[n-1]);
    dist *= 2;
    forn(i, 1, n) {
        dist = max(dist, v[i]-v[i-1]);
    }
    cout << setprecision(15) << (double)dist/2 << ln;    
    P_; return 0;
}