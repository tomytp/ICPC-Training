#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define NMAX 200001

bool nums[NMAX];

int main() {
    ll n; cin >> n;
    for (ll i = 0; i < n - 1; i++) {
        ll numero; cin >> numero;
        nums[numero] = true;
    }

    for (ll i = 1; i <= n; i++) {
        if (!nums[i]) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}