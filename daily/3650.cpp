#include "../common_header.hpp"

// Dijkstra
class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    unordered_map<int, unordered_map<int, int>> graph;
    for (int i = 0; i < n; i++)
      graph[i] = {};

    for (vector<int> &edge : edges) {
      if (graph[edge[0]].find(edge[1]) == graph[edge[0]].end())
        graph[edge[0]][edge[1]] = edge[2];
      else
        graph[edge[0]][edge[1]] = min(edge[2], graph[edge[0]][edge[1]]);

      if (graph[edge[1]].find(edge[0]) == graph[edge[1]].end())
        graph[edge[1]][edge[0]] = edge[2] * 2;
      else
        graph[edge[1]][edge[0]] = min(edge[2] * 2, graph[edge[1]][edge[0]]);
    }

    unordered_map<int, int> visisted;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    q.push({0, 0});

    while (!q.empty()) {
      auto [dist, dest] = q.top();
      // cout << "dist: " << dist << " dest: " << dest << endl;
      if (dest == n - 1)
        return dist;
      q.pop();
      if (visisted.find(dest) != visisted.end() && visisted[dest] <= dist)
        continue;

      visisted[dest] = dist;
      for (auto [nextDest, w] : graph[dest])
        q.push({dist + w, nextDest});
    }
    return -1;
  }
};
