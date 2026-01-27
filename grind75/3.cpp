#include "../common_header.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    unordered_set<char> ss;

    int res = 0;
    for (int end = 0; end < s.size(); end++) {
      if (ss.find(s[end]) == ss.end()) {
        ss.insert(s[end]);
        res = max(res, end - start + 1);
        continue;
      }
      while (ss.find(s[end]) != ss.end())
        ss.erase(ss.find(s[start++]));
      ss.insert(s[end]);
      res = max(res, end - start + 1);
    }
    return res;
  }
};
