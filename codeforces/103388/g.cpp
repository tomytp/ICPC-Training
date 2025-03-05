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
v64 fibo;

string solve(ll n, ll i){
    if(n == 1){
        return "";
    }

    for(; i >= 2; i--){
        if(n%fibo[i] == 0){
            string s1;
            forn(j, 1, i) s1.push_back('A');
            s1.push_back('B');
            string resp1 = solve(n/fibo[i], i);
            string resp2 = solve(n,i-1);
            if(resp2 == "IMPOSSIBLE"){
                if(resp1 == "IMPOSSIBLE"){
                    return "IMPOSSIBLE";
                }
                return s1+resp1;
            }
            if(resp1 == "IMPOSSIBLE"){
                return resp2;
            }
            return min(s1+resp1, resp2);
        }
    }

    return "IMPOSSIBLE";
}

int main(){
    _; ll n; cin >> n;
    string s;
    fibo.push_back(1);
    fibo.push_back(1);
    while(fibo[fibo.size()-1] < MAXN) fibo.push_back(fibo[fibo.size()-1] + fibo[fibo.size()-2]);

    ll tamanho = fibo.size();
    cout << solve(n, tamanho-1) << ln;

    return 0;
}