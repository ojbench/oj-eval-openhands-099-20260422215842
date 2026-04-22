// Problem 099 - 捕鱼达人 (ACMOJ 2454)
// Compute the maximum sum of fish in any connected component of positive cells
// using BFS over 4-directional neighbors.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<char>> vis(m, vector<char>(n, 0));
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    long long best = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > 0 && !vis[i][j]) {
                long long sum = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    pair<int,int> cur = q.front();
                    q.pop();
                    int x = cur.first, y = cur.second;
                    sum += a[x][y];
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] > 0 && !vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
                if (sum > best) best = sum;
            }
        }
    }

    cout << best << '\n';
    return 0;
}
