#include "../common_header.hpp"

class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    unordered_map<int, int> m;
    for (vector<int> p : points)
      m[p[1]]++;

    // Solve with hint from discussion tab for the final calculation
    // long long sum = 0;
    // long long sumOfSquared = 0;
    // for (auto [k, v] : m)
    //   if (v > 1) {
    //     long long cur = (long long)v * (v - 1) / 2;
    //     sum += cur;
    //     sumOfSquared += cur * cur;
    //   }
    //
    long long MOD = 1e9 + 7;
    // long long res = ((sum * sum - sumOfSquared) / 2) % MOD;

    // Even quicker method with editorial
    long long res = 0;
    long long curSum = 0;
    for (auto [k, v] : m) {
      if (v > 1) {
        long long cur = (long long)v * (v - 1) / 2;
        res += cur * curSum;
        curSum += cur;
      }
    }

    return res % MOD;
  }
};
