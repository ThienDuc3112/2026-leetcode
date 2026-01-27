#include "./common_header.hpp"

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    if (nums.size() <= 1)
      return 0;
    vector<int> copied = nums;
    int res = 0;
    while (copied.size() > 1) {
      bool sorted = true;

      int a, min = copied[0] + copied[1];
      for (int i = 1; i < copied.size(); i++) {
        if (copied[i - 1] > copied[i])
          sorted = false;
        int sum = copied[i - 1] + copied[i];
        if (sum < min) {
          min = sum;
          a = i;
        }
      }

      if (sorted)
        break;
      cout << "a: " << a << " min: " << min << endl;
      res++;
      copied[a - 1] = min;
      for (int i = a; i < copied.size() - 1; i++)
        copied[a] = copied[a + 1];
      copied.pop_back();
      for (int i : copied)
        cout << i << ", ";
      cout << endl;
    }
    return res;
  }
};
