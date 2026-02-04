#include "../common_header.hpp"

class Solution {
public:
  bool isTrionic(vector<int> &nums) {
    int change = 0;
    bool increasing = true;
    if (nums[1] <= nums[0])
      return false;
    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1])
        return false;
      bool curdir = nums[i] > nums[i - 1];
      if (increasing == curdir)
        continue;
      increasing = !increasing;
      if (++change > 2)
        return false;
    }
    return true;
  }
};
