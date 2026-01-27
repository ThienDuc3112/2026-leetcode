#include "../common_header.hpp"

struct QueueItem {
  int value = 0, count = 0;
};

struct MinPrio {
  bool operator()(const QueueItem &a, const QueueItem &b) const {
    return a.count > b.count || (a.count == b.count && a.value > b.value);
  }
};

class Solution {
public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    vector<int> res;
    int head = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); i++) {
      // cout << "Loop: " << i << endl;
      count[nums[i]]++;
      if (i - head >= k) {
        count[nums[head++]]--;
      }

      if (i - head == k - 1) {
        priority_queue<QueueItem, vector<QueueItem>, MinPrio> pq;
        // cout << "\t" << "pq contents:" << endl;
        for (auto [k, v] : count) {
          if (v == 0)
            continue;
          // cout << "\t\t" << "k: " << k << " v: " << v << endl;
          pq.push({k, v});
          if (pq.size() > x)
            pq.pop();
        }
        int cur_res = 0;
        // cout << "\t" << "remains: " << endl;
        while (pq.size() > 0) {
          // cout << "\t\t" << "value: " << pq.top().value
          //      << " count: " << pq.top().count << endl;
          cur_res += pq.top().count * pq.top().value;
          pq.pop();
        }

        res.push_back(cur_res);
      }
    }
    return res;
  }
};
