#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();

class HopcroftKarp {
private:
    int n, m;
    std::vector<std::vector<int>> graph;
    std::vector<int> matching, dist;
    std::queue<int> q;

    bool bfs() {
        for (int v = 1; v <= n; ++v) {
            if (matching[v] == 0) {
                dist[v] = 0;
                q.push(v);
            } else {
                dist[v] = INF;
            }
        }
        dist[0] = INF;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v != 0) {
                for (int u : graph[v]) {
                    if (dist[matching[u]] == INF) {
                        dist[matching[u]] = dist[v] + 1;
                        q.push(matching[u]);
                    }
                }
            }
        }
        return (dist[0] != INF);
    }

    bool dfs(int v) {
        if (v != 0) {
            for (int u : graph[v]) {
                if (dist[matching[u]] == dist[v] + 1) {
                    if (dfs(matching[u])) {
                        matching[u] = v;
                        matching[v] = u;
                        return true;
                    }
                }
            }
            dist[v] = INF;
            return false;
        }
        return true;
    }

public:
    HopcroftKarp(int n, int m) : n(n), m(m), graph(n + 1), matching(n + m + 1), dist(n + m + 1) {}

    void add_edge(int v, int u) {
        graph[v].push_back(u + n);
    }

    int match() {
        int result = 0;
        while (bfs()) {
            for (int v = 1; v <= n; ++v) {
                if (matching[v] == 0 && dfs(v)) {
                    ++result;
                }
            }
        }
        return result;
    }

    std::vector<int> get_matching() {
        std::vector<int> result(n + 1);
        for (int v = 1; v <= n; ++v) {
            result[v] = matching[v] > n ? matching[v] - n : 0;
        }
        return result;
    }
};

std::pair<int, std::vector<int>> solve(int N, int M, const std::vector<std::vector<int>>& happiness) {
    auto can_achieve_happiness = [&](int target) {
        HopcroftKarp hk(N, M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (happiness[i][j] >= target) {
                    hk.add_edge(i + 1, j + 1);
                }
            }
        }
        return hk.match() == N;
    };

    int left = 1, right = 1e9;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (can_achieve_happiness(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    HopcroftKarp hk(N, M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (happiness[i][j] >= left) {
                hk.add_edge(i + 1, j + 1);
            }
        }
    }
    hk.match();

    return {left, hk.get_matching()};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> happiness(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> happiness[i][j];
        }
    }

    auto [max_min_happiness, food_assignments] = solve(N, M, happiness);

    std::cout << max_min_happiness << '\n';
    for (int i = 1; i <= N; ++i) {
        std::cout << food_assignments[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}