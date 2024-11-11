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

ll parent[MAXN]; //Inicializar parent[i] = i
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

int main(){
    F_;
    ll n, m; cin >> n >> m;
    
    forn(i, 0, n) {
        parent[i] = i;
    }

    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        uni(a-1, b-1);
    }

    map<ll, ll> mp;

    forn(i, 0, n) {
        ll r = find(i);
        mp[r] = i;
    }

    cout << mp.size() - 1 << ln;

    auto it = mp.begin();
    while (it != mp.end()) {
        ll cur = it->second + 1;
        it++;
        if (it != mp.end()) {
            cout << cur << " " << it->second + 1 << ln;
        }
    }     

    P_; return 0;
}