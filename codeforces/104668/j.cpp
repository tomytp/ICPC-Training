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

ll solve(vector<vector<char>>& mat){
    ll n = mat.size();
    ll m = mat[0].size();

    vector<v64> dp(n, v64(m,1)); 

    // forn(i,0,n) forn(j,0,n) cout << mat[i][j] << " \n"[j == n-1];
    
    
    ll resp = 0;
    
    forn(i,1,n){
        forn(j,1,m){
            if(mat[i][j] != mat[i-1][j] || mat[i][j] != mat[i][j-1]) continue;

            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            resp += dp[i][j] - 1;
        }
    }
    return resp;
}

int main(){
    _;
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> matne(n, vector<char>(m));
    vector<vector<char>> matno(n, vector<char>(m));
    vector<vector<char>> matse(n, vector<char>(m));
    vector<vector<char>> matso(n, vector<char>(m));
    
    forn(i,0,n) forn(j,0,m){
        char c; cin >> c;
        matno[i][j] = c;  
        matne[n-1-i][j] = c;  
        matse[i][m-1-j] = c;  
        matso[n-1-i][m-1-j] = c;  
    } 

    ll resp = 0;

    resp += solve(matno);
    debug(resp);
    resp += solve(matne);
    debug(resp);
    resp += solve(matso);
    debug(resp);
    resp += solve(matse);
    debug(resp);

    cout << resp << ln;
    return 0;
}