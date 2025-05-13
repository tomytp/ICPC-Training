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
    vector<p64> v(n);
    v64 p(m);
    v64 c_tot(m);
    vector<v64> ans(m);
    forn(i, 0, n) cin >> v[i].first, v[i].second = i;
    forn(i, 0, m) cin >> p[i];

    sort(v.rbegin(), v.rend());

    forn(i, 0, n) {
        ll m_idx = 0;
        double m_val = 0;
        forn(j, 0, m) {
            if (p[j]* (double)v[i].first / (v[i].first + c_tot[j]) > m_val) {
                m_val = p[j] * (double)v[i].first / (v[i].first + c_tot[j]);
                m_idx = j;
            }
        }

        ans[m_idx].push_back(v[i].second);
        c_tot[m_idx] += v[i].first;
    }
    forn(i, 0, m) {
        cout << ans[i].size() << " ";
        forn(j, 0, ans[i].size()) cout << ans[i][j] + 1 << " ";
        cout << ln;
    }

    return 0;
}