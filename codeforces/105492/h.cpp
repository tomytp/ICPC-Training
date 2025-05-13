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

int main(){
    _;
    ll r, c, q;
    cin >> r >> c >> q;

    vector<vector<char>> mat(r, vector<char>(c,0));
    vector<vector<p64>> dp(r, vector<p64>(c, 0));
    vector<v64> ultima(r, v64(c, 0));

    forn(i,0,r)
    forn(j,0,c){
        cin >> mat[i][j];
    }

    forn(i,0,r){
        dp[i][0] = (mat[i][j])
    }
    forn(i,0,r)
    forn(j,0,c){
        
    }

    return 0;
}