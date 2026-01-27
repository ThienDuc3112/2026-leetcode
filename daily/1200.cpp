#include "../common_header.hpp"

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); i++) {
      if (res.size() == 0) {
        res.push_back({arr[i - 1], arr[i]});
        continue;
      }
      int diff = arr[i] - arr[i - 1];
      int lastDiff = res[res.size() - 1][1] - res[res.size() - 1][0];
      cout << "diff: " << diff << " lastDiff: " << lastDiff << endl;
      if (diff == lastDiff) {
        res.push_back({arr[i - 1], arr[i]});
      } else if (diff < lastDiff) {
        res.clear();
        res.push_back({arr[i - 1], arr[i]});
      }
    }
    return res;
  }
};
