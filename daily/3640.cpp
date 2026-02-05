#include "../common_header.hpp"

// I'll do it later
class Solution {
public:
  long long maxSumTrionic(vector<int> &nums) {
    bool increasing = true;
    vector<int> largestEndAt(nums.size(), 0);
    int i = 1;
    long long res = LONG_LONG_MIN;
    while (i < nums.size() && nums[i] <= nums[i - 1])
      i++;
    for (; i < nums.size(); i++) {
      int j = i;
      long long maxSegmentEnd = nums[j];
      long long maxSegment = 0;
      while (j < nums.size() && nums[j] > nums[j - 1]) {
      }
    }

    return res;
  }
};
