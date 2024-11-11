#include <bits/stdc++.h>
using namespace std;

typedef int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;  // empty sequence costs 0
    
    for(int mask = 0; mask < (1 << n); mask++) {
        if(dp[mask] == INT_MAX) continue;
        
        vector<pair<int,int>> seq; // {value, position}
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) {
                seq.push_back({arr[i], i});
            }
        }
        
        bool valid = true;
        for(int i = 1; i < seq.size(); i++) {
            if(seq[i].first < seq[i-1].first) {
                valid = false;
                break;
            }
        }
        if(!valid) continue;
        
        // Try adding each remaining element
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) continue;  // already included
            
            // Check if adding this element maintains sorted property
            bool can_add = true;
            if(!seq.empty() && arr[i] < seq.back().first) {
                can_add = false;
            }
            
            if(can_add) {
                int new_mask = mask | (1<<i);
                // Calculate cost of intervals removed
                int last_pos = -1;
                int cost = 0;
                int curr_interval = 0;
                
                for(int j = 0; j < n; j++) {
                    if(new_mask & (1<<j)) {
                        if(curr_interval > 0) {
                            cost += curr_interval * curr_interval;
                            curr_interval = 0;
                        }
                    } else {
                        curr_interval++;
                    }
                }
                if(curr_interval > 0) {
                    cost += curr_interval * curr_interval;
                }
                
                dp[new_mask] = cost;
            }
        }
    }
    
    cout << dp[(1<<n)-1] << '\n';
    
    return 0;
}