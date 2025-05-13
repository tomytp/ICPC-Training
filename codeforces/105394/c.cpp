#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll id(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 26 + c - 'A';
    }
    return c - 'a';
}

bool is_var(string c) {
    if (c.size() > 1) return false;
    return (c[0] <= 'Z' && c[0] >= 'A') || (c[0] <= 'z' && c[0] >= 'a');
}
char get_c(ll i) {
    if (i < 26) {
        return 'a' + i;
    }
    return 'A' + i - 26;
}

int main(){
    _;
    ll n; cin >> n;
    vector<string> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    vector<vector<string>> suff(n);
    forn(i, 0, n) {
        map<string, string> mp;
        ll curr = 0;
        forn(j, i, n) {
            if (!is_var(v[j])) suff[i].push_back(v[j]);
            else {
                if (mp.find(v[j]) == mp.end()) {
                    mp[v[j]] = get_c(curr++);
                }
                suff[i].push_back(mp[v[j]]);
            }
        }
    }

    sort(suff.begin(), suff.end());
    // forn(i, 0, suff.size()) {
    //     forn(j, 0, suff[i].size()) cout << suff[i][j] << " \n"[j == suff[i].size()-1];
    // }
    // cout << "---------\n";
    
    ll q; cin >> q;
    forn(i, 0, q) {
        ll nq; cin >> nq;
        vector<string> vq(nq), vq2;
        forn(j, 0, nq) cin >> vq[j];

        map<string, string> mp;
        ll curr = 0;
        forn(j, 0, vq.size()) {
            if (!is_var(vq[j])) vq2.push_back(vq[j]);
            else {
                if (mp.find(vq[j]) == mp.end()) {
                    mp[vq[j]] = get_c(curr++);
                }
                vq2.push_back(mp[vq[j]]);
            }
        }


        ll l = 0, r = n-1;

        bool solved = false;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (vq2.size() <= suff[mid].size()) {
                bool match = true;
                forn(k, 0, vq2.size()) {
                    if (vq2[k] != suff[mid][k]) {
                        match = false;
                        break;
                    }
                }
                // forn(akjd, 0, vq2.size()) cout << vq2[akjd] << " \n"[akjd==vq2.size()-1];
                // forn(akjd, 0, suff[mid].size()) cout << suff[mid][akjd] << " \n"[akjd == suff[mid].size()-1];

                if (match) {
                    cout << "yes" << ln;
                    solved = true;
                    break;
                }
            }
            if (vq2 < suff[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (!solved) {
            cout << "no" << ln;
        }

        



    }

    return 0;
}