class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    long newNum = num1;
    int res = 0;
    while (newNum > 0 && res <= 60) {
      //   cout << res << " newNum: " << newNum << " bit count: " <<
      //   countBit(newNum) << endl;
      if (res >= countBit(newNum) && res <= newNum)
        return res;
      newNum -= num2;
      res++;
    }
    return -1;
  }

  int countBit(long n) {
    int c = 0;
    for (; n; ++c)
      n &= n - 1;
    return c;
  }
};
