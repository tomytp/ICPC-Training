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
    map<ll, ll> mp;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        mp[aux]++;
    }
    v64 coins, val, sum(mp.size(), 0);
    coins.reserve(mp.size());
    val.reserve(mp.size());

    for (auto e : mp) {
        coins.push_back(e.first * e.second);
        val.push_back(e.first);
    }

    if (mp.size() == 1) {
        cout << mp.begin()->first * mp.begin()->second << ln;
        return 0;
    }

    sum[0] = coins[0];
    sum[1] = val[0] == val[1] - 1? max(coins[0], coins[1]) : coins[0] + coins[1];
    forn (i, 2, mp.size()) {
        if (val[i] == val[i-1] + 1) {
            sum[i] = max(sum[i-1], sum[i-2] + coins[i]);
        } else {
            sum[i] = sum[i-1] + coins[i];
        }
    }
    cout << sum[sum.size()- 1] << ln;
    P_; return 0;
}