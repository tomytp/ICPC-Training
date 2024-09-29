#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define mp make_pair

int main() {
    FAST_CIN;
    string giga; cin >> giga;
    ll n = giga.size();
    ll q; cin >> q;
    vector<map<char, ll>> g(giga.size());

    forn(i, 0, n) {
        forn(j, i+1, n) {
            if (g[i].find(giga[j]) == g[i].end()) {
                g[i][giga[j]] = j;
            }
        }
    }
    
    // forn(i, 0, (ll) giga.size()) {
    //     for(auto entry : g[i]) {
    //         cout << entry.first << ":" << entry.second << " ";
    //     }
    //     cout << ln;
    // }

    forn(i, 0, q) {
        string amigo; cin >> amigo;
        ll menor = 10000;
        forn(j, 0, n) {
            if(giga[j] != amigo[0]) continue;
            ll pointer_giga = j;
            ll pointer = 1;
            while(pointer != (ll) amigo.size() || n-pointer_giga < amigo.size()-pointer+1) {
                // dbg(pointer);
                // dbg(pointer_giga);
                auto it = g[pointer_giga].find(amigo[pointer]);
                if(it != g[pointer_giga].end()) {
                    pointer_giga = it->second;
                    pointer++;
                } else {
                    break;
                }
                // dbg((pointer != (ll) amigo.size()));
                // dbg((n-pointer_giga < amigo.size()-pointer));
            }
            if (pointer == amigo.size()) {
                menor = min(menor, pointer_giga-j);
            }
        }
        if (menor != 10000) {
            cout << menor-amigo.size() + 1 << ln;
        } else {
            cout << -1 << ln;
        }
    }
}
