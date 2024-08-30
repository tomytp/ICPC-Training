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

double a, b, c, ox, oy, oz, rdado, rsup, rinf;

bool test(double r){
    double x, y, z, dist;
    x = max(fabs(ox-r), fabs(ox-(a-r)));
    y = max(fabs(oy-r), fabs(oy-(b-r)));
    z = max(fabs(oz-r), fabs(oz-(c-r)));
    dist = x*x+y*y+z*z;
    if(dist <= (r + rdado)*(r + rdado)) return 0;
    else return 1;
}

int main() {
    fast_cin();
    long double r;
    cin >> a >> b >> c;
    cin >> ox >> oy >> oz;
    cin >> rdado;
    ll bo;
    rsup = min(min(a,b),c) / 2;
    rinf = 0;
    while(rsup - rinf > 0.00000001){
        cout << setprecision(18) << fixed << (rsup - rinf) << ln;
        r = rsup/2 + rinf/2;
        bo = test(r);
        if(bo) rinf = r;
        else rsup = r;
    }
    cout << setprecision(15) << fixed << (rsup + rinf)/2 << ln;
}