#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ln '\n'

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> forcas(n);
    for (ll i = 0; i < n; i++) cin >> forcas[i];
    sort(forcas.rbegin(), forcas.rend());

    ll safe_count = 1;
    ll safe_sum = forcas[0];

    ll block_count = 0;
    ll block_sum = 0;
    for (ll i = 1; i < n; i++) {
        block_count++;
        block_sum += forcas[i];

        if (block_sum >= safe_sum) {
            safe_count += block_count;
            safe_sum += block_sum;
            
            block_count = 0;
            block_sum = 0;
        }
    }

    cout << safe_count << ln;
    return 0;
}