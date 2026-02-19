#include "../common_header.hpp"

class Solution {
public:
  int longestBalanced(string s) {
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
      unordered_map<char, int> count;
      count[s[i]]++;
      for (int j = i + 1; j < s.size(); j++) {
      }
    }
    return res;
  }
};
