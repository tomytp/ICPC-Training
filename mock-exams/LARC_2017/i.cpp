#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p64;
typedef vector<int> v64;
typedef vector<int> v32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())
#define dbg(x) cout << #x << " = " << x << ln

#define MAXN 100000
#define LOG 20

int ances[MAXN][LOG];
int ancesw[MAXN][LOG];
int h[MAXN];

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = LOG; i >= 0; --i) {
        if (h[u] - (1ll<<i) >= h[v]) {
            u = ances[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; --i) {
        if (ances[u][i] != ances[v][i]) {
            u = ances[u][i];
            v = ances[v][i];
        }
    }
    return ances[u][0];
} 

int maxbet(int u, int lca) {
    int maximo = 0;
    for (int i = LOG; i >= 0; --i) {
        if (h[ances[u][i]] >= h[lca]) {
            maximo = max(maximo, ancesw[u][i]);
            u = ances[u][i];
        }
    }
    return maximo;
}


int main(){
    fast_cin();
    int n, r; cin >> n >> r;
    v32 adj[MAXN], adjw[MAXN];
    map<p64, int> mat;
    forn(i, r) {
        int u, v, w; cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(v);
        adjw[u].push_back(w);
        adj[v].push_back(u);
        adjw[v].push_back(w);
        mat[mp(u, v)] = w;
        mat[mp(v, u)] = w;
    }

    priority_queue<pair<p64, p64>> pq;
    bool vis[MAXN];
    set<p64> arvore;
    pq.push(mp(mp(0,0), mp(0, 0)));
    int minw = 0;

    while (!pq.empty()) {
        auto uv = pq.top().se;
        auto wh = pq.top().fi;
        pq.pop();
        if (vis[uv.first]) continue;
        arvore.insert(uv);
        arvore.insert(mp(uv.se,uv.fi));
        ances[uv.fi][0] = uv.se;
        ancesw[uv.fi][0] = -wh.fi;
        vis[uv.first] = true;
        h[uv.first] = wh.se;
        minw -= wh.fi;

        forn(i, sz(adj[uv.fi])) {
            int v = adj[uv.fi][i];
            int w = adjw[uv.fi][i];
            if (!vis[v]) pq.push(mp(mp(-w, wh.se+1), mp(v, uv.fi)));
        }
    }

    forsn(i, 1, LOG) {
        forn(j, n) {
            ances[j][i] = ances[ances[j][i-1]][i-1];
            ancesw[j][i] = max(ancesw[ances[j][i-1]][i-1], ancesw[j][i-1]);
        }
    }  

    dbg(minw);
    int q; cin >> q;
    forn (i, q) {
        int a, b; cin >> a >> b;
        --a;
        --b;
        if( arvore.find(mp(a,b)) != arvore.end()){
            cout << minw << ln;
            continue;
        }
        int lcaa = lca(a, b);
        int totmax = max(maxbet(a, lcaa), maxbet(b, lcaa));
        dbg(totmax);
        dbg(mat[mp(a,b)]);
        cout << minw - totmax + mat[mp(a,b)] << ln;
    }

    // forn (i, n) {
    //     forn (j, n) {
    //         cout << adjw[i][j] << " ";
    //     }
    //     cout << ln;
    // }

    // forn(i, n) {
    //     cout << "H: " << h[i] << " P: " << ances[i][0] << " VO: " << ances[i][1] << " PP: " << ancesw[i][1] << ln;
    // }
}