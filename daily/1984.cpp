#include "../common_header.hpp"

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    if (k <= 1)
      return 0;
    sort(nums.begin(), nums.end());
    int res = nums[nums.size() - 1];
    for (int i = 0; i + k - 1 < nums.size(); i++) {
      res = min(abs(nums[i + k - 1] - nums[i]), res);
    }
    return res;
  }
};
