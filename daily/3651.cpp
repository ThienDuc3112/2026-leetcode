#include "../common_header.hpp"

// Need editorial
class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> ps;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ps.push_back({i, j});
      }
    }
    sort(ps.begin(), ps.end(), [&](const auto &p1, const auto &p2) -> bool {
      return grid[p1.first][p1.second] < grid[p2.first][p2.second];
    });

    vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
    for (int t = 0; t <= k; t++) {
      int minCost = INT_MAX;
      for (int i = 0, j = 0; i < ps.size(); i++) {
        auto [x, y] = ps[i];
        minCost = min(minCost, costs[x][y]);
        // Skip if next point can tp to (equal value)
        if (i + 1 < ps.size() &&
            grid[ps[i + 1].first][ps[i + 1].second] == grid[x][y])
          continue;

        // Set all points with the same value to the same minCost
        for (; j <= i; j++)
          costs[ps[j].first][ps[j].second] = minCost;
      }

      for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
          if (i == m - 1 && j == n - 1) {
            costs[i][j] = 0;
            continue;
          }
          if (i != m - 1)
            costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
          if (j != n - 1)
            costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
        }
      }

      // for (int i = 0; i < m; i++) {
      //   for (int j = 0; j < n; j++) {
      //     cout << costs[i][j] << ", ";
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
    return costs[0][0];
  }
};

// TLE
// class Solution {
// public:
//   int minCost(vector<vector<int>> &grid, int k) {
//     int a = grid.size(), b = grid[0].size();
//     map<int, vector<pair<int, int>>> l;
//
//     for (int i = 0; i < a; i++)
//       for (int j = 0; j < b; j++) {
//         int s = grid[i][j];
//         if (l.find(s) == l.end())
//           l[s] = {{i, j}};
//         else
//           l[s].push_back({i, j});
//       }
//
//     vector<vector<int>> heuristic(a);
//     for (int i = a - 1; i >= 0; i--) {
//       heuristic[i] = vector<int>(b);
//       for (int j = b - 1; j >= 0; j--) {
//         if (i == a - 1 && j == b - 1)
//           heuristic[i][j] = 0;
//         else if (i == a - 1)
//           heuristic[i][j] = heuristic[i][j + 1] + grid[i][j + 1];
//         else if (j == b - 1)
//           heuristic[i][j] = heuristic[i + 1][j] + grid[i + 1][j];
//         else
//           heuristic[i][j] = min(heuristic[i][j + 1] + grid[i][j + 1],
//                                 heuristic[i + 1][j] + grid[i + 1][j]);
//       }
//     }
//
//     // {row, col, k}
//     set<tuple<int, int, int>> visisted;
//     // {dist, k, row, col}
//     priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int,
//     int>>,
//                    greater<tuple<int, int, int, int>>>
//         q;
//     q.push({0, -k, 0, 0});
//
//     int res = heuristic[0][0];
//     while (!q.empty()) {
//       auto [dist, kRemain, i, j] = q.top();
//       q.pop();
//       if (visisted.find({i, j, kRemain}) != visisted.end())
//         continue;
//       cout << " dist = " << dist << " kRemain = " << kRemain << " i = " << i
//            << " j: " << j << " visisted.size = " << visisted.size() << endl;
//       if (i == a - 1 && j == b - 1)
//         return dist;
//
//       visisted.insert({i, j, kRemain});
//
//       if (kRemain == 0)
//         q.push({dist + heuristic[i][j], 0, a - 1, b - 1});
//       else {
//         if (i + 1 < a)
//           q.push({dist + grid[i + 1][j], kRemain, i + 1, j});
//         if (j + 1 < b)
//           q.push({dist + grid[i][j + 1], kRemain, i, j + 1});
//         auto end = l.upper_bound(grid[i][j]);
//         for (auto it = l.begin(); it != end; it++) {
//           for (auto [x, y] : it->second)
//             q.push({dist, kRemain + 1, x, y});
//         }
//       }
//     }
//     return -1;
//   }
// };
