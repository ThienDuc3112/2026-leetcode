#include "../common_header.hpp"

struct Item {
  long long dis;
  vector<int> item;
};

struct ItemCmp {
  bool operator()(const Item &a, const Item &b) { return a.dis > b.dis; }
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<Item, vector<Item>, ItemCmp> test;
    for (vector<int> &p : points) {
      int x = p[0], y = p[1];
      test.push({x * x + y * y, p});
      if (test.size() > k)
        test.pop();
    }
    vector<vector<int>> res;
    while (!test.empty()) {
      res.push_back(test.top().item);
      test.pop();
    }
    return res;
  }
};
