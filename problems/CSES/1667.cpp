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

#define INF 1'000'000'000'000

vector<vp64> adj;

void dijkstra(int s, v64& d, v64& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> visited(n, false);

    d[s] = 0;
    forn(i, 0, n) {
        ll u = -1;
        forn(j, 0, n) {
            if (!visited[j] && (u == -1 || d[j] < d[u])) u = j;
        }

        if (d[u] == INF) break;

        visited[u] = true;
        for (auto edge : adj[u]) {
            ll v = edge.first;
            ll w_v = edge.second;

            if (d[u] + w_v < d[v]) {
                d[v] = d[u] + w_v;
                p[v] = u;
            }
        }
    }
}

int main(){
    F_;
    ll n, m; cin >> n >> m;
    adj.resize(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].emplace_back(b, 1);
        adj[b].emplace_back(a, 1);
    }

    v64 d(n);
    v64 p(n);
    dijkstra(0, d, p);

    if (d[n-1] == INF) {
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }

    stack<ll> path;
    ll curr = n-1;
    path.push(n);
    while (curr != 0) {
        path.push(p[curr] + 1);
        curr = p[curr];
    }

    cout << path.size() << ln;
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << ln;

    P_; return 0;
}