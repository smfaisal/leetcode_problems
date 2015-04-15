#include <iostream>
#include <hash_map>

using namespace std;

int main() {
	hash_map<int, string> hm;
	hm[1] = "one";
	hm[2] = "two";

	cout << hm[1] << hm[2];
}

