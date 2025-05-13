#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

struct lane {
    char op;
    ll amount;

    ll calc(ll people) {
        if (op == '+') {
            return amount;
        } else {
            return people * (amount - 1);
        }
        assert(false);
    }
};

ll get_decision(p64 a, p64 b, ll i) {
    if (a.second < b.second) return 0;
    if (b.second < a.second) return 1;
    if (i < b.second) return 3;

    if (a.first > b.first) return 0;
    if (b.first > a.first) return 1;

    return 2;
}

void solve() {
    ll n; cin >> n;
    vector<pair<lane, lane>> v(n);
    vector<pair<p64, p64>> mult(n);
    forn(i, 0, n) {
        cin >> v[i].first.op >> v[i].first.amount;
        cin >> v[i].second.op >> v[i].second.amount;
    }
    p64 ma = {1, n}, mb = {1, n};
    for (ll i = n-1; i>= 0; i--) {
        if (v[i].first.op == 'x') ma = {v[i].first.amount, i};
        if (v[i].second.op == 'x') mb = {v[i].second.amount, i};
        mult[i] = {ma, mb};
    }

    ll a = 1, b = 1, q = 0;
    forn(i, 0, n-1) {
        ll new_people = v[i].first.calc(a) + v[i].second.calc(b) + q;
        q = 0;

        ll dec = get_decision(mult[i+1].first, mult[i+1].second, i+1);
        if (dec == 0) a += new_people;
        else if (dec == 1) b += new_people;
        else if (dec == 2) {
            q = new_people * mult[i+1].first.first;
            continue;
        } else if (dec == 3) {
            q = new_people;
            continue;
        }
    }
    a += v[n-1].first.calc(a);
    b += v[n-1].second.calc(b);
    cout << a + b + q << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}