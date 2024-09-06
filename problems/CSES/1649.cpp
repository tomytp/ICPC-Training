#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007L

#define LC 2*node+1
#define RC 2*node+2
#define REC ll node = 0, ll L = 0,  ll R = -1

template <typename T>
struct segtree {
    T op (const T& a, const T& b) {
        return min(a, b);
    }
    int N;
    vector<T> tree;
    segtree(ll _N) : N(_N) {
        ll e = 64 - __builtin_clzl(N-1);
        if (N == 1) e = 0;
        N = 1 << e;
        tree.resize(1 << (e+1));
    }

    void setup(vector<T>& V, REC) {
        if(R == -1) R = N;
        if (L >= sz(V)) return;
        if (R - L == 1) {
            tree[node] = V[L];
            return;
        }
        ll m = (L + R) / 2;
        setup(V, LC, L, m);
        setup(V, RC, m, R);
        tree[node] = op(tree[LC], tree[RC]);
    }

    T update(ll i, const T& nv, REC) {
        if (R == -1) R = N;
        if (i < L || i >= R) return tree[node];
        if (R - L == 1) return tree[node] = nv;
        ll m = (L + R) / 2;
        return tree[node] = op(update(i, nv, LC, L, m), update(i, nv, RC, m ,R));  
    }
    
    T query(ll i, ll j) {
        return _query(i, j + 1);
    }

    T _query(ll i, ll j, REC) {
        if (R == -1) R = N;
        if (i <= L && R <= j) return tree[node];
        ll m = (L + R) / 2;
        if (i >= m) return _query(i, j, RC, m, R);
        else if (j <= m) return _query(i, j, LC, L, m);
        return op(_query(i, j, LC, L, m), _query(i, j, RC, m, R));
    }
};

int main() {
    ll n; cin >> n;
    ll q; cin >> q;

    v64 vec(n);
    forn(i, 0, n) cin >> vec[i];

    segtree<ll> seg(n);
    seg.setup(vec);

    forn (i, 0, q) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            seg.update(a -1, b);
        } else {
            cout << seg.query(a -1, b -1) << ln;
        }
    }
}