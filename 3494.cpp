#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    long long res = 0;
    for (int tailIndex = 0; tailIndex < mana.size(); ++tailIndex) {
      int curStep = 0;
      for (int i = 0; i < skill.size(); ++i)
        curStep = max(curStep, skill[i] * mana[tailIndex]);

      res += curStep;
    }

    return res;
  }
};
