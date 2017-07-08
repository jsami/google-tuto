#include <iostream>
using namespace std;

void Print4Hellos() {
  cout.flags(ios::left);
  for (int j = 0; j < 4; j++) {
    cout.width(17);
    cout << "Hello, World!";
  }
  cout << endl;
}

int main() {
  for (int i = 0; i < 6; i ++) {
    Print4Hellos();
  }
  return 0;
}