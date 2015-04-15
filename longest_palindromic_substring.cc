#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.length() < 2) {
      return true;
    } else {
      int forward = 0;
      int backward = s.length() - 1;
      while (forward < backward) {
        if (s[forward] == s[backward]) {
          forward++;
          backward--;
        } else {
          return false;
        }
      }
      return true;
    }
  }

  string longestPal(string s) {
    if (s.length() < 2) {
      return s;
    }

    int len = s.length();

    while (len > 0) {
      for (int i = 0; i <= s.length()-len; i++) {
        if (isPalindrome(s.substr(i, len))) {
          return s.substr(i, len);
        }
      }
      len--;
    }
    return s;
  }

  string longestPalindrome(string s) {
    if (s.length() < 2) {
      return s;
    }
    int size = s.length();
    //vector<vector<bool> > table(size, vector<bool>(size, false));
    bool table[1000][1000] = {false};

    int maxlen = 1;
    int maxstart = 0;
    for (int i = 0; i < size; i++) {
      table[i][i] = true;
    }
    for (int i = 0; i < size-1; i++) {
      if (s[i] == s[i+1]) {
        table[i][i+1] = true;
        maxlen = 2;
        maxstart = i;
      }
    }
    for (int len = 3; len <= size; len++) {
      for (int i = 0; i <= size-len; i++) {
        if (s[i] == s[i+len-1] && table[i+1][i+len-2]) {
          table[i][i+len-1] = true;
          maxlen = len;
          maxstart = i;
        }
      }
    }
    return s.substr(maxstart, maxlen);
  }
};

int main() {
  Solution s;
  string str = "cwziydanrqvsdtvnnqgjnbrvvwxwqojeqgxhwxdoktjktulemwpbeqscbbtbfvkxsrjetfdrovcrdwzfmnnihtgxybuairswfewvpuscocqifuwylhssldpjrawqdrbvkykpaggspbfrulcktpbofchzikhzxhpocgvdbwpewpywsgqbczmamprklaoovcfecwchhmsaqkhvuvvzjblmgvqpqtnlipgqsanvovylpmxlmxvymppdykphhaamtxjnnlsqfwjwhyywgurteaummwhvavxbcpgrfffxrowluqmqjaugryxdmwvyokdcfcvcytxpixbvwrdgzctejdoaavgtezexmvxgrkpnayvfarkyoruofqmpnsqdzojxqrjsnfwsbzjmaoigytygukqlrcqaxazvmytgfghdczvzphfdbnxtklaiqqsotavdmhiaermluafheowcobjqmrkmlzyas";//"abcbabsleinceaabbcbbaa";
  cout << "Longest palindromic substring is: " << s.longestPalindrome(str) << endl;
  return 0;
}