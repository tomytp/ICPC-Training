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

#define MAXN 10001
ll vec[MAXN];
ll n;

map<p64, ll> dpp;

ll dp(ll suff, ll teleport) {
    if (dpp.find(mp(suff, teleport)) != dpp.end()) {
        return dpp[mp(suff, teleport)];
    }
    if (suff + 1  > n) {
        dpp[mp(suff, teleport)] = 0;
        return 0;
    }

    auto ans = min(abs(vec[suff+1]-vec[suff])+dp(suff+1, teleport),
               abs(teleport - vec[suff+1])+dp(suff+1, vec[suff]));
    dpp[mp(suff, teleport)] = ans;
    return ans;
}

int main() {
    fast_cin();
    cin >> n;
    vec[0] = 0;
    forn(i, 1, n + 1) {
        cin >> vec[i];
    }
    cout << dp(0,0) << ln;

}