#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    char prev = ' ';
    int cur_max = 0;
    int res = 0;
    for (int i = 0; i < neededTime.size(); i++) {
      if (prev == colors[i]) {
        res += min(cur_max, neededTime[i]);
        cur_max = max(cur_max, neededTime[i]);
      } else {
        prev = colors[i];
        cur_max = neededTime[i];
      }
    }

    return res;
  }
};
