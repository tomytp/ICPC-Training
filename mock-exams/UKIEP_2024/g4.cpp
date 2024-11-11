#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;
typedef vector<char> vc;
typedef vector<vc> vvc;


#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define MAXN 2005

struct Hasher {
    ll b1, b2, mod;
    ll power1[MAXN], power2[MAXN];
    Hasher(ll b1, ll b2, ll mod) : b1(b1), b2(b2), mod(mod) {
        precomp();
    }

    ll hash(ll v, ll i, ll j) {
        return ((ll) v * (power1[i] * power2[j] % mod)) % mod;
    }

    void precomp(){
        power1[0] = 1;
        power2[0] = 1;
        forn(i,0,MAXN-1){
            power1[i+1] = (power1[i]*b1) % mod;
            power2[i+1] = (power2[i]*b2) % mod;
        }
    }
};

Hasher h1 = Hasher(17, 19, 1'000'000'007);
Hasher h2 = Hasher(23, 31, 1'000'000'009);

struct DoubleHash {
    ll a, b;
    DoubleHash(ll v, ll i, ll j) {
        a = h1.hash(v, i, j);
        b = h2.hash(v, i, j);
    }
    DoubleHash(ll a, ll b): a(a), b(b) {}
    DoubleHash(): a(0), b(0) {}
    
    DoubleHash operator + (const DoubleHash &p) { 
        return DoubleHash((a + p.a) % h1.mod, (b + p.b) % h2.mod);
    }

    DoubleHash operator - (const DoubleHash &p) { 
        return DoubleHash((a - p.a + h1.mod) % h1.mod, (b - p.b + h2.mod) % h2.mod);
    }

    bool operator == (const DoubleHash &p) {
        return a = p.a && b == p.b;
    }

    void print() {
        cout << a << " " << b << ln;
    }

    DoubleHash shift(ll m, ll n) {
        ll new_a = (a * h1.power1[m]) % h1.mod;
        new_a = (new_a * h1.power2[n]) % h1.mod;

        ll new_b = (b * h2.power1[m]) % h2.mod;
        new_b = (new_b * h2.power2[n]) % h2.mod;
        
        return DoubleHash(new_a,new_b);
    }
};

vvc read_matrix(ll rows, ll columns) {
    vvc vec(rows, vc(columns));
    forn(i, 0, rows) {
        forn(j, 0, columns) {
            cin >> vec[i][j];
        }
    }
    return vec;
}

vector<vector<DoubleHash>> haxx(MAXN, vector<DoubleHash>(MAXN));
vector<vector<DoubleHash>> hac(MAXN, vector<DoubleHash>(MAXN));
vector<vector<DoubleHash>> har(MAXN, vector<DoubleHash>(MAXN));
ll rkey, ckey, rhay, chay, counter;

void cum_sum(){
    forn(i,0,chay){
        hac[i][0] = haxx[i][0];
        forn(j,1,rhay){
            hac[i][j] = hac[i][j-1] + haxx[i][j];
        }
    }
    forn(j,0,rhay){
        har[0][j] = haxx[0][j];
        forn(i,1,chay){
            har[i][j] = har[i-1][j] + haxx[i][j];
        }
    }
}

DoubleHash query_row(ll i, ll j) {
    DoubleHash out = har[i][j+ckey];
    if (j != 0) {
        out = out - har[i][j-1];
    }
    return out;
}

DoubleHash query_col(ll i, ll j) {
    DoubleHash out = hac[i+rkey][j];
    if (i != 0) {
        out = out - hac[i-1][j];
    }
    return out;
}

int main() {
    fast_cin();

    cin >> rkey >> ckey;
    vvc key = read_matrix(rkey, ckey);

    cin >> rhay >> chay;
    vvc haystack = read_matrix(rhay, chay);

    DoubleHash khax;

    forn(i,0,rhay){
        forn(j,0,chay){
            haxx[i][j] = DoubleHash(haystack[i][j]-'a'+1, i, j);
        }
    }

    forn(i,0,rkey){
        forn(j,0,ckey){
            khax = khax + DoubleHash(key[i][j]-'a'+1, i, j);
        }
    }

    cum_sum();

    DoubleHash phax;
    forn(i, 0, rkey){
        forn(j,0,ckey){
            phax = phax + haxx[i][j];
        }
    }

    DoubleHash qhax = phax;
    forn(i, 0, rhay-rkey){
        phax = qhax;
        forn(j,0,chay-ckey){
            if(khax.shift(i,j) == phax){
                dbg(i); dbg(j);
                cout << ln;
            }
            phax = phax + query_col(i,j+ckey) - query_col(i,j);
        }
        qhax = qhax + query_row(i+rkey,0) - query_row(i,0);
    }
}