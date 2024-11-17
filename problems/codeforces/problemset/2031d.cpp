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

#define N 500001

ll v[N];

ll parent[N];
ll sz[N];
ll top[N];
ll low[N];

ll find(ll x){
    ll pai = x;
    ll filho = x;
    ll aux;
    while(pai != parent[pai]) pai = parent[pai];
    while(filho != parent[filho]) {
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
    if(sz[rx] < sz[ry]) swap(rx,ry);
    parent[ry] = rx;
    sz[rx] += sz[ry]; 
    top[rx] = max(top[rx], top[ry]);
    low[rx] = min(low[rx], low[ry]);
    return;
}


void solve() {
    ll n; cin >> n;
    forn (i, 0, n){
        cin >> v[i];
        parent[i] = i;
        sz[i] = 1;
        top[i] = v[i];
        low[i] = v[i];
    }

    forn(_, 0, 20) {
        forn(i, 1, n) {
            ll f = find(i-1);
            ll fi = find(i);
            if (top[f] > low[fi]) {
                uni(f, i);
            }
        }
        forn(i, 0, n-1) {
            ll f = find(i+1);
            ll fi = find(i);
            if (top[fi] > low[f]) {
                uni(f, i);
            }
        }
    }


    forn(i, 0, n) {
        cout << top[find(i)] << " \n"[i == n-1];
    }
}

int main(){
    F_;
    ll t; cin >> t; 
    while (t--) solve();
    P_; return 0;
}