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
    ll n, m, d; cin >> n >> m >> d;
    vv64 v(n, v64(m));
    ll mini = 1000000000;
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> v[i][j];
            mini = min(mini, v[i][j]);
        }
    }
    map<ll, ll> mp;
    forn(i, 0, n) {
        forn(j, 0, m) {
            v[i][j] -= mini;
            mp[v[i][j]]++;
            if (v[i][j] && v[i][j] % d != 0) {
                cout << -1 << ln;
                return 0;
            }

        }
    }

    ll ans = 0;
    while (mp.size() > 1) {
        p64 front = *mp.begin();
        p64 back = *mp.rbegin();
        if (front.second < back.second) {
            auto front2 = ++mp.begin();
            ans += ((front2->first - front.first) / d) * front.second;
            front2->second += front.second;
            mp.erase(front.first);
        } else {
            auto back2 = ++mp.rbegin();
            ans += ((back.first - back2->first) / d) * back.second;
            back2->second += back.second;
            mp.erase(back.first);
        }
    }
    cout << ans << ln;

    P_; return 0;
}

//3 3 3

//5 8 5
//11 11 17
//14 5 2


//3 6 3
//9 9 15
//12 3 0