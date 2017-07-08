#include <iostream>
using namespace std;

// How many ways can you arrange 6 different books, left to right, on a shelf?
// We already know that it will be the number of permuations of the 6 books, thus 6! = 720 arrangements
//-------------------------------
int factorial(int n) {
  int combinations = 1;
  for(int i = 1; i <= n; i++) {
    combinations *= i;
  }
  return combinations;
}

int main() {
  int n = 6;
  cout << factorial(n) << " ways to arrange "<< n << " books" << endl;
  return 0;
}
