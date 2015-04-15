#include <iostream>
#include <functional>

using namespace std;

int main() {
  hash<string> str_hash;

  cout << "Hash of 5 is: " << str_hash("5") << endl;
  cout << "Hash of 15 is: " << hash<string>()("15") << endl;
  cout << "Hash of 25 is: " << str_hash("25") << endl;

  return 0;
}