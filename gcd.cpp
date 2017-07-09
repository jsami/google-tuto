// gcd.cpp, Sami Ramahasindry
// Finding GCD of two numbers by Euclidian algorithm

#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

int Gcd(int a, int b) {
  if (a < b) {
    Swap(a, b);
  }
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  int a = 4;
  int b = 96;
  cout << "gcd(" << a << ", " << b << ") = " << Gcd(a, b) << endl;
  return 0;
}