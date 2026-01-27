class Solution {
public:
  int minimumOneBitOperations(int n) {
    int mask = 1;
    int k = 0;
    int ans = 0;
    while (mask <= n) {
      if (mask & n)
        ans = (2 << k) - 1 - ans;
      mask <<= 1;
      k++;
    }
    return ans;
  }
};
