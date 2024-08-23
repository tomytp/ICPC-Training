#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) ((ll) (x).size())
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L

#define NMAX 1000000

string arr[NMAX];
set<string> total;
set<string> prefix;

void permutations(string& s, ll start, ll end) {
    if (start == end) {
        total.insert(s);
    } else {
        forn(i, start, end + 1) {
            swap(s[start], s[i]);
            string pre = s.substr(0, start + 1);
            if (prefix.find(pre) == prefix.end()) {
                permutations(s, start + 1, end);
                prefix.insert(pre);
            }
            swap(s[start], s[i]);
        }
    }
}

int main() {
    fast_cin();
    string s; cin >> s;

    permutations(s, 0, sz(s) - 1);

    cout << sz(total) << ln;
    for (auto& str : total) {
        cout << str << ln;
    }
}