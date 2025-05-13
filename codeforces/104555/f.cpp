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
    _; ll points, c, r; cin >> points >> c >> r;
    v64 v1(c), v2(r);
    forn(i, 0, c) cin >> v1[i];
    forn(i, 0, r) cin >> v2[i];

    ll pt1 = 0, pt2 = 0, counter = 0;
    while(pt1 < c){
        if(v1[pt1] <= points){
            points -= v1[pt1];
            pt1++;
        }
        else{
            if(pt2 == r) break;
            points += v2[pt2];
            pt2++;
        }
        counter++;
    }

    cout << counter + (r-pt2) << ln;
    return 0;
}