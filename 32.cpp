#include "common_header.hpp"

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> st;
    vector<int> pairing(s.size(), -1);

    for (int i = 0; i < s.size(); i++) {
      bool type = s[i] == '(';
      if (type)
        st.push(i);
      else {
        if (st.size() == 0)
          continue;
        pairing[st.top()] = i;
        pairing[i] = st.top();
        st.pop();
      }
    }

    int res = 0;
    int cur = 0;
    for (int i : pairing) {
      if (i == -1) {
        res = max(res, cur);
        cur = 0;
      } else
        cur++;
    }
    // for (int i : pairing)
    //   cout << i << ", ";
    // cout << endl;
    return max(res, cur);
  }
};
