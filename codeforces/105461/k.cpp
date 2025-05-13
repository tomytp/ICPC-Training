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
    ll n, m; cin >> n >> m;

    vector<vector<ll>> g(n);
    vector<pair<ll,ll>> ord_grau;
    vector<ll> grau_efetivo(n);
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    forn(i, 0, n){
        ord_grau.push_back({g[i].size(),i});
        grau_efetivo[i] = g[i].size();
    }
    sort(ord_grau.begin(), ord_grau.end());

    // for(auto x : ord_grau) cout << x.second << " ";
    // cout << ln;

    ll vert = n;
    vector<bool> in_complete(n, false);
    for(auto x : ord_grau) {
        ll ind = x.second;
        if(grau_efetivo[ind] > vert-1){
            debug(ind);
            cout << "YES" << ln;
            return 0;
        }

        if (in_complete[ind]){
            vert--;
            continue;
        }

        for(auto y : g[ind]){
            in_complete[y] = true;
            grau_efetivo[y]--;
        }

        vert--;
    }

    cout << "NO" << ln;
    
    return 0;
}