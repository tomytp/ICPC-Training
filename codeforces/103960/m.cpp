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
const ll MAXN = 100008;

v64 primes;
vector<bool> is_comp(MAXN,false);

void sieve(ll n){
  forn(i,2,n){
    if(!is_comp[i]){
      primes.push_back(i);
    }
    
    forn(j,0,primes.size()){
      if(i*primes[j] > n) break;
      is_comp[i*primes[j]] = true;   
      if(i % primes[j] == 0) break;
    }
  }
}

int main(){
    _;
    return 0;
}