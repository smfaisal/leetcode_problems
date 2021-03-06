#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
	void dfs (string& s, int st, vector<int>& sp, vector<string>& res, 
						unordered_set<string>& dict, vector<vector<bool> >& mp) {
		if (st >= s.size()) {
			string str = s;
			for (int i = 0; i < sp.size()-1; i++) {
				str.insert(sp[i]+i, " ");
			}
			res.push_back(str);
		} else {
			for (int j = 0; j < mp[st].size(); j++) {
				if (mp[st][j] == true) {
					sp.push_back(j+1);
					dfs(s, j+1, sp, res, dict, mp);
					sp.pop_back();
				}
			}
		}
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<vector<bool> > mp (s.size(), vector<bool>(s.size(), false));
		for (int i = 0; i < s.size(); i++) {
			for (int j = i; j < s.size(); j++) {
				if (dict.find(s.substr(i, j-i+1)) != dict.end()) {
					mp[i][j] = true;
				}
			}
		}

		vector<string> res;
		vector<int> sp;

		dfs(s, 0, sp, res, dict, mp);

		return res;
 	}
};

int main() {
	Solution s;
	unordered_set<string> dict; 
	dict.insert ("cat");
	dict.insert ("cats");
	dict.insert ("and");
	dict.insert ("sand");
	dict.insert ("dogs");
	string str = "catsanddogs";
	vector<string> res = s.wordBreak(str, dict);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}
}
