#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define forn(i, s, e) for(ll i = s; i < e, i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg

const ll mod = 1'000'000'007;
#define MAXN 50
ll bit[MAXN];

void add(ll p, ll v) {
    for (; p<MAXN; p+=p&-p) bit[p] = ((bit[p]% mod) + (v% mod)) % mod;
}

ll query(ll p) {
    ll r = 0;
    for (; p; p-=p&-p) r = ((r% mod) + (bit[p]% mod)) % mod;
    return r;
}

ll query(ll a, ll b) {
    return query(b) - query(a-1);
}

ll count_inv(string s){
    ll resp = 0;
    for(ll i = s.size() - 1; i >= 0; i--) {
        ll v = (s[i] - 'a') + 1;
        add(v, 1);
        resp = ((resp% mod) + (query(v - 1)% mod)) % mod;
    }
    return resp;
}

int main() {
    FAST_CIN;
    string s;
    cin >> s;
    ll n; cin >> n;
    ll inv2 = 500'000'004;
    n = n%mod;
    ll a = count_inv(s)%mod;
    memset(bit, 0, MAXN*sizeof(ll));
    string ss = s+s;
    ll b = count_inv(ss)%mod;
    ll aux2 = (2*(a% mod))%mod;
    b = ((b% mod)-(aux2% mod))%mod;
    ll resp = ((a% mod)*(n% mod))%mod;
    ll aux = ((n% mod)*(n% mod))%mod;
    aux = ((aux% mod)-(n% mod))%mod;
    aux = ((aux% mod)*(inv2% mod))%mod;
    aux = ((aux% mod)*(b% mod))%mod;
    resp = ((resp% mod)+(aux% mod))%mod;
    cout << resp << ln;
}