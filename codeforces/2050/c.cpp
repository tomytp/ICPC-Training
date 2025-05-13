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

void solve() {
    string s; cin >> s;
    map<ll, ll> mp;
    ll sum = 0;
    forn(i, 0, s.size()) {
        mp[s[i]-'0']++;
        sum += s[i] - '0';
    }

    if (sum % 9 == 0) {
        cout << "YES" << ln;
        return;
    }

    ll extra = sum % 9;

    vector<bool> v(200);
    v[0] = true;
    forn(i, 0, mp[2]) {
        for (ll j = 190; j >= 0; j--) {
            if (v[j]) v[j+2] = true;
        }
    }
    forn(i, 0, mp[3]) {
        for (ll j = 190; j >= 0; j--) {
            if (v[j]) v[j+6] = true;
        }
    }
    forn(i, 1, 15) {
        if (v[9*i - extra]) {
            cout << "YES" << ln;
            return;
        }
    }
    cout << "NO" << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}