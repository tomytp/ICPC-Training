#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define NMAX 1000001

bool vec[NMAX];

int main() {
    fast_cin();
    ll n; cin >> n;
    
    ll sum = n * (n+1) / 2;
    ll used = 0;

    if (sum & 1) {
        cout << "NO" << ln;
        return 0;
    } else {
        cout << "YES" << ln;
        sum /= 2;
        ll current = n;
        while (sum) {
            if (sum < current) {
                current = sum;
            } else {
                sum -= current;
                vec[current] = true;
                used++;
                current--;
            }
        }
    }

    cout << used << ln;
    forn(i, 1, n+1) {
        if (vec[i]) cout << i << " ";
    }
    cout << ln << n - used << ln;
    forn(i, 1, n+1) {
        if (!vec[i]) cout << i << " ";
    }
    cout << ln;
    return 0;
}