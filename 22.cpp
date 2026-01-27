#include "common_header.hpp"
#include <vector>

class Solution {
public:
  vector<string> fn(int open, int close) {
    if (open < 0 || close < 0 || open > close)
      return {};

    if (open == 0) {
      string res = "";
      for (int i = 0; i < close; i++)
        res += ")";
      return {res};
    }

    if (open == close) {
      vector<string> ans = fn(open - 1, close);
      for (int i = 0; i < ans.size(); i++)
        ans[i] = "(" + ans[i];
      return ans;
    }

    vector<string> o = fn(open - 1, close);
    for (int i = 0; i < o.size(); i++)
      o[i] = "(" + o[i];
    vector<string> c = fn(open, close - 1);
    for (int i = 0; i < c.size(); i++)
      c[i] = ")" + c[i];
    o.insert(o.end(), c.begin(), c.end());
    return o;
  }
  vector<string> generateParenthesis(int n) { return fn(n, n); }
};
