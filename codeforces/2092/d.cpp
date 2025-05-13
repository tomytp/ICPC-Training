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

void nx(v64& v, v64& count, v64& ans) {
    vector<p64> cts;
    forn(i, 0, 3) {
        cts.emplace_back(count[i], i);
    }
    sort(cts.begin(), cts.end());

    forn(k, 0, 3) {
        forn(i, 0, v.size()-1) {
            if (v[i] != v[i+1] && v[i] != cts[k].second && v[i+1] != cts[k].second) {
                ans.push_back(i+1);
                v.insert(v.begin() + i+1, cts[k].second);
                count[cts[k].second]++;
                return;
            }
        }
    }

}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    v64 v;
    v64 count = {0, 0, 0};
    forn(i, 0, n) {
        if (s[i] == 'T') v.push_back(0);
        if (s[i] == 'I') v.push_back(1);
        if (s[i] == 'L') v.push_back(2);
        count[v[i]]++;
    }
    ll op = 0;
    v64 ans;

    while (op++ < 2*n) {
        if ((count[0] == count[1]) && (count[1] == count[2])) {
            cout << ans.size() << ln;
            forn(i, 0, ans.size()) cout << ans[i] << ln;
            return;
        }
        nx(v, count, ans);
    };

    if ((count[0] == count[1]) && (count[1] == count[2])) {
        cout << ans.size() << ln;
        forn(i, 0, ans.size()) cout << ans[i] << ln;
        return;
    }
    cout << -1 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}