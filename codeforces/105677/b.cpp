#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ 
    #define debug(x) 
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll get_penalty(ll deli, ll opt) {
    return (ll)(deli - opt) * (deli - opt);
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<p64> gifts(n);
    for (ll i = 0; i < n; ++i) {
        cin >> gifts[i].first;
        gifts[i].second = i;
    }

    sort(gifts.begin(), gifts.end());
    k = min(n, k);

    // cost_matrix[j][i]: penalty if gift with sorted index 'i' is delivered on day gifts[j].first
    vector<v64> pref_cost(n, v64(n));
    for (ll ddi = 0; ddi < n; ++ddi) {
        for (ll gi = 0; gi < n; ++gi) {
            pref_cost[ddi][gi] = get_penalty(gifts[ddi].first, gifts[gi].first);
        }
    }

    // prefix_cost_matrix[j][i]: sum of penalties if gifts with sorted indices 0 to i are delivered on day gifts[j].first
    for (ll j = 0; j < n; ++j) {
        partial_sum(pref_cost[j].begin(), pref_cost[j].end(), pref_cost[j].begin());
    }

    auto rsq = [&](ll ddi, ll l, ll r) {
        if (l > r) return 0LL;
        ll penalty_sum = pref_cost[ddi][r];
        if (l > 0) {
            penalty_sum -= pref_cost[ddi][l - 1];
        }
        return penalty_sum;
    };

    // dp[i][k]: Minimum penalty to deliver the first (i+1) sorted gifts using at most k delivery days.
    vector<v64> dp(n, v64(k + 1, INF));
    // backpoller[i][k]: stores the split poll 'prev_gift_index' that leads to the optimal dp[i][k]
    vector<v64> backpoller(n, v64(k + 1, -1));

    // Base case: using only 1 delivery day
    for (ll gift_index = 0; gift_index < n; ++gift_index) {
        dp[gift_index][1] = rsq(gift_index, 0, gift_index);
    }

    // DP recurrence: Calculate dp[gift_index][days] for days > 1
    for (ll days = 2; days <= k; ++days) {
        for (ll cgi = 0; cgi < n; ++cgi) {
            for (ll pgi = 0; pgi < cgi; ++pgi) {
                ll cp = dp[pgi][days - 1] + rsq(cgi, pgi + 1, cgi);
                if (cp < dp[cgi][days]) {
                    dp[cgi][days] = cp;
                    backpoller[cgi][days] = pgi;
                }
            }
             // Also consider the case where all gifts up to current_gift_index are delivered on the 'days'-th day
             ll current_penalty_no_split = rsq(cgi, 0, cgi);
             if (days == 1) { // already handled base case, but just for completeness/clarity, no split for day 1 is covered above
                 dp[cgi][days] = min(dp[cgi][days], current_penalty_no_split);
             } else if (dp[cgi][days] > current_penalty_no_split && cgi == 0) {
                 // Handles the case where we use 'days' days only for the first gift, not particularly useful, but logically valid.
                 dp[cgi][days] = current_penalty_no_split;
                 backpoller[cgi][days] = -1; // No split
             }
        }
    }

    forn(i, 0, n) {
        forn(j, 1, k+1) {
            cout << dp[i][j] << " ";
        }
        cout << ln;
    }
    cout << ln;

    forn(i, 0, n) {
        forn(j, 1, k+1) {
            cout << backpoller[i][j] << " ";
        }
        cout << ln;
    }

    v64 delivery_days_assignment(n, -1);
    ll last_gift_index = n - 1;
    ll current_days = k;

    while (current_days > 0 && last_gift_index >= 0) {
        ll split_gift_index = backpoller[last_gift_index][current_days];
        ll delivery_day = gifts[last_gift_index].first;

        ll start_index = (split_gift_index == -1) ? 0 : split_gift_index + 1;
        for (ll i = start_index; i <= last_gift_index; ++i) {
            delivery_days_assignment[gifts[i].second] = delivery_day; // Assign delivery day to original gift index
        }

        last_gift_index = split_gift_index;
        current_days--;
    }

    // for (ll i = 0; i < n; ++i) {
    //     cout << delivery_days_assignment[i] << (i == n - 1 ? "" : " ");
    // }
    cout << endl;

    return 0;
}