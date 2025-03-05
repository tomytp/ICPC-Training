#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool is_beautiful(const vector<int>& seq) {
    if (seq.size() < 3) {
        return false;
    }
    for (size_t i = 1; i < seq.size(); ++i) {
        bool found_smaller_left = false;
        for (size_t j = 0; j < i; ++j) {
            if (seq[j] < seq[i]) {
                found_smaller_left = true;
                break;
            }
        }
        if (!found_smaller_left) {
            return false;
        }
    }
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        bool found_larger_right = false;
        for (size_t j = i + 1; j < seq.size(); ++j) {
            if (seq[j] > seq[i]) {
                found_larger_right = true;
                break;
            }
        }
        if (!found_larger_right) {
            return false;
        }
    }
    return true;
}

long long solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long beautiful_count = 0;
    long long mod = 998244353;

    for (int len = 3; len <= 4; ++len) {
        vector<int> indices(len);
        function<void(int, int)> generate_combinations = 
            [&](int current_len, int start_index) {
            if (current_len == len) {
                vector<int> subsequence;
                for (int index : indices) {
                    subsequence.push_back(a[index]);
                }
                if (is_beautiful(subsequence)) {
                    beautiful_count = (beautiful_count + 1) % mod;
                }
                return;
            }
            if (start_index >= n) {
                return;
            }
            for (int i = start_index; i < n; ++i) {
                indices[current_len] = i;
                generate_combinations(current_len + 1, i + 1);
            }
        };
        generate_combinations(0, 0);
    }

    return beautiful_count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}