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
    ll n;
    cin >> n;
    ll curr_shift = 1;
    ll num_op = 1;
    vector<string> resp;
    
    ll counter = 0;

    forn(i,0,20){
        counter++;
        curr_shift *= 2;
        counter++;
        if(curr_shift >= n) break;
    }
    curr_shift = 1;
    cout << counter + 2 << ln;

    forn(i,0,20){
        cout << "B" << num_op << " = B" << num_op-1 << " << " << curr_shift << ln;
        num_op++;
        cout << "B" << num_op << " = B" << num_op-2 << " | " << "B" << num_op-1 << ln;
        curr_shift *= 2;
        num_op++;
        if(curr_shift >= n) break;
    }

    cout << "B" << num_op << " = B" << num_op-1 << " << " << 1 << ln;
    num_op++;  
    cout << "B" << num_op << " = B" << num_op-2 << " ^ " << "B" << num_op-1 << ln;

    return 0;
}