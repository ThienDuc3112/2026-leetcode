#include "../common_header.hpp"

class Solution {
public:
  int countBinarySubstrings(string s) {
    char lastC = s[0];
    int last = 0;
    int cur = 0;
    int res = 0;
    for (char c : s) {
      if (c == lastC)
        cur++;
      else {
        res += min(last, cur);
        last = cur;
        cur = 1;
        lastC = c;
      }
    }
    res += min(last, cur);
    return res;
  }
};
