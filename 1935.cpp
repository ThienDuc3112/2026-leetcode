#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    int res = 0;

    unordered_set<char> brokenLettersSet;
    for (char c : brokenLettersSet)
      brokenLettersSet.insert(c);

    bool last_char_is_white_space = false;
    bool has_letter = false;

    for (char c : text) {
      if (brokenLettersSet.find(c) != brokenLettersSet.end()) {
        has_letter = true;
      }
      if (c != ' ') {
        last_char_is_white_space = false;
      } else {
        if (!has_letter && !last_char_is_white_space)
          res++;
        has_letter = false;
        last_char_is_white_space = true;
      }
    }
    if (!has_letter && !last_char_is_white_space)
      res++;
    return res;
  }
};
