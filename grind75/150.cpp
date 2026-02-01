#include "../common_header.hpp"

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;

    for (string &token : tokens) {
      if (token == "+") {
        int a2 = s.top();
        s.pop();
        int a1 = s.top();
        s.pop();
        s.push(a1 + a2);
      } else if (token == "-") {
        int a2 = s.top();
        s.pop();
        int a1 = s.top();
        s.pop();
        s.push(a1 - a2);
      } else if (token == "*") {
        int a2 = s.top();
        s.pop();
        int a1 = s.top();
        s.pop();
        s.push(a1 * a2);
      } else if (token == "/") {
        int a2 = s.top();
        s.pop();
        int a1 = s.top();
        s.pop();
        s.push(a1 / a2);
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};
