#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

int calculate_mex(const vector<int>& arr) {
    set<int> s;
    for (int x : arr) {
        if (x >= 0) {
            s.insert(x);
        }
    }
    int mex_val = 0;
    while (s.count(mex_val)) {
        mex_val++;
    }
    return mex_val;
}

bool is_magical(const vector<int>& s) {
    int n = s.size();
    if (n <= 1) {
        return true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int current_min = s[0];
        for (int j = 1; j <= i; ++j) {
            current_min = min(current_min, s[j]);
        }
        vector<int> suffix;
        for (int j = i + 1; j < n; ++j) {
            suffix.push_back(s[j]);
        }
        if (current_min < calculate_mex(suffix)) {
            return false;
        }
    }
    return true;
}

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_len = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subsequence;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subsequence.push_back(a[j]);
            }
        }
        if (is_magical(subsequence)) {
            max_len = max(max_len, (int)subsequence.size());
        }
    }
    return max_len;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}