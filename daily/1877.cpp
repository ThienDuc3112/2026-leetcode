#include "../common_header.hpp"

class Solution {
public:
  int minPairSum(vector<int> &nums) {
    int count[100001]{};
    for (int n : nums)
      count[n]++;

    int res = 0;
    int left = 1, right = 1e5;
    for (int i = 0; i < nums.size() / 2; i++) {
      while (count[left] <= 0)
        left++;
      while (count[right] <= 0)
        right--;
      res = max(res, left + right);
      count[left]--;
      count[right]--;
    }
    return res;
  }
};

// class Solution {
// public:
//   int minPairSum(vector<int> &nums) {
//     sort(nums.begin(), nums.end());
//     int res = 0;
//     for (int i = 0; i < nums.size() / 2; i++)
//       res = max(res, nums[i] + nums[nums.size() - 1 - i]);
//     return res;
//   }
// };
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
