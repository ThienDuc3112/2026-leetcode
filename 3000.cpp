#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int res = 0;
    int max_val = -1;
    for (auto d : dimensions) {
      int cur = (d[0] * d[0] + d[1] * d[1]);
      if (cur >= max_val) {
        res = cur == max_val ? max(d[0] * d[1], res) : d[0] * d[1];
      }
    }

    return res;
  }
};
