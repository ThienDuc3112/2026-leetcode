#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> seen;
    for (int num : nums) {
      if (seen.find(num) == seen.end())
        seen[num] = 0;
      seen[num]++;
    }

    int count = 0;
    int res = nums[0];
    for (auto &[k, v] : seen) {
      cout << "k: " << k << " v: " << v << endl;
      if (v > count) {
        res = v;
        count = v;
      } else if (v == count) {
        res += v;
      }
    }

    return res;
  }
};
