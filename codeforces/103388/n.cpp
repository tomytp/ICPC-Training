#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXX = 100100;
const ll neutral = 0;
#define comp(a, b) ((a) + (b))

//1-indexed
struct BIT {
    v64 ft;
    BIT(ll n) {
        ft.assign(n+1, 0);
    }

    ll rsq(ll i) {
        ll sum = neutral;
        for (;i; i-=(i&-i)) sum = comp(sum, ft[i]);
        return sum;
    }

    ll rsq(ll i, ll j) {
        return rsq(j) - rsq(i-1);
    }

    void add(ll i, ll v) {
        for(;i<(ll)ft.size(); i+= (i&-i)) ft[i] = comp(ft[i], v);
    }
};

struct PT {
    ll pos, qidx;
    char type;
    bool operator<(const PT& other) const {
        if (pos != other.pos) {
            return pos < other.pos;
        }
        if (qidx != other.qidx) {
            return qidx < other.qidx;
        }
        return type < other.type;
    }
};


int main(){
    _;
    ll n, q; cin >> n >> q;
    v64 v(n);
    forn(i, 0, n) {
        cin >> v[i];
        v[i]++;
    }
    v64 l(q), r(q), val(q);
    forn(i, 0, q){
        cin >> l[i] >> val[i] >> r[i];
        r[i]+= l[i];
        val[i]++;
    }

    v64 diff(q);
    BIT bit(MAXX);
    set<PT> fila;
    
    forn(i, 0, q) {
        PT pta, ptb;
        pta.pos = l[i] - 1;
        ptb.pos = r[i] - 1;
        pta.type = 'l';
        ptb.type = 'r';
        pta.qidx = i;
        ptb.qidx = i;
        fila.insert(pta);
        fila.insert(ptb);
        debug(fila.size());
    }

    forn(i, 0, n) {
        bit.add(v[i], 1);

        if (!fila.size()) continue;
        while (fila.size() && fila.begin()->pos == i) {
            PT first = *fila.begin();
            fila.erase(fila.begin());

            bool ganhou = val[first.qidx] <= v[l[first.qidx] - 1];
            if (ganhou) continue;

            ll rsq = bit.rsq(val[first.qidx], MAXX);

            if (first.type == 'l') diff[first.qidx] -= rsq;
            else diff[first.qidx] += rsq;
        }      
    }
    
    forn(i, 0, q) {
        cout << diff[i] << ln;
    }
    return 0;
} 