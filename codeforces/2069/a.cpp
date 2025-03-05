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
const ll MAXN = 1005;
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

ll count_groups(v64& v) {
    ll ans = 0;
    if (v[0]) ans++;
    forn(i, 0, v.size()-1){
        if (!v[i] && v[i+1]) ans++;
    } 
    return ans;
}

void solve() {
    ll n; cin >> n;
    n-=2;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> b[i];
    forn(i, 0, n) {
        parent[i] = i;
        sz[i] = 1;
    }

    forn(i, 0, n) {
        if (b[i]) {
            if (i+1 < n) uni(i, i+1);
            if (i-1 >= 0) uni(i, i-1);
        }
    }
    set<ll> ans;
    forn(i, 0, n) if (b[i]) ans.insert(find(i));
    cout << (((ll) ans.size() == count_groups(b))? "YES" : "NO") << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}