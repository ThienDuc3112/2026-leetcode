#include "../common_header.hpp"

// Use 2 ordered set
class Solution {
public:
  vector<long long> findXSum(vector<int> &nums, int k, int x) {
    vector<long long> res;
    int head = 0;
    unordered_map<int, int> count;
    set<pair<long long, int>, greater<pair<long long, int>>> top, bottom;
    long long windowedSum = 0;

    for (int i = 0; i < nums.size(); i++) {
      // cout << "======================================" << endl;
      long long cnt = count[nums[i]]++;

      if (cnt) {
        if (auto it = bottom.find({(long long)cnt, nums[i]});
            it != bottom.end()) {
          bottom.erase(it);
        } else {
          top.erase({cnt, nums[i]});
          windowedSum -= nums[i] * cnt;
          // cout << "windowedSum -= nums[i] * cnt: " << windowedSum << "\n";
        }
      }

      windowedSum += (long long)count[nums[i]] * nums[i];
      // cout << "windowedSum += (long long)count[nums[i]] * nums[i]: "
      //      << windowedSum << "\n";
      top.insert({count[nums[i]], nums[i]});

      if (top.size() > x) {
        auto it_top = prev(top.end());
        windowedSum -= it_top->first * it_top->second;
        // cout << "windowedSum -= it_top->first * it_top->second: " <<
        // windowedSum
        //      << "\n";
        bottom.insert({it_top->first, it_top->second});
        top.erase(it_top);
      }

      if (i >= k) {
        int cnt = count[nums[i - k]];
        if (auto it = bottom.find({cnt, nums[i - k]}); it != bottom.end()) {
          bottom.erase(it);
        } else {
          top.erase({cnt, nums[i - k]});
          windowedSum -= (long long)nums[i - k] * cnt;
          // cout << "windowedSum -= (long long)nums[i-k] * cnt: " <<
          // windowedSum
          //      << "\n";
        }

        if (--count[nums[i - k]] > 0)
          bottom.insert({count[nums[i - k]], nums[i - k]});

        if (auto it = begin(bottom); top.size() < x && it != end(bottom)) {
          windowedSum += it->first * it->second;
          // cout << "windowedSum += it->first * it->second: " << windowedSum
          //      << "\n";
          top.insert({it->first, it->second});
          bottom.erase(it);
        }
      }

      if (i + 1 >= k)
        res.push_back(windowedSum);

      // cout << "windowedSum: " << windowedSum << "\n";
      // cout << "count:\n";
      // for (auto [k, v] : count)
      //   cout << "\tk: " << k << " v: " << v << endl;
      //
      // cout << "top:\n";
      // for (auto [count, value] : top)
      //   cout << "\tcount: " << count << " value: " << value << endl;
      //
      // cout << "bottom:\n";
      // for (auto [count, value] : bottom)
      //   cout << "\tcount: " << count << " value: " << value << endl;
    }
    return res;
  }
};
