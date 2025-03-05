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

int main(){
    _; ll b, l, sum = 0, sign = -1; cin >> b >> l;
    v64 digit(l);
    if(l%2 == 0) sign = 1;
    forn(i, 0, l){
        cin >> digit[i];
        sum += sign*digit[i];
        sign = -sign;
    } 

    sum = sum%(b+1);
    if(sum<0) sum += b+1;
    ll neg_sum = b+1-sum;

    if(sum == 0){
        cout << "0 0" << ln;
        return 0;
    }

    ll change_index = -1;
    ll new_value = -1;
    forn(i, 0, l){
        if((l-i)%2 == 1 and digit[i]-neg_sum >= 0){
            change_index = i;
            new_value = digit[i]-neg_sum;
            break;
        }
        if((l-i)%2 == 0 and digit[i]-sum >= 0){
            change_index = i;
            new_value = digit[i]-sum;
            break;
        }
    }

    if(change_index == -1){
        cout << "-1 -1" << ln;
        return 0;
    }

    cout << change_index+1 << " " << new_value << ln;
    return 0;
}