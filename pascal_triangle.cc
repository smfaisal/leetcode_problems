#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
		vector<int> row;
		vector<vector<int> > res;
		if (numRows == 0) {
			return res;
		}
		row.push_back(1);
		res.push_back(row);
		if (numRows == 1) {
			return res;
		}

		row.push_back(1);
		res.push_back(row);
	
		if (numRows == 2) {
			return res;
		}
		
		for (int nrow = 3; nrow <= numRows; nrow++) {
			vector<int> newrow;
			newrow.push_back(1);
			for (int tmp = 1; tmp < row.size(); tmp++) {
				newrow.push_back(row[tmp-1]+row[tmp]);
			}
			newrow.push_back(1);
			res.push_back(newrow);
			row = newrow;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<vector<int> > res;

	res = s.generate(8);

	for (vector<int> v : res) {
		for (int i : v) {
			cout << i << ", ";
		}
		cout << endl;
	}
	return 0;
}
