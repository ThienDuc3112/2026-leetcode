#include "../common_header.hpp"

// After checking editorial
// NOTE: multiset.erase erase ALL instances,
// ALWAYS USE .erase(ms.find(x)), NOT .erase(x)
class Container {
public:
  Container(int k) : k(k), s(0) {};

  long long sum() { return s; }

  void add(int x) {
    if (!high.empty() && x >= (*high.begin())) {
      high.insert(x);
    } else {
      low.insert(x);
      s += x;
    }
    adjust();
  }

  void erase(int x) {
    auto it = low.find(x);
    if (it != low.end()) {
      low.erase(it);
      s -= x;
    } else {
      high.erase(high.find(x));
    }
    adjust();
  }

private:
  int k;
  multiset<int> low, high;
  long long s;

  void adjust() {
    while (low.size() > k) {
      int x = *prev(low.end());
      high.emplace(x);
      low.erase(prev(low.end()));
      s -= x;
    }

    while (low.size() < k && high.size() > 0) {
      int x = *high.begin();
      low.emplace(x);
      high.erase(high.begin());
      s += x;
    }
  }
};

class Solution {
public:
  long long minimumCost(vector<int> &nums, int k, int dist) {
    Container count(k - 1);
    int head = 1;
    long long res = LONG_LONG_MAX;
    for (int tail = 1; tail < nums.size(); tail++) {
      count.add(nums[tail]);
      if (tail - head > dist)
        count.erase(nums[head++]);
      if (tail - head == dist)
        res = min(res, count.sum());
    }
    return res + nums[0];
  }
};
