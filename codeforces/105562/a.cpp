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
    vector<string> v(n);
    getline(cin, v[0]);
    forn(i, 0, n) {
        getline(cin, v[i]);
        // cout << v[i] << ln;
    }

    vector<pair<string, string>> v2;
    forn(i, 0, n) {
        forn(j, 0, v[i].size()) {
            if (v[i][j] >= 'A' && v[i][j] <= 'Z') {
                v2.push_back({v[i].substr(j, v[i].size() - j), v[i]});
                break;
            }
        }
    }
    sort(v2.begin(), v2.end());
    forn(i, 0, n) {
        cout << v2[i].second << ln;
    }
    
    return 0;
}