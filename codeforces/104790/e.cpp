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

struct my_test{
    ll start, prep_end, end, cost, delta, g;

    my_test(ll s_,ll p_,ll e_,ll a_){
        start = s_;
        prep_end = p_;
        end = e_;
        cost = a_;
        delta = end - prep_end;
    }
};

int main(){
    _;
    ll n; cin >> n;
    vector<my_test> vec;

    vec.push_back(my_test(0,0,0,0));
    forn(i,1,n+1){
        ll s, p, e, a;
        cin >> s >> p >> e >> a;
        vec.push_back(my_test(s,p,e,a));    
            vec[i].g = vec[i].start - vec[i-1].end; 
        }

    vector<v64> dp(n+1, v64(n+1, -INF));

    forn(i,0,n+1){
        if(i == 0){
            dp[0][0] = 0;
            continue;
        }
        forn(j,0,n+1){
            if(j == 0){
                dp[i][0] = dp[i-1][0] + vec[i].g; 
                continue;
            }

            ll curr_resp = dp[i-1][j] + vec[i].g;
            
            if(dp[i-1][j] == -INF){
                curr_resp = -INF;
            }

            if(dp[i-1][j-1] + vec[i].g >= vec[i].cost){
                curr_resp = max(curr_resp, dp[i-1][j-1] + vec[i].g - vec[i].cost + vec[i].delta); 
            }

            dp[i][j] = curr_resp;
        }
    }

    ll idx = n;

    // forn(j,0,n+1){
    //     forn(i,0,n+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << ln;
    // }
    for(; idx >= 0; idx--){
        if(dp[n][idx] != -INF){
            break;
        }
    }

    cout << idx << ln;
    return 0;
}