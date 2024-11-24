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

bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

v64 get_prime_factors(ll n) {
    v64 factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

pair<ll, ll> solve_game(ll q) {
    if (q == 1 || is_prime(q)) {
        return {1, 0};
    }
    
    v64 factors = get_prime_factors(q);
    
    v64 unique_factors;
    for (ll f : factors) {
        if (unique_factors.empty() || unique_factors.back() != f) {
            unique_factors.push_back(f);
        }
    }
    
    if ((unique_factors.size() == 2 && factors.size() == 2) ||
        (unique_factors.size() == 1 && factors.size() == 2)) {
        return {2, 0};
    }
    
    if (factors.size() >= 2) {
        return {1, factors[0] * factors[1]};
    }
    
    return {1, factors[0]};
}

int main() {
    ll q;
    cin >> q;
    
    pair<int, ll> result = solve_game(q);
    cout << result.first << ln;
    if (result.first == 1) {
        cout << result.second << ln;
    }
    
    return 0;
}
