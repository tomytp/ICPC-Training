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
    ll ax, ay, bx, by, cx, cy; cin >> ax >> ay >> bx >> by >> cx >> cy;

    ll dx1 = ax - bx;
    ll dy1 = ay - by;
    ll dx2 = bx - cx;
    ll dy2 = by - cy;

    bool equal_distances = dx1*dx1 + dy1*dy1 == dx2*dx2 + dy2*dy2;
    bool colinear = (by-ay)*(cx-bx) == (cy-by)*(bx-ax);


    if (equal_distances && !colinear) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    P_; return 0;
}