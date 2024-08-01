#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_cin();
    ll n; cin >> n;
    
    if (n == 1) {
        cout << 1 << ln;
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << ln;
        return 0;
    }

    ll impar;
    if (n & 1) impar = n;
    else impar = n-1;

    while (impar > 0) {
        cout << impar << " ";
        impar -= 2;
    }

    cout << "4 2 ";
    ll par = 6;
    while (par <= n) {
        cout << par << " ";
        par += 2;
    }

    cout << ln;   

    return 0;
}