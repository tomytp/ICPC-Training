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
    ll n, d; cin >> n >> d;
    v64 rankings(n), points(n);
    forn(i, 0, n) cin >> rankings[i];
    forn(i, 0, n) cin >> points[i];
    ll mine = points[0] + rankings[d-1];
    ll point = n-1;
    ll pos = 1;
    forn (i, 0, d-1) {
        if (rankings[i] + points[point] > mine) {
            pos++;
        } else {
            point--;
        }
    }
    cout << pos << ln;
    P_; return 0;
}