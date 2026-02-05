#include "../common_header.hpp"

class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      int newIdx = (nums.size() + i + nums[i]);
      while (newIdx < 0)
        newIdx += nums.size();
      newIdx %= nums.size();
      res[i] = nums[newIdx];
    }
    return res;
  }
};
