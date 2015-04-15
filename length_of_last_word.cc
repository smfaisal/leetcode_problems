#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int len = 0;
    if (!s) {
      return len;
    }
    int i;
    int str_len = strlen(s);
    for (i = str_len-1; i >= 0; i--) {
      if (s[i] != ' ')
        break;
    }
    bool found_space = false;
    while (i >= 0) {
      if (s[i] == ' ') {
        break;
      }
      len++;
      i--;
    }

    return len;
  }
};

int main() {
  Solution s;
  cout << "Last word length: " << s.lengthOfLastWord("Hello World  ") << endl;
  return 0;
}