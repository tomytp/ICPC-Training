#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;
typedef vector<p64> vp64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 
#define dbg(x) cout << #x << " = " << x << ln

int main() {
    FAST_CIN;
    ll n; cin >> n;
    map<ll,ll> idx;
    v64 a(n), b(n), p(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        idx[a[i]], idx[b[i]];
    }

    int curr = 0;
    for (auto&v : idx) {
        v.second = curr++;
    }

    vector<vp64> project(curr);
    for (ll i = 0; i < n; i++) {
        project[idx[b[i]]].emplace_back(idx[a[i]], p[i]);
    }

    v64 dp(curr + 1, 0);
    dp[0] = 0;
    for (ll i = 1; i < curr + 1; i++) {
        dp[i] = dp[i-1];
        for (auto& p : project[i-1]) {
            dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }

    cout << dp[curr] << ln;
}