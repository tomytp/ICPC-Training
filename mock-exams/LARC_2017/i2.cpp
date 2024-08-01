#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<int, int> p32;
typedef vector<ll> v64;
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

#define MAXN 110001
#define LOG 21

int anc[LOG][MAXN], ancw[LOG][MAXN];
int h[MAXN];
v32 adj[MAXN], adjw[MAXN];
map<p32, int> mat;

int get_lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    for (int i = LOG - 1; i>=0; --i) {
        if (h[a] - (1<<i) >= h[b]) {
            a = anc[i][a];
        }
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

int get_max_edge(int a, int lca) {
    int max_edge = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        if (h[anc[i][a]] >= h[lca]) {
            max_edge = max(max_edge, ancw[i][a]);
            a = anc[i][a];
        }
    }
    return max_edge;
}

int main() {
    fast_cin();

    int n, r; cin >> n >> r;
    forn(i, r) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        adjw[a].pb(c);
        adjw[b].pb(c);
        mat[mp(a,b)] = c;        
        mat[mp(b,a)] = c;        
    }

    priority_queue<pair<p32,p32>> pq;
    bool visited[MAXN];
    set<p64> tree;
    pq.push(mp(mp(0, 0), mp(1, 1)));
    int minw = 0;

    while (!pq.empty()) {
        int a = pq.top().se.fi;
        int b = pq.top().se.se;
        int c = -pq.top().fi.fi;
        int he = pq.top().fi.se;
        pq.pop();
        if (visited[a]) continue;
        visited[a] = true;
        tree.insert(mp(a,b));
        tree.insert(mp(b,a));
        anc[0][a] = b;
        ancw[0][a] = c;
        h[a] = he;
        minw += c;

        forn(i, sz(adj[a])) {
            int v = adj[a][i];
            int w = adjw[a][i];
            if (!visited[v]) {
                pq.push(mp(mp(-w, he+1), mp(v, a)));
            }
        }
    }

    forsn(i, 1, LOG) {
        forsn(j, 1, n + 1) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            ancw[i][j] = max(ancw[i-1][anc[i-1][j]], ancw[i-1][j]);
        }
    }


    int q; cin >> q;
    forn(i, q) {
        int a, b; cin >> a >> b;
        if (tree.find(mp(a, b)) != tree.end()) {
            cout << minw << ln;
            continue;
        }
        int lca = get_lca(a, b);
        int max_edge = max(get_max_edge(a, lca), get_max_edge(b, lca));
        cout << minw - max_edge + mat[mp(a,b)] << ln;   
    }
}