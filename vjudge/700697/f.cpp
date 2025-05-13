#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    stack<ll> st;

    ll ans = 0;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        while (st.size() && st.top() > aux) st.pop();

        if (!st.size() || st.top() != aux) {
            ans++;
            st.push(aux);
        }
    }
    cout << ans << ln;
    return 0;
}