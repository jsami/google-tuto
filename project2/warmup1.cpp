// warmup1.cpp, Sami Ramahasindry
// Find the next number that is a perfect square and also the sum of a series 1...n

#include <iostream>
#include <cmath>
using namespace std;

#define kBiggestWeKnow    1225

int SeriesSum(int n) {
  return n * (n + 1) / 2;
}

bool IsSeriesSumAndPerfectSquare(int n) {
  int root = (int)round((sqrt(n)));
  bool is_perfect_square = n == root * root;
  for (int i = 1; i < 2 * root; i++) {
    if (SeriesSum(i) == n && is_perfect_square) {
      cout << "Sum of serie from 1 to " << i << endl;
      cout << "Square of " << root << endl;
      k
      return true;
    }
  }
  return false;
}

int main() {
  int n = kBiggestWeKnow + 1;
  while (!(IsSeriesSumAndPerfectSquare(n))) {
    n++;
  }
  cout << "The next number is: " << n << endl;
  return 0;
}