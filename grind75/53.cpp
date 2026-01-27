#include "../common_header.hpp"

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int res = nums[0];
    int last = nums[0];
    for (int i : nums) {
      last = max(i, last + i);
      res = max(last, res);
    }
    return res;
  }
};
