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

ll n;

int main(){
    F_;
    cin >> n;
    v64 g(n), g2(n);
    ll cost = 0, total = 0;
    forn(i, 0, n) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        total += c;
        if (g[a] || g2[b]) {
            cost += c;
            g[b] = 1;
            g2[a] = 1;
        } else {
            g[a] = 1;
            g2[b] = 1;
        }
    }
    cout << min(cost, total-cost) << ln;
    P_; return 0;
}