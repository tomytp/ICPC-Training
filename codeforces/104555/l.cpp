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
    string s; cin >> s;
    ll n = s.size();
    ll k; cin >> k;
    vector<string> v(n);
    forn(i, 0, k) {
        ll j = i;
        while (j < n) {
            v[i].push_back(s[j]);
            j += k;
        }
    }
    forn(i, 0, k) {
        sort(v[i].begin(), v[i].end());
        ll j = 0;
        while (j < v[i].size()) {
            s[i + (k*j)] = v[i][j];
            j++;
        }
    }

    cout << s << ln;
    

    return 0;
}