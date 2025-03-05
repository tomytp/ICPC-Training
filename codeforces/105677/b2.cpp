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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _;
    ll n; ll k_orig;
    map<ll,ll> freq;

    cin >> n >> k_orig;
    
    v64 vec;
    
    forn(i,0,n){
        ll aux; cin >> aux;
        if(freq[aux] == 0){
            vec.push_back(aux);
        }
        freq[aux]++;
    }

    n = vec.size();
    
    if(n <= k_orig){
        cout << 0 << ln;
        return 0;
    }


    sort(vec.begin(), vec.end());

    vector<vector<v64>> dp(n, vector<v64>(n, v64(k_orig+1,INF)));

    dp[n-1][n-1][1] = 0;

    for(ll i = n-2; i >= 0; i--){
        dp[i][n-1][1] = dp[i+1][n-1][1] + freq[vec[i]]*(vec[n-1] - vec[i])*(vec[n-1] - vec[i]);
    }

    forn(k,2,k_orig+1){
        for(ll i = n-1; i >= 0; i--){
            for(ll j = n-k; j >= i; j--){
                if(i == j){
                    forn(x,i,n-k+2){
                        dp[i][i][k] = min(dp[i][i][k], dp[i+1][x][k-1]);
                    }
                }else{
                    dp[i][j][k] = dp[i+1][j][k] + freq[vec[i]]*(vec[i] - vec[j])*(vec[i] - vec[j]); 
                }        
            }
        }
    }

    // forn(k,1,k_orig+1){
    //     forn(j,0,n){
    //         forn(i,0,n){
    //             if(dp[i][j][k] == INF){
    //                 cout << "# ";
    //             }else{
    //                 cout << dp[i][j][k] << ' ';
    //             }
    //         }
    //         cout << ln;
    //     }
    //     cout << ln << ln;
    // }

    ll ans = INF;

    forn(j,0,n-1){
        ans = min(ans, dp[0][j][k_orig]);
    }
    cout << ans << ln;
    return 0;
}