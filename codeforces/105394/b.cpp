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
    _; ll n, h, w=0; cin >> n >> h;
    vector<v64> book(n, v64(3));
    forn(i, 0, n){
        cin >> book[i][0] >> book[i][1] >> book[i][2];
    }

    forn(i, 0, n){
        sort(book[i].begin(), book[i].end());
        if(book[i][0] > h){
            cout << "impossible" << ln;
            return 0;
        }
        if(book[i][1] > h){
            w += book[i][1];
        }
        else{
            w += book[i][0];
        }
    }

    cout << w << ln;
    return 0;
}