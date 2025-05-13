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

ll n;
vector<v64> g;
v64 ans;
v64 likes;

ll bs(vector<v64>& pac, ll target) {
    ll l = 0, r = pac.size() - 1;
    ll ans2 = pac.size();

    while (l <= r) {
        ll mid = l + (r-l) / 2;

        if (pac[mid].back() >= target) {
            ans2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans2;
}

void dfs(ll u, ll parent, vector<v64>& pac) {
    ll pos = bs(pac, likes[u]);
    debug(u);
    debug(pos);
    if (pos == pac.size() || pac.size() == 0) {
        pos = pac.size();
        pac.push_back({likes[u]});
    } else {
        pac[pos].push_back(likes[u]);
    }

    // forn(i, 0, pac.size()) {
    //     forn(j, 0, pac[i].size()) {
    //         cout << pac[i][j] << " \n"[j == pac[i].size() - 1];
    //     }
    // }
    // cout << ln;
    ans[u] = pac.size();

    for (auto v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, pac);
    }

    if (pac[pos].size() == 1) {
        assert(pac.size() - 1 == pos);
        pac.pop_back();
    } else {
        pac[pos].pop_back();
    }
}

int main(){
    _;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    likes.resize(n);
    forn(i, 1, n) {
        ll aux; cin >> aux; aux--;
        g[i].push_back(aux);
        g[aux].push_back(i);
    }
    forn(i, 0, n) {
        cin >> likes[i];
    }


    vector<v64> pac;
    dfs(0, -1, pac);

    forn(i, 1, n) {
        cout << ans[i] << " \n"[i==n-1];
    }


    return 0;
}