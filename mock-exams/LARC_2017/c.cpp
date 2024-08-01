#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())
#define dbg(x) cout << #x << " = " << x << ln


int main(){
    //fast_cin();
    ll k, n; cin >> k >> n;
    v64 ocur(k, 0);

    forn(i, n) {
        ll aux; cin >> aux;
        ocur[--aux]++;
    }

    map<ll, p64> freqs;
    
    forn(i, k) {
        if (freqs.find(ocur[i]) == freqs.end()) {
            freqs[ocur[i]] = mp(1, i);
        } else {
            freqs[ocur[i]] = mp(freqs[ocur[i]].fi + 1, i);
        }
    }
    ll total_bigs = 0;
    for(auto p : freqs) {
        if (p.se.fi > 1) total_bigs++;
    }
    if (total_bigs == 2 && sz(freqs) == 2 && abs((*freqs.begin()).se.fi - (*++freqs.begin()).se.fi) == 2) {
        auto a = *freqs.begin();
        auto b = *++freqs.begin();
        if (a.se.fi < b.se.fi) {
            cout << '-' << b.se.se << " +" << a.se.se << ln; 
        } else {
            cout << '-' << a.se.se << " +" << b.se.se << ln; 
        }
    }

    ll neg = -1, pos = -1;
    ll count_bigs = 0;
    ll counter = 0;
    ll temp = -1;
    for(auto p : freqs) {
        dbg(p.se.fi);
        if (temp != -1 && p.se.fi != temp + 1) {
            cout << "*" << ln;
            return 0;
        }
        temp = p.se.fi;
        counter++;
        if (p.se.fi > 1 || !total_bigs && counter == 2) count_bigs++;
        else {
            if (count_bigs == 0) {
                if (neg == -1) {
                    neg = p.se.se;
                }
                else {
                    cout << "*" << ln;
                    return 0;
                }
            }
            else if (count_bigs == 1) {
                if (pos == -1) {
                    pos = p.se.se;
                } else {
                    cout << "*" << ln;
                    return 0;
                }
            }
        }
    }
    if (count_bigs > 1) {
        cout << "*" << ln;
        return 0;
    }

    if (pos != -1) {
        cout << "-" << pos + 1<< " ";
    }
    if (neg != -1) {
        cout << "+" << neg + 1 << " ";
    }
    cout << ln;
}