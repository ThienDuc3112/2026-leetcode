#include "../common_header.hpp"

class Solution {
public:
  int minimumCost(vector<int> &nums) {
    int a = INT_MAX, b = INT_MAX;
    for (int i = 1; i < nums.size(); i++) {
      int x = nums[i];
      if (x <= a) {
        b = a;
        a = x;
      } else if (x < b)
        b = x;
    }

    return nums[0] + a + b;
  }
};
