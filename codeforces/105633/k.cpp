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

vector<bool> exists(1048576+1);
vector<ll> dp(1048576+1, -1);
vector<ll> pos(1048576+1, -1);
vector<bool> fila(1048576+1);
array<ll, 1048576+1> q;

vector<ll> filhos = {
    0b11111111111111111110,
    0b11111111111111111101,
    0b11111111111111111011,
    0b11111111111111110111,
    0b11111111111111101111,
    0b11111111111111011111,
    0b11111111111110111111,
    0b11111111111101111111,
    0b11111111111011111111,
    0b11111111110111111111,
    0b11111111101111111111,
    0b11111111011111111111,
    0b11111110111111111111,
    0b11111101111111111111,
    0b11111011111111111111,
    0b11110111111111111111,
    0b11101111111111111111,
    0b11011111111111111111,
    0b10111111111111111111,
    0b01111111111111111111,
};

ll mask;

void precalc() {
    ll idx = 0;
    ll qend = 0;
    q[qend++] = mask;

    while(q[idx] != 0) {
        ll u = q[idx];
        for (auto f : filhos) {
            f &= u;
            if (!fila[f]) {
                fila[f] = true;
                q[qend++] = (f);
            }
        }
        idx++;
        
        ll ans = 0;
        if (exists[u]) ans = u;
        forn (i, 0, 20) {
            ll parent = u | (1 << i);
            if (dp[parent] == -1) continue;
            ll p_pai = __builtin_popcountll(dp[parent]);
            ll p_curr = __builtin_popcountll(ans);
            if (p_pai == p_curr && pos[dp[parent]] < pos[ans]) ans = dp[parent];
            else if (p_pai > p_curr) ans = dp[parent];
        }

        dp[u] = ans;
        if (!ans) dp[u] = -1;
        if(dp[u] != -1){
            debug(bitset<10>(u));
            debug(bitset<10>(dp[u]));
            debug(1);
        }
    }
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    mask = (1<<m) -1;
    vector<ll> v;
    ll found = -1;
    forn(i, 0, n) {
        ll curr = 0;
        forn(j, 0, m) {
            char aux; cin >> aux;
            curr <<= 1;
            if (aux == 'Y'){
                curr |= 1;
            } 
        }
        if (curr == mask && found == -1) found = i;
        exists[curr] = true;
        if (pos[curr] == -1) pos[curr] = i;
        v.push_back(curr);
    }

    if (found != -1) {
        ll a = 0;
        ll ia = -1;
        forn(i, 0, n) {
            if (i == found) continue;
            if (__builtin_popcountll(v[i]) > __builtin_popcountll(a)) {
                a = v[i];
                ia = i;
            }
        }
        if (ia > found) swap(ia, found);
        cout << ia+1 << " " << found+1 << ln;
        return 0;
    }

    precalc();

    debug((bitset<20>(mask)));
    ll a = 0, b = 0, curr = -1;
    forn(i, 0, n) {
        ll val = v[i];
        ll max_inv = dp[(~v[i]) & mask];
        if (max_inv == -1) continue;
        ll pop = __builtin_popcountll(val & max_inv);
        if (pop > curr) {
            a = val;
            b = max_inv;
            curr = pop;
        }
    }


    // cout << a << ln << b  << ln << curr << ln;
    ll idx_a = -1;
    ll idx_b = -1;

    forn(i,0,n){
        if(v[i] == a && idx_a == -1) idx_a = i;
        if(v[i] == b && idx_b == -1) idx_b = i;
    }
    if(curr == -1){
        cout << "No" << ln;
        return 0;
    }
    if(idx_b < idx_a) swap(idx_a, idx_b);
    
    cout << idx_a+1 << ' ' << idx_b+1 << ln;
    return 0;
}