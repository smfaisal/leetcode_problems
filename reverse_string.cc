#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
	public:
	 void reverseWords(string &s) {
		if (!s.empty()) {
			// Get rid of trailing spaces
			int sp_ind = s.size() - 1;
			while (s[sp_ind] == ' ') {
				--sp_ind;
			}
			if (sp_ind < s.size() - 1) {
				s.erase(sp_ind+1);
			}

			unsigned last_space = s.rfind(" ");
			if (last_space != std::string::npos) {
				int i;
				int end = last_space-1;
				for (i = last_space-1; i >= 0; i--) {
					if (s[i] == ' ') {
						if (i + 1 <= end) {
							s.append(" " + s.substr(i+1, end - i));
						}
						end = i-1;
					}
				}
				if (i < end) {
					s.append(" " + s.substr(i+1, end - i));
				}
				s.erase(0, last_space+1);
			}	
	 	}
	}
};

int main() {
	Solution s;
	string str = "  a  b  "; //"1 ";//"The Sky Is Blue";
	s.reverseWords(str);
	cout << "<<<" << str << ">>>" << endl;
}
