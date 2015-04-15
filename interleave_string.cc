#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {										        
		vector<vector<bool> > A(s1.size()+1, vector<bool>(s2.size()+1, false));
		int n1 = s1.size();
		int n2 = s2.size();
		if (n1+n2 != s3.size()){
			return false;
		}
		A[0][0] = true;
		for (int i = 1; i <= n1; i++) {
			if (s1[i-1] == s3[i-1] && A[i-1][0]) {
				A[i][0] = true;
			}
		}
		for (int i = 1; i <= n2; i++) {
			if (s2[i-1] == s3[i-1] && A[0][i-1]) {
				A[0][i] = true;
			}
		}
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				A[i][j] = (s3[i+j-1] == s1[i-1] && A[i-1][j]) ||
									(s3[i+j-1] == s2[j-1] && A[i][j-1]);
			}
		}
		return A[n1][n2];
	}
};

int main() {
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc"; //"aadbbcbcac"; //"aebfcgdh";

	cout << s3 << " Interleaved with " << s1 << ", " 
			 << s2 << "?: " << s.isInterleave(s1, s2, s3)
			 << endl;
}
