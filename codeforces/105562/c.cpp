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

int main(){
    _;
    ll n = 5;
    set<p64> pts;
    forn(i, 0, n) {
        ll x, y; cin >> x >> y;
        pts.emplace(x, y);
    }

    ll ans = 0;
    bool swaped = true;
    while (swaped) {
        if (pts.size() == 1) break;
        swaped = false;
        vector<p64> xy;
        vector<p64> yx;
        for(auto& [x,y] : pts) {
            debug(x);
            debug(y);
            xy.emplace_back(x, y);
            yx.emplace_back(y, x);
        }
        sort(xy.begin(), xy.end());
        sort(yx.begin(), yx.end());

        if (xy[0].first != xy[1].first) {
            pts.erase(xy[0]);
            ans += abs(xy[1].first - xy[0].first);
            xy[0].first = xy[1].first;
            pts.insert(xy[0]);
            swaped = true;
            continue;
        }

        if (xy[xy.size()-1].first != xy[xy.size()-2].first) {
            pts.erase(xy[xy.size()-1]);
            ans += abs(xy[xy.size()-1].first - xy[xy.size()-2].first);
            xy[xy.size()-1].first = xy[xy.size()-2].first;
            pts.insert(xy[xy.size()-1]);
            swaped = true;
            continue;
        }
    
        if (yx[0].first != yx[1].first) {
            pts.erase({yx[0].second, yx[0].first});
            ans += abs(yx[0].first - yx[1].first);
            yx[0].first = yx[1].first;
            pts.insert({yx[0].second, yx[0].first});
            swaped = true;
            continue;
        }

        if (yx[yx.size()-1].first != yx[yx.size()-2].first) {
            pts.erase({yx[yx.size()-1].second, yx[yx.size()-1].first});
            ans += abs(yx[yx.size()-1].first - yx[yx.size()-2].first);
            yx[yx.size()-1].first = yx[yx.size()-2].first;
            pts.insert({yx[yx.size()-1].second, yx[yx.size()-1].first});
            swaped = true;
            continue;
        }
    }

    if (pts.size() == 1) {
        cout << ans << ln;
        return 0;
    }

    set<ll> xs, ys;
    ll x_max = -1, x_min = INF, y_max = -1, y_min = INF;
    for (auto& [x, y]: pts) {
        xs.insert(x);
        ys.insert(y);

        x_max = max(x_max, x);
        x_min = min(x_min, x);
        y_max = max(y_max, y);
        y_min = min(y_min, y);
    }
    bool pt_no_meio = false;
    for (auto& [x, y] : pts) {
        if (x != x_max && x != x_min && y != y_max && y != y_min) {
            pt_no_meio = true;
            break;
        }
    }

    debug(ans);
    ans += 2* (abs(x_max - x_min) + abs(y_max - y_min));
    debug(ans);

    if (pt_no_meio) {
        ans += min(abs(x_max - x_min), abs(y_max - y_min));
    }

    cout << ans << ln;


    return 0;
}