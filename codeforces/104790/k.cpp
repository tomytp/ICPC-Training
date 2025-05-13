    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll, ll> p64; 
    typedef vector<ll> v64;

    #define forn(i, s, e) for(ll i = (s); i < (e); i++)
    #define ln "\n"

    #if defined(DEBUG)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
    #else
    #define _ (void)0
        #define debug(x) (void)0
    #endif

    const ll INF = 0x3f3f3f3f3f3f3f3fll;

    mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

    ll uniform(ll l, ll r){
        uniform_int_distribution<ll> uid(l, r);
        return uid(rng);
    }

    ll n;
    ll lx, ly, rx, ry;
    ll ans = 0;

    map<pair<ll, ll>, ll> mp;

    ll ask(ll x, ll y) {
        if (mp.count({x, y})) return mp[{x,y}];
        cout << "? " << x << " " << y << ln;
        cout.flush();
        ll k; cin >> k;
        mp[{x, y}] = k;
        ans = max(ans, k);
        return k;
    }


    int main(){
        _;
        cin >> n;

        ll maxi = 0, mx, my;

        forn(i, 0, n*3) {
            ll x = uniform(1, n);
            ll y = uniform(1, n);
            ll resp = ask(x, y);
            if (maxi < resp) {
                maxi = resp;
                mx = x;
                my = y;
            }
        }

        vector<p64> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (true) {
            bool a = true;
            for (auto dir : dirs) {
                ll x = mx + dir.first;
                ll y = my + dir.second;
                if (x <= 0 || x > n) continue;
                if (y <= 0 || y > n) continue;
                ans = ask(x, y);
                if (ans > maxi) {
                    a = false;
                    maxi = ans;
                    mx = x;
                    my = y;
                    break;
                }
            }
            if (a) break;
        }


        cout << "! " << maxi << ln;
        cout.flush();

        return 0;
    }