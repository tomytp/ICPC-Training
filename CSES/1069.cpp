#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()


int main() {
    string s; cin >> s;
    ll maximo = 1;
    ll current = 1;

    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i - 1]) {
            current++;
        } else {
            current = 1;
        }
        maximo = max(maximo, current);
    }

    cout << maximo << ln;
}