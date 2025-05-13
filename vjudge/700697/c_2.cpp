#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> mini(n+1, INF), maxi(n+1, 0), sum(n+1);

    ll type, q;
    forn(i, 1, n+1) {
        sum[i] = sum[i-1];
        mini[i] = mini[i-1];
        maxi[i] = maxi[i-1];

        cin >> type >> q;
        if (type == 1) {
            mini[i] = min(mini[i], q);
            maxi[i] = max(maxi[i], q);
            sum[i] += q;
        }
        else if (type == 2) cout << maxi[q] << ln;
        else if (type == 3) cout << mini[q] << ln;
        else cout << sum[q] << ln;
    }

    return 0;
}