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

#define MAXN 1000005

ll parent[MAXN]; //Inicializa parent[i] = i
ll sz[MAXN];

ll find(ll x){
    ll pai = x;
    ll filho = x;
    ll aux;
    while( pai != parent[pai] ) pai = parent[pai];
    while( filho != parent[filho] ) {
        aux = parent[filho];
        parent[filho] = pai;
        filho = aux;
    }
    return pai;
}
void uni(ll x, ll y){
    ll rx = find(x);
    ll ry = find(y);
    if(rx == ry) return;
    if( sz[rx] < sz[ry]) swap(rx,ry);
    parent[ry] = rx;
    sz[rx] += sz[ry]; 
    return;
}

v64 offx = {1, 0};
v64 offy = {0, 1};

int main(){
    F_;
    ll n, m; cin >> n >> m;

    forn(i, 0, n*m) {
        parent[i] = i;
    }

    vector<vector<char>> v(n, vector<char>(m));

    set<ll> open_cells;

    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> v[i][j];
        }
    }

    forn(i, 0, n) {
        forn(j, 0, m) {
            if (v[i][j] == '.') {
                open_cells.insert(i*m + j);
                forn(k, 0, 2) {
                    if (i+offx[k] < n && i+offx[k] >= 0 && j+offy[k] < m && j+offy[k] >=0 && v[i+offx[k]][j+offy[k]] == '.') {
                        uni(i*m + j, (i+offx[k])*m + (j+offy[k]));
                    }
                }
            }
        }
    }
    set<ll> rooms;
    for (auto e : open_cells) {
        rooms.insert(find(e));
    }
    cout << rooms.size() << ln;

    P_; return 0;
}