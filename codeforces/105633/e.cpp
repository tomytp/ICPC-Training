#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
vector<string> g;
vector<p64> vis = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
ll n, m; 

ll dfs(p64 u, p64 parent) {
    ll number_rep = g[u.first][u.second] - '0';
    if (number_rep >= 0 && number_rep <= 9) return number_rep;
    vector<p64> children;

    for (auto p : vis) {
        p.first += u.first;
        p.second += u.second;
        if (p == parent || p.first >= n || p.first < 0 || p.second < 0 || p.second >= m) continue;
        if (g[p.first][p.second] != '.') children.push_back(p);
    }

    if (g[u.first][u.second] == 'P' || g[u.first][u.second] == '#') {
        assert(children.size() == 1);
        return dfs(children[0], u);
    }
    assert(children.size() == 2);
    ll a = dfs(children[0], u);
    ll b = dfs(children[1], u);
    if (g[u.first][u.second] == '+') {
        return a + b;
    }
    if (g[u.first][u.second] == '-') {
        return abs(a - b);
    }
    if (g[u.first][u.second] == '*') {
        return a * b;
    }
    if (g[u.first][u.second] == '/') {
        if (b > a) swap(a, b);
        return a / b;
    }
    assert(false);
}

int main(){
    _;
    cin >> n >> m;
    g.resize(n);
    forn(i, 0, n) {
        cin >> g[i];
    }

    ll px, py;
    forn(i, 0, n) {
        forn(j, 0, m) {
            if (g[i][j] == 'P') px = i, py = j;
        }
    }

    cout << dfs({px, py}, {-1, -1}) << ln;
    return 0;
}