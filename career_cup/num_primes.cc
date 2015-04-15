#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
  if (n==2 || n==3) {
    return true;
  }
  if (n%2 == 0 || n%3 == 0) {
    return false;
  }
  int d = 5;
  for (int i = 1; ; i++) {
    d = 6*i-1;
    if (d > sqrt(n)) {
      break;
    }
    if (n%d == 0) {
      return false;
    }
    d+=2;
    if (d > sqrt(n)) {
      break;
    }
    if (n%d == 0) {
      return false;
    }
  }
  return true;
}
/*
 * Complete the function below.
 */
int getNumberOfPrimes(int N) {
  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (isprime(i)) {
      count++;
    }
  }
  return count;
}

int main() {
  cout << "Primes: " << getNumberOfPrimes(100) << endl;
  return 0;
}