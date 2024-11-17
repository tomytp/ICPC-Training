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

ll n, m;

ll solve(ll start, ll target) {
    ll tot = 0;
    ll half = (target + (target&1)) / 2;
    if (start < half) {
        tot += solve(start, half);
        start = half;
    }

    while (start != target) {
        if (start <= (target + (target & 1)) / 2) {
            start *= 2;
            tot++;
        } else {
            tot++;
            start--;
        }
    }
    return tot;
}

int main(){
    F_;
    cin >> n >> m;

    cout << solve(n, m) << ln;
    P_; return 0;
}