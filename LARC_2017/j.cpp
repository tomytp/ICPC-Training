#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())
#define dbg(x) cout << #x << " = " << x << ln

ll solve(ll i, ll n , string lake){
    v64 paths(i,0);
    ll d = n/i;
    forn(j, n){
        if(lake[j] == 'R'){
            paths[j%i]++;
            if(paths[j%i]==d) return 1;
        }
    }
    return 0;
}

int main(){
    fast_cin();
    ll n, counter=0, sum=0;
    string lake;
    cin >> lake;
    n = sz(lake);
    v64 dp(n,0);
    forsn(i,1,n){
        if(n % i==0){
            dp[i] = solve(i, n, lake);
        } else {
            dp[i]=dp[gcd(i,n)];
        }
        sum += dp[i];
    }

    cout << sum << ln;
}