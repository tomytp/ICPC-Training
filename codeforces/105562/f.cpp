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

ll fill(ll l, ll c, v64& curr, v64& cap, v64& child) {
    if (l == -1) return -1;
    if (c == 0) return l;
    ll space = cap[l] - curr[l];
    if (space >= c) {
        curr[l] += c;
        return l;
    }
    if (space < c) {
        curr[l] += space;
        c -= space;
    }

    return child[l] = fill(child[l], c, curr, cap, child);
    
}

int main(){
    _;
    ll n, q; cin >> n >> q;
    v64 cap(n), curr(n), child(n, -1);
    forn(i, 0, n) cin >> cap[i];
    
    for (ll i = n-2; i >= 0; i--) {
        ll aux = i+1;
        while(aux != -1){
            if(cap[aux] > cap[i]) break;
            aux = child[aux];
        }
        child[i] = aux;
    }

    forn(i, 0, q) {
        char t; cin >> t;
        if (t == '?') {
            ll x; cin >> x;
            cout << curr[x-1] << ln;
        } else {
            ll l, c; cin >> l >> c;
            fill(l-1, c, curr, cap, child);
        }
    }

    return 0;
}