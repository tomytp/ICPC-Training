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

v64 mp {0, 0, 0, 0, 0};

int main(){
    F_;
    ll n; cin >> n;
    ll aux;
    forn(i, 0, n) {
        cin >> aux; mp[aux]++;
    }
    ll total = 0;
    total += mp[4];

    dbg(total);

    aux = min(mp[3], mp[1]);
    mp[1] -= aux;
    total += mp[3];

    dbg(total);

    if (mp[2] & 1) {
        total += mp[2]/2 + 1;
        mp[1] -= min(mp[1], 2LL);
    } else {
        total += mp[2]/2;
    }

    dbg(total);

    if (mp[1] % 4 == 0) {
        total += mp[1] / 4;
    } else {
        total += mp[1] / 4;
        total++;
    }

    cout << total << ln;

    P_; return 0;
}