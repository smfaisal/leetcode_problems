#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.size() == 0) {
      return true;
    }
    int st = 0;
    int end = s.size()-1;

    while (st <= end) {
      while (st < s.size() && !isalnum(s[st])) {
        st++;
      }
      while (end >= 0 && !isalnum(s[end])) {
        end--;
      }
      if (tolower(s[st]) == tolower(s[end])) {
        st++;
        end--;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  string str = "A man, a plan, a canal: Panama";

  cout << "Palinedrome? : " << s.isPalindrome(str) << endl;

  return 0;
}

