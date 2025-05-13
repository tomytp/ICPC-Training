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

vector<p64> solve() {
    ll n; cin >> n;
    v64 v(n);
    ll sum = 0;
    ll zeros = 0;
    forn(i, 0, n) {
        cin >> v[i];
        sum += v[i];
        if (!v[i]) zeros++;

    }

    vector<p64> ans;
    if (!zeros) {
        ans.emplace_back(1, n);
        return ans;
    }

    if (sum == 0) {
        ans.emplace_back(3, n);
        ans.emplace_back(1, 2);
        ans.emplace_back(1, 2);
        return ans;
    }

    if (v[0]) {
        ans.emplace_back(2, n);
        ans.emplace_back(1, 2);
        return ans;
    }
    if (v[n-1]) {
        ans.emplace_back(1, n-1);
        ans.emplace_back(1, 2);
        return ans;
    }

    ll idx = -1;
    forn(i, 0, n) {
        if (v[i]) {
            idx = i+1;
            break;
        }
    }

    if (idx == 2) {
        ans.emplace_back(3, n);
        ans.emplace_back(1, 2);
        ans.emplace_back(1, 2);
        return ans;
    } else {
        ans.emplace_back(idx, n);
        ans.emplace_back(1, idx-1);
        ans.emplace_back(1, 2);
        return ans;
    }

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) {
        auto ans = solve();
        cout << ans.size() << ln;
        forn(i, 0, ans.size()) {
            cout << ans[i].first << " " << ans[i].second << ln;
        }
    }
    return 0;
}