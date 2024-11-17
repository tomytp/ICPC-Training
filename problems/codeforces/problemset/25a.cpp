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
    ll n; cin >> n;
    ll le = 0, lo = 0, co = 0;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        if (aux & 1) {
            lo = i;
            co++;
        } else {
            le = i;
        }
    }

    if (co > 1) {
        cout << le+1 << ln;
    } else {
        cout << lo+1 << ln;
    }
    P_; return 0;
}