
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D true
#define F if(!D)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P if(D)cout<<"DEBUG\n"
#define dbg(x) if(D) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

vv64 adj;
vector<bool> visited;
vector<bool> visited2;
v64 parent;
v64 path;
ll start = -1;
ll fim = -1;

void dfs(ll i) {
    dbg(i);
    visited[i] = true;
    visited2[i] = true;

    for (auto v : adj[i]) {
        if(start != -1) return;
        if (visited2[v]) {
            start = i;
            fim = v;
            return;
        }
        parent[v] = i;
        dfs(v);
    }
}

int main(){
    F;
    ll n, m; cin >> n >> m;
    adj.resize(n);
    parent.resize(n);
    visited.resize(n);
    visited2.resize(n);

    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    forn(i, 0, n) {
        parent[i] = i;
    }

    forn(i, 0, n) {
        if (visited[i]) continue;
        visited2.assign(n, false);
        dfs(i);
        if (start != -1) break;
    }

    dbg(start);
    if (start == -1) {
        cout << "IMPOSSIBLE" << ln;
    } else {
        ll aux = start;     
        path.push_back(fim);     
        while (aux != fim) {
            path.push_back(aux);
            aux = parent[aux];
        }
        path.push_back(fim);

        reverse(path.begin(), path.end());
        cout << path.size() << ln;
        for (auto p : path) {
            cout << p+1 << " ";
        }
        cout << ln;
    }

    P; return 0;
} 