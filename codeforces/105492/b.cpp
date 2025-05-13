#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct vertex {
    ll north, south, east, west;
};

struct node {
    ll idx, dir, active, used, dist;
};

int main(){
    _;
    ll n, k; cin >> n >> k;
    vector<vector<ll>> v(n, vector<ll>(4));
    vector<vector<vector<vector<ll>>>> visited(n, vector<vector<vector<ll>>>(4, vector<vector<ll>>(k, vector<ll>(3))));
    forn(i, 0, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        v[i][0]--; v[i][1]--; v[i][2]--; v[i][3]--;
    }

    if (n == 1) {
        cout << 0 << ln;
        return 0;
    }

    queue<node> q;
    q.emplace(0, 0, 0, 0, 0);
    q.emplace(0, 1, 0, 0, 0);
    q.emplace(0, 2, 0, 0, 0);
    q.emplace(0, 3, 0, 0, 0);

    while(!q.empty()) {
        node u = q.front(); q.pop();
        forn(i, 0, 4) {
            if (v[u.idx][i] == -1) continue;
            
        }
        
    }
    

    return 0;
}