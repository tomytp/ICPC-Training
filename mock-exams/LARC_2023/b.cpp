#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg

int main() {
    FAST_CIN;
    ll n; cin >> n;
    map<ll,ll> mp;

    forn(i,0,(3*n)){
        ll aux; cin >> aux;
        mp[aux]++;
    }
    for(auto p : mp) {
        if (p.second % 3 != 0) {
            cout << "Y" << ln;
            return 0;
        }
    }
    cout << "N" << ln;
}