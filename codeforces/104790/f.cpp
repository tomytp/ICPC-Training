#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;
    ll n; cin >> n;
    ll c; cin >> c;
    
    v64 vec(n);

    forn(i,0,n) cin >> vec[i];
    
    map<ll, ll> mp, out;
    forn(i, 0, n) {
        mp[i] = vec[i];
        ll curr = 0;
        while(!mp.empty() && curr < c) {
            ll to_go = min((c - curr), mp.begin()->second);
            mp.begin()->second -= to_go;
            curr += to_go;
            if (mp.begin()->second == 0) {
                if (curr < c) {
                    out[mp.begin()->first] = i;
                } else {
                    out[mp.begin()->first] = i+1;
                }
                mp.erase(mp.begin());
            }
        }
    }

    ll MIN_EL = INF;
    ll id = 0;
    for (auto &[k, v] : out) {
        if (v-k < MIN_EL && v < n) {
            MIN_EL = v-k;
            id = k;
        }
    }

    if (MIN_EL == INF) {
        cout << "impossible" << ln;
    } else {
        cout << id << ln;
    }

    return 0;
}