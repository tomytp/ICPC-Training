#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


int main() {
    fast_cin();
    ll q; cin >> q;
    double p, r, y;
    forn(i,0,q){
        cin >> p >> r >> y;
        double a,b, c;
        double n,w,e,s;
        a = r;
        b = (y-p-r)/2;
        c = (p-r+y)/2;
        s = (max(max(-a,0.0),max(b,c)) - max(max(a,0.0),max(-b,-c)))/2;
        n = a + s +0.0;
        w = b - s+0.0;
        e = c - s+0.0;
        s = s+0.0;
        cout << setprecision(7) << n << ' ' << e << ' ' << s << ' ' << w << ln;
    }
    

}