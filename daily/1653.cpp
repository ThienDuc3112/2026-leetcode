#include "../common_header.hpp"

class Solution {
public:
  int minimumDeletions(string s) {
    int l = s.size();
    vector<int> aAfter(l, 0), bBefore(l, 0);
    for (int i = 0; i < l - 1; i++) {
      if (s[i] == 'a')
        bBefore[i + 1] = bBefore[i];
      else
        bBefore[i + 1] = bBefore[i] + 1;
      if (s[l - i - 1] == 'a')
        aAfter[l - 2 - i] = aAfter[l - i - 1] + 1;
      else
        aAfter[l - 2 - i] = aAfter[l - i - 1];
    }

    int res = l;
    for (int i = 0; i < l; i++)
      res = min(res, aAfter[i] + bBefore[i]);

    return res;
  }
};
