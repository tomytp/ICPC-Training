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

const ll MAXN = 1000000;

ll n;
vector<v64> g(MAXN);
vector<map<string,ll>> vmp(MAXN);
v64 sum(MAXN);
v64 sub_sum(MAXN, 0);
ll min_dist = INF;

vector<string> read_path() {
    vector<string> ans;
    string s; cin >> s;
    forn(i, 0, s.size()) {
        if (s[i] == '/') {
            ans.push_back("");
        } else {
            ans.back().push_back(s[i]);
        }
    }

    return ans;
}

ll dfs(ll u, ll parent){
    ll curr_sum = sum[u];
    ll curr_dist = 0;

    for(ll v: g[u]){
        if(v == parent) continue;
        
        ll aux = dfs(v, u);

        curr_sum += sub_sum[v];
        curr_dist += aux + sub_sum[v];
    }

    sub_sum[u] = curr_sum;
    debug(u);
    debug(curr_dist);
    return curr_dist;
}

void dfs2(ll u, ll parent, ll u_dist){
    min_dist = min(u_dist, min_dist);
    debug(u);
    debug(u_dist);

    for(auto v : g[u]) {
        if (v == parent) continue;
        ll v_dist = u_dist + n - 2*sub_sum[v];
        dfs2(v, u, v_dist);
    }
}

int main(){
    _;
    cin >> n;
    ll c_ver = 1;
    forn(KKKK, 0, n) {
        auto path = read_path();
        ll curr = 0;
        forn(i, 0, path.size() - 1) {
            if (vmp[curr].count(path[i])) {
                curr = vmp[curr][path[i]];
            } else {
                g[curr].push_back(c_ver);
                vmp[curr][path[i]] = c_ver;
                curr = c_ver++;
            }
        }
        sum[curr]++;
    }

    ll curr_dist = dfs(0, -1);
    dfs2(0, -1, curr_dist);
    cout << min_dist + n << ln;
    return 0;
}