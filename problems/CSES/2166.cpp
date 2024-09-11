#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;
typedef vector<p64> vp64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007L
#define dbg(x) cout << #x << " = " << x << ln


#define LC 2*nd+1
#define RC 2*nd+2
#define REC ll nd = 0, ll L = 0,  ll R = -1

typedef struct pt {
    ll sum, max_pref;
    pt operator + (const pt &p) const { return {sum+p.sum, max(max_pref, sum + p.max_pref)}; }
} PT;

template <typename T>
struct SegTree {
    vector<T> tree;
    ll n;

    T op(T a, T b) {
        return a + b;
    }

    void _build(vector<T>& v, ll nd, ll st, ll ed) {
        if (st == ed){
            tree[nd] = v[st];
        } else {
            ll mid = (st + ed) / 2;
            _build(v, LC, st, mid);
            _build(v, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }

    void _update(ll idx, T val, ll nd, ll st, ll ed) {
        if (st == ed) tree[nd] = val;
        else {
            ll mid = (st + ed) / 2;
            if (idx <= mid) _update(idx, val, LC, st, mid);
            else _update(idx, val, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }

    T _query(ll l, ll r, ll nd, ll st, ll ed) {
        if (r < st || ed < l) return PT{0, 0}; // REPLACE BY NEUTRAL
        if (l <= st && ed <= r) return tree[nd];
        ll mid = (st + ed) / 2;
        T left = _query(l, r, LC, st, mid);
        T right = _query(l, r, RC, mid+1, ed);
        return op(left, right);
    }

    SegTree(vector<T>& v) : n(sz(v)) {
        tree.resize(4 * n);
        _build(v, 0, 0, n-1);
    }

    void update(ll idx, T val) {
        _update(idx, val, 0, 0, n-1);
    }

    T query(ll l, ll r) {
        return _query(l, r, 0, 0, n-1);
    }
};


int main() {
    FAST_CIN;
    ll n; cin >> n;
    ll q; cin >> q;

    vector<PT> vec(n+1);
    forn(i, 1, n+1) {
        ll aux; cin >> aux;
        vec[i] = {aux, aux};
    }

    SegTree<PT> seg(vec);
    
    forn(i, 0, q) {
        ll t; cin >> t;
        if (t == 1) {
            ll k, u; cin >> k >> u;
            seg.update(k, PT{u,u});
        } else {
            ll a, b; cin >> a >> b;
            cout << seg.query(a, b).max_pref << ln;
        }
    }
}