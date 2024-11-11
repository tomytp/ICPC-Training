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
v64 parent;
v64 path;
ll start = -1;
ll fin = -1;
 
void dfs(ll i) {
    dbg(i);
    visited[i] = true;
 
    for (auto v : adj[i]) {
        if(start != -1) return;
        if (v == parent[i]) continue;
        if (visited[v]) {
            start = i;
            fin = v;
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
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    forn(i, 0, n) {
        parent[i] = i;
    }
 
    forn(i, 0, n) {
        if (visited[i]) continue;
        dfs(i);
        if (start != -1) break;
    }
 
    // for (auto& v : parent) {
    //     cout << v + 1<< " ";
    // }
    // cout << ln;
    // return 0;
    dbg(start);
    if (start == -1) {
        cout << "IMPOSSIBLE" << ln;
    } else {
        ll aux = start;     
        path.push_back(fin);        
        while (aux != fin) {
            path.push_back(aux);
            aux = parent[aux];
        }
        path.push_back(fin);
 
        cout << path.size() << ln;
        for (auto p : path) {
            cout << p+1 << " ";
        }
        cout << ln;
    }
 
 
    P; return 0;
} 