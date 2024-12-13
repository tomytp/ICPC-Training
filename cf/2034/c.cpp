#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

ll n, m; 

void dfs(ll i, ll j, const vector<vector<char>>& g, vector<vector<bool>>& visited) {
    vector<tuple<ll,ll,char>> dirs = {{0, 1, 'L'}, {0, -1, 'R'}, {1, 0, 'U'}, {-1, 0, 'D'}};
    visited[i][j] = true;

    for (auto& [x, y, c] : dirs) {
        ll il = i + x, jl = j+y;
        if (il >= n || il < 0 || jl >= m || jl < 0) continue;
        if (g[il][jl] == c && !visited[il][jl]) {
            dfs(il, jl, g, visited);
        }
    }
}

bool can_lock(ll i, ll j, const vector<vector<char>>& g, vector<vector<bool>>& visited) {
    vector<p64> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    if (g[i][j] != '?') {
        if (!visited[i][j]) return true;
        else return false;
    }

    for (auto& [x, y] : dirs) {
        ll il = i + x, jl = j+y;
        if (il >= n || il < 0 || jl >= m || jl < 0) continue;
        if (!visited[il][jl]) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    forn(i, 0, n) {
        forn(j, 0, m) cin >> g[i][j];
    }

    forn(j, 0, m) {
        if (!visited[0][j] && g[0][j] == 'U') {
            dfs(0, j, g, visited);
        }
        if (!visited[n-1][j] && g[n-1][j] == 'D') {
            dfs(n-1, j, g, visited);
        }
           
    }
    forn(i, 0, n) {
        if (!visited[i][0] && g[i][0] == 'L') {
            dfs(i, 0, g, visited);
        }
        if (!visited[i][m-1] && g[i][m-1] == 'R') {
            dfs(i, m-1, g, visited);
        }
    }
    ll ans = 0;
    forn(i, 0, n) {
        forn (j, 0, m) {
            if (can_lock(i, j, g, visited)) ans++;
        }
    }
    cout << ans << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}