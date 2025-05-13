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

ll calc(ll l, ll r, v64& pre, v64& pos) {
    ll mid = l + (r-l) / 2;
    ll mida = mid + pos[mid];
    ll midb = mid - pre[mid];
    ll ansa = max(mida - l, r-1 - mida);
    ll ansb = max(midb - l, r-1 - midb);
    return min(ansa, ansb);
}

int main(){
    _;
    ll n, k; cin >> n >> k; k++;
    string s; cin >> s;
    v64 pre(n), pos(n);
    if (s[0] == '1') pre[0] = 1;
    forn(i, 1, n) {
        if (s[i] == '0') pre[i] = 0;
        else pre[i] = 1 + pre[i-1];
    }
    if (s[n-1] == '1') pre[n-1] = 0;
    for(ll i = n-2; i >= 0; i--) {
        if (s[i] == '0') pos[i] = 0;
        else pos[i] = 1 + pos[i+1];
    }

    ll ans = INF;
    ll curr = 0;
    ll l = 0, r = 0;
    while(l < n && r <= n) {
        if (curr < k) {
            if (s[r++] == '0') curr++;
            debug(curr);
            continue;
        }
        
        if (curr > k) {
            if (s[l++] == '0') curr--;
            debug(curr);
            continue;
        }

        ans = min(ans, calc(l, r, pre, pos));
        if (s[r++] == '0') curr++;
    }

    cout << ans << ln;
    return 0;
}