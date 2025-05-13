#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;

    int type;
    ll num;
    cin >> type >> num;
    map<ll, ll> bigs = {{1, num}};    
    map<ll, ll> smalls = {{1, num}};
    map<ll, ll> sums = {{1, num}};

    ll ans;
    for (ll i = 1; i < n; i++) {
        cin >> type >> num;
        if (type == 1) {
            if ((--bigs.end())->second < num) {
                bigs.insert({i+1, num});
            } else if ((--smalls.end())->second < num) {
                smalls.insert({i+1, num});
            }
            sums.insert({i+1, (--sums.end())->second + num});
        } else if (type == 2) {
            ans = (--bigs.end())->second;
            for (auto it = bigs.begin(); it != bigs.end(); it++) {
                if (it->first > num) {
                    ans = (--it)->second;
                    break;
                } else if (it->first == num) {
                    ans = it->second;
                    break;
                }
            }
            cout << ans << endl;
        } else if (type == 3) {
            ans = (--smalls.end())->second;
            for (auto it = bigs.begin(); it != bigs.end(); it++) {
                if (it->first > num) {
                    ans = (--it)->second;
                    break;
                } else if (it->first == num) {
                    ans = it->second;
                    break;
                }
            }
            cout << ans << endl;
        } else {
            ans = (--sums.end())->second;
            for (auto it = sums.begin(); it != sums.end(); it++) {
                if (it->first > num) {
                    ans = (--it)->second;
                    break;
                } else if (it->first == num) {
                    ans = it->second;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}