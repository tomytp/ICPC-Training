#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define MOD 1000000007L


struct treap {
    char val;
    bool reverse;
    ll prio, size;
    vector<treap*> kids;
    treap(char c) : val(c), prio(rand()), size(1), kids({NULL, NULL}) {}
};

int size(treap *t) { 
    return t ? t->size : 0; 
}

void recalc(treap *t) {
    if (!t) return;
    if (!t->reverse) return;
    t->reverse = false;
    swap(t->kids[0], t->kids[1]);
    if (t->kids[0])
        t->kids[0]->reverse = !t->kids[0]->reverse;
    if (t->kids[1])
        t->kids[1]->reverse = !t->kids[1]->reverse;
}

vector<treap*> split(treap *t, ll idx) {
	if (!t) return {NULL, NULL};
    vector<treap*> out;
    recalc(t);

	if (size(t->kids[0]) < idx) {
		out = split(t->kids[1], idx - size(t->kids[0]) - 1);
        t->kids[1] = out[0];
        out = {t, out[1]};

	} else {
        out = split(t->kids[0], idx);
        t->kids[0] = out[1];
        out = {out[0], t};
	}

    t-> size = 1 + size(t->kids[0]) + size(t->kids[1]);
    return out;

}

void print_treap(treap *t) {
    if (!t) return;
    recalc(t);
    print_treap(t->kids[0]);
    cout << t->val;
    print_treap(t->kids[1]);
}

treap* merge(treap* left, treap* right) {
    treap *out;
    if (left == NULL) return right;
	if (right == NULL) return left;
    recalc(left);
    recalc(right);

    if (left->prio < right->prio) {
        left->kids[1] = merge(left->kids[1], right);
		out = left;
	} else {
		right->kids[0] = merge(left, right->kids[0]);
		out = right;
	}

	out->size = 1 + size(out->kids[0]) + size(out->kids[1]);
    return out;
}

treap* reverse(treap *t, ll a, ll b) {
    vector<treap*> r2 = split(t, b);
    vector<treap*> r1 = split(r2[0], a - 1);
    vector<treap*> r = {r1[0], r1[1], r2[1]};

    r[1]->reverse = !r[1]->reverse;
    recalc(r[1]);

    
    treap *f = merge(r[0], r[1]);
    f = merge(f, r[2]);

    return f; 
}


int main() {
    F_;
    ll n; cin >> n;
    ll m; cin >> m;
    string s; cin >> s;
    treap *t = NULL;

    for (auto c : s) {
        treap *aux = new treap(c);
        t = merge(t, aux);
    }

    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        t = reverse(t, a, b);
    }
    print_treap(t);
    cout << ln;


    P_;
}