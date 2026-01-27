#include "../common_header.hpp"
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.size() == 0)
      return {newInterval};
    vector<vector<int>> res;
    bool inserted = false;
    for (vector<int> &toInsert : intervals) {
      if (res.size() == 0) {
        if (toInsert[0] < newInterval[0])
          res.push_back(toInsert);
        else {
          res.push_back(newInterval);
          newInterval = toInsert;
        }
        continue;
      }

      if (toInsert[0] > newInterval[0]) {
        vector<int> temp = newInterval;
        newInterval = toInsert;
        toInsert = temp;
      }

      // cout << "toInsert: [" << toInsert[0] << ", " << toInsert[1] << "]\n";
      // cout << "newInterval: [" << newInterval[0] << ", " << newInterval[1]
      //      << "]\n";
      // cout << "res.back: [" << res.back()[0] << ", " << res.back()[1] <<
      // "]\n";

      if (toInsert[0] <= res.back()[1]) {
        res.back()[0] = min(res.back()[0], toInsert[0]);
        res.back()[1] = max(res.back()[1], toInsert[1]);
      } else {
        res.push_back(toInsert);
      }
    }

    if (newInterval[0] <= res.back()[1]) {
      res.back()[0] = min(res.back()[0], newInterval[0]);
      res.back()[1] = max(res.back()[1], newInterval[1]);
    } else {
      res.push_back(newInterval);
    }

    return res;
  }
};
