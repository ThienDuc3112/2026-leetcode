#include "../common_header.hpp"

class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    unordered_set<int> s;
    for (int n : nums)
      s.insert(n);

    if (s.find(original) == s.end())
      return original;

    while (s.find(original *= 2) != s.end())
      ;

    return original;
  }
};
