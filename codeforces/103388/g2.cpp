#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
#define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
#define _ (void)0
#define debug(x) (void)0
#endif

const ll MAXN = 1'000'000'000'000'008ll;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

string solve(ll n){
    v64 fibo;
    string s;
    fibo.push_back(1);
    fibo.push_back(1);
    while(fibo[fibo.size()-1] < MAXN) fibo.push_back(fibo[fibo.size()-1] + fibo[fibo.size()-2]);
    
    if(n == 1){
        cout << 'B' << ln;
        return 0;
    }

    ll tamanho = fibo.size();
    for(ll i = tamanho-1; i >= 2; i--){
        while(n%fibo[i] == 0){
            n = n/fibo[i];
            forn(j, 1, i) s.push_back('A');
            s.push_back('B');
        }
    }

    if(n != 1){
        return "IMPOSSIBLE";
    }

    return s;
}

string conv(ll a){
    string s;
    while(a > 0){
        if(a % 2 == 0) s.push_back('A');
        else s.push_back('B');
        a /= 2;
    }
    return s;
}
int main(){
    //ll pow2 = 32768;
    ll pow2 = 1048576;
    vector<ll> dp(pow2+1);
    map<ll, string> min_s;

    dp[0] = 1;

    forn(i,1,pow2){
        if(i%2 == 0) dp[i] = dp[i/2] + dp[i/4];
        else dp[i] = dp[i/2];
        
        if(min_s[dp[i]] == "") min_s[dp[i]] = conv(i); 
        else min_s[dp[i]] = min(conv(i), min_s[dp[i]]);
    }

    forn(i,2,2000){
        string resp1, resp2;
        
        if(min_s[i] == "") resp1 = "IMPOSSIBLE";
        else resp1 = min_s[i];
        
        resp2 = solve(i);
        
        if(resp1 != resp2){
            cout << i << ": ";
            cout << resp1 << ln;
            cout << resp2 << ln;
            cout << ln;
        }
    }
}