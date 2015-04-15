#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>* t) {
	vector<int>::iterator it = t->begin();
	for (; it != t->end(); it++) {
		cout << *it;
	}
}

int main() {
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	print_vector(&test);
	return 0;
}
