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

void dfs(ll x, vector<set<ll>>& adj, vector<bool>& visited, v64& parent, set<ll>& leafs) {
    visited[x] = true;
    ll children = 0;
    for (auto e : adj[x]) {
        if (visited[e]) continue;
        children++;
        parent[e] = x;
        dfs(e, adj, visited, parent, leafs);
    }
    if (!children) leafs.insert(x);
}


int main(){
    F_;
    ll n; cin >> n;
    vector<set<ll>> adj(n, set<ll>());
    vector<bool> visited(n);
    vector<ll> parent(n);
    set<ll> leafs;
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    dfs(0, adj, visited, parent, leafs);
    
    forn(i, 0, n) {
        adj[i].erase(parent[i]);
    }

    ll ops = 0;
    while(!leafs.empty()) {
        auto f = *leafs.begin();
        leafs.erase(f);

        if (parent[f] == f) {
            ops += 2;
            break;
        }

        if (adj[parent[f]].size() >= 2) {
            ops += 2;
            adj[parent[f]].erase(f);

            if (adj[parent[f]].size() == 0) {
                leafs.insert(parent[f]);
            }
        } else {
            ll avo = parent[parent[f]];
            
            if (avo == parent[f]) {
                ops += 1;
                break;
            } else {
                adj[avo].erase(parent[f]);
                ops++;
                if (adj[avo].size() == 0) {
                    leafs.insert(avo);
                }
            }
        }
    }

    cout << ops << ln;
    
    P_; return 0;
}