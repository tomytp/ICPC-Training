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
const ll MOD = 1'000'000'007;

ll mult(ll a, ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}

ll sum(ll a, ll b){
    return ((a%MOD)+(b%MOD))%MOD;
}

ll sub(ll a, ll b){
    return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

ll pot(ll a, ll b){
    ll expo=1, prod=a;
    b = b % (MOD-1);
    a = a % MOD;

    while(b>=1){
        if(b%2 == 1) expo = mult(expo,prod);
        prod = mult(prod,prod);
        b = b/2;
    }
    
    return expo;
}

ll inv_mod(ll a){
    return pot(a, MOD-2);
}

ll convert(string s){
    s = s.substr(2,s.size()-2);
    ll sz = s.size();

    ll inv_10 = inv_mod(10);
    ll pot_10 = inv_10;
    ll resp = 0;

    forn(i,0,sz){
        resp = sum(resp, mult((s[i]-'0'),pot_10));
        pot_10 = mult(inv_10, pot_10);
    }
    return resp;
}

template<typename T>
struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;
    T val;

    static constexpr T neutral = 0; // Customize this for min/max/gcd/etc.

    node(ll l_, ll r_, const vector<T>& v) : lm(l_), rm(r_) {
        if (lm == rm) {
            val = v[lm];
        } else {
            ll m = (lm + rm) / 2;
            lc = make_unique<node>(lm, m, v);
            rc = make_unique<node>(m + 1, rm, v);
            pull();
        }
    }

    static T comb(const T& a, const T& b) {
        return sum(a, b); // Change to min/max/gcd as needed
    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    void point_add(ll idx, T x) {
        if (lm == rm) {
            val = sum(val, x);
            return;
        }
        if (idx <= lc->rm) lc->point_add(idx, x);
        else rc->point_add(idx, x);
        pull();
    }

    void point_sub(ll idx, T x) {
        if (lm == rm) {
            val = sub(val, x);
            return;
        }
        if (idx <= lc->rm) lc->point_sub(idx, x);
        else rc->point_sub(idx, x);
        pull();
    }

    T query(ll lq, ll rq) {
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }
};

int main(){
    _;
    ll n; ll num_q;
    cin >> n >> num_q;
    string s; cin >> s;
    ll p = convert(s);
    ll q = sub(1,p);

    ll inv_q = inv_mod(q);

    v64 pow_q(n+1,1);
    v64 pow_inv_q(n+1,1);

    v64 v_mais(n, 0);
    v64 v_menos(n, 0);

    forn(i,1,n+1){
        pow_q[i] = mult(pow_q[i-1], q);
        pow_inv_q[i] = mult(pow_inv_q[i-1], inv_q);
    }

    node seg_mais(0,n-1, v_mais);
    node seg_menos(0,n-1, v_menos);

    forn(i,0,num_q){
        char c; cin >> c;
        if(c == '+'){
            ll b, x; cin >> b >> x;
            x--;
            seg_mais.point_add( x, mult(b, pow_q[x]));
            seg_menos.point_add(x, mult(b, pow_inv_q[x]));
            continue;
        }
        if(c == '-'){
            ll b, x; cin >> b >> x;
            x--;
            seg_mais.point_sub( x, mult(b, pow_q[x]));
            seg_menos.point_sub(x, mult(b, pow_inv_q[x]));
            continue;
        }
        ll x; cin >> x;
        x--;
        ll resp = 0;

        ll left = seg_menos.query(0,x);
        ll right = seg_mais.query(x+1,n-1);
        
        debug(left);
        debug(right);

        resp = sum(mult(pow_q[x], left), mult(pow_inv_q[x], right));
        
        cout << resp << ln;
    }
    
    return 0;
}