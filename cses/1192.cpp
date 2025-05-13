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

vector<vector<bool>> visited;
vector<string> grid;

vector<p64> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(ll i, ll j) {
    visited[i][j] = true;

    for(auto& [x, y] : dirs) {
        ll ni = i+x;
        ll nj = j+y;
        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) continue;
        if (!visited[ni][nj] && grid[ni][nj] == '.') dfs(ni, nj);
    }    
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    visited.resize(n, vector<bool>(m));
    grid.resize(n);
    forn(i, 0, n) cin >> grid[i];

    ll ans = 0;
    forn(i, 0, n)
    forn(j, 0, m) {
        if (!visited[i][j] && grid[i][j] == '.') {
            dfs(i, j);
            ans++;
        }
    }

    cout << ans << ln;


    return 0;
}