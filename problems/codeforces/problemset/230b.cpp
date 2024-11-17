#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

#define MAXN 1000001

v64 primes;
vector<bool> is_comp(MAXN,false);
ll phi[MAXN];
ll cum_sum[MAXN];

void sieve(ll n){
  phi[1] = 1;
  forn(i,2,n){
    if(!is_comp[i]){
      phi[i] = i-1;
      primes.push_back(i);
    }
    
    forn(j,0,primes.size()){
      if(i*primes[j] > n) break;
      is_comp[i*primes[j]] = true;
      
      if(i % primes[j] == 0){
        phi[i*primes[j]] = phi[i]*primes[j]; 
        break;
      }
      phi[i*primes[j]] = phi[i]*phi[primes[j]];    
    }
  }
}

int main(){
    F_;
    sieve(MAXN);
    set<ll> sq;
    forn(i, 0, primes.size()) {
        sq.insert(primes[i]*primes[i]);
    }
    ll n; cin >> n;
    forn (i, 0, n) {
        ll t; cin >> t;
        cout << (sq.find(t) != sq.end()? "YES" : "NO") << ln;
    }
    P_; return 0;
}