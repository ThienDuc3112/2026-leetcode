#include "../common_header.hpp"

class Solution {
private:
  struct less_key {
    inline bool operator()(const vector<int> &a, const vector<int> &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    };
  };

public:
  int intersectionSizeTwo(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), less_key{});
    int ans = 0;
    int lastPick = -1;
    int minPick = -1, maxPick = -1;
    for (vector<int> i : intervals) {
    }
  }
};
