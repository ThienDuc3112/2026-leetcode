#include "./common_header.hpp"

class MedianFinder {
private:
  set<pair<int, int>, less<pair<int, int>>> top, bottom;
  unordered_map<int, int> count;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (top.size() > bottom.size()) {
    } else {
    }
  }

  double findMedian() {}
};
