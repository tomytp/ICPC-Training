#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef multiset<ll> m64;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"


int main() {
    fast_cin();

    int N, T, v, ans = 0;
    int c = 0, f = 0, p = 0, q = 0;
    char b;
    m64 C, F, P, Q;

    cin >> N >> T;

    forn(i, 0, N) {
        cin >> b >> v;
        switch (b) {
            case 'C':
                if (c + v <= T) {
                    C.insert(v);
                    c += v;
                    ans++;
                }
                else if (v < *C.end()) {
                    C.insert(v);
                    c += v - *C.end();
                    C.erase(*C.end());
                    ans++;
                }
                break;
            case 'F':
                if (f + v <= T) {
                    F.insert(v);
                    f += v;
                    ans++;
                }
                else if (v < *F.end()) {
                    F.insert(v);
                    f += v - *F.end();
                    F.erase(*F.end());
                    ans++;
                }
                break;
            case 'P':
                if (p + v <= T) {
                    P.insert(v);
                    p += v;
                    ans++;
                }
                else if (v < *C.end()) {
                    P.insert(v);
                    p += v - *P.end();
                    P.erase(*P.end());
                    ans++;
                }
                break;
            case 'Q':
                if (q + v <= T) {
                    Q.insert(v);
                    q += v;
                    ans++;
                }
                else if (v < *Q.end()){
                    Q.insert(v);
                    q += v - *Q.end();
                    Q.erase(*Q.end());
                    ans++;
                }
                break;
        }
    }

    cout << ans;
    
    return 0;
}