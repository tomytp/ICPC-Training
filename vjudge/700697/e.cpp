#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    
    stack<pair<ll,ll>> smaller_to_the_left;
    forn(i, 0, n) {
        ll x; cin >> x;
        while (smaller_to_the_left.size() && smaller_to_the_left.top().first >= x) smaller_to_the_left.pop();
        
        ll ans = 0;
        if (smaller_to_the_left.size()) ans = smaller_to_the_left.top().second + 1;

        cout << ans << " \n"[i==n-1];
        smaller_to_the_left.push({x, i});
    }
    return 0;
}