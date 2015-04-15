#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = 1;
    int max = 0;
    int start = 0;
    if (s.length() < 2) {
      return s.length();
    }
    map<char, bool> mp;
    for (int i = 0; i < s.length(); i++) {
      if (mp[s[i]] == false) {
        mp[s[i]] = true;
      } else {
        len = i - start;
        if (len > max) {
          max = len;
        }
        while (s[start] != s[i]) {
          mp[s[start]] = false;
          start++;
        }
        start++;
      }
    }
    len = s.length() - start;
    if (len > max) {
      max = len;
    }
    return max;
  }
};

int main() {
  Solution s;
  string str = "qopubjguxhxdipfzwswybgfylqvjzhar";//"wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
  cout << "Max len without repeating: " << s.lengthOfLongestSubstring(str) << endl;
}