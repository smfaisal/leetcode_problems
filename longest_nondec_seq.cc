#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lns(const vector<int>& seq) {
	vector<int> counter;

	for (int i = 0; i < seq.size(); i++) {
		counter.push_back(1);
	}

	for (int i = 1; i < seq.size(); i++) {
		if (seq[i] > seq[i-1]) {
			counter[i] += counter[i-1];
		}
	}
	int max = -1;
	for (int i = 0; i < counter.size(); i++) {
		if (counter[i] > max) {
			max = counter[i];
		}
	}

	return max;
}

int main() {
	int arr[] = {1, 5, 6, 7, 8, 5, 1, 2, 3, 4, 5, 6, 7, 1, 3, 1};
	vector<int> seq (arr, arr+15);
	cout << "Longest seq: " << lns(seq) << endl;
}
