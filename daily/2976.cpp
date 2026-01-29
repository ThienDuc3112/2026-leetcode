#include "../common_header.hpp"

class Solution {
public:
  long long minimumCost(string source, string target,
                        const vector<char> &original,
                        const vector<char> &changed, const vector<int> &cost) {
    vector<vector<long long>> graph(26, vector<long long>(26, LONG_LONG_MAX));

    for (int i = 0; i < 26; i++)
      graph[i][i] = 0;

    for (int i = 0; i < cost.size(); i++)
      graph[original[i] - 'a'][changed[i] - 'a'] =
          min((long long)cost[i], graph[original[i] - 'a'][changed[i] - 'a']);

    // All pair shortest path algo
    for (int a = 0; a < 26; a++)
      for (int i = 0; i < 26; i++) {
        if (graph[i][a] == LONG_LONG_MAX)
          continue;
        for (int j = 0; j < 26; j++) {
          if (graph[a][j] == LONG_LONG_MAX)
            continue;
          graph[i][j] = min(graph[i][j], graph[a][j] + graph[i][a]);
        }
      }

    long long res = 0;
    for (int i = 0; i < source.length(); i++) {
      if (source[i] != target[i]) {
        if (graph[source[i] - 'a'][target[i] - 'a'] == LONG_LONG_MAX)
          return -1;
        res += graph[source[i] - 'a'][target[i] - 'a'];
      }
    }
    return res;
  }
};
