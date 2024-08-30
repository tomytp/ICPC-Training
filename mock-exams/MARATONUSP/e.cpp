#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<int, int> p32;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v64> vv64;

#define forn(i,s,e) for(ll i = s; i < e; ++i)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

ll xzao,yzao,zzao,wzao = 0;

ll f(ll a, ll b, ll c){
    ll resp = 0;
    resp += a*a*wzao - 2*xzao*a;
    resp += b*b*wzao - 2*yzao*b;
    resp += c*c*wzao - 2*zzao*c;
    return resp;
}

int main() {
    // fast_cin();
    ll n; cin >> n;
    ll x,y,z,w;
    double av, bv, cv;

    forn(i,0,n){
        cin >> x >> y >> z >> w;
        xzao += w*x;
        yzao += w*y;
        zzao += w*z;
        wzao += w;
    }

    av = (double)xzao/wzao;
    bv = (double)yzao/wzao;
    cv = (double)zzao/wzao;

    ll mini = 2e18;
    ll ma, mb, mc;
    for (ll c = (ll)(ceil(cv) + 0.5); c >= (ll)(floor(cv) + 0.5); c--) {
        for (ll b = (ll)(ceil(bv) + 0.5); b >= (ll)(floor(bv) + 0.5); b--) {
            for (ll a = (ll)(ceil(av) + 0.5); a >= (ll)(floor(av) + 0.5); a--) {
                if (f(a,b,c) <= mini) {
                    mini = f(a,b,c);
                    ma = a;
                    mb = b;
                    mc = c;
                }
            }
        }
    }

    cout << ma << " " << mb << " " << mc << ln;    
}