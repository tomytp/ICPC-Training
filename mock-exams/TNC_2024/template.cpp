#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long max_field_trip_score(int N, int M, const vector<vector<int>>& grid) {
    vector<long long> DP(9 * N + 1, 0);
    
    for (int i = N - 1; i >= 0; --i) {
        vector<long long> new_DP(9 * N + 1, 0);
        vector<int> suffix_max(M + 1, 0);
        
        for (int j = M - 1; j >= 0; --j) {
            suffix_max[j] = max(suffix_max[j + 1], grid[i][j]);
        }
        
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k <= 9 * N; ++k) {
                if (DP[k] > 0 || k == 0) {
                    int new_score = k + grid[i][j];
                    long long bob_score = DP[k] + suffix_max[j + 1];
                    new_DP[new_score] = max(new_DP[new_score], bob_score);
                }
            }
        }
        
        DP = move(new_DP);
    }
    
    long long max_score = 0;
    for (int k = 0; k <= 9 * N; ++k) {
        max_score = max(max_score, (long long)k * DP[k]);
    }
    
    return max_score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    
    cout << max_field_trip_score(N, M, grid) << endl;
    
    return 0;
}