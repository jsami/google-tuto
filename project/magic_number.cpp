#include <iostream>
#include <string>
using namespace std;

int Reverse(int input) {
  int first = input / 100;
  int second = (input % 100) / 10;
  int last = (input % 100) % 10;
  return last * 100 + second * 10 + first;
}

int main() {
  int input, sub, reverse1, reverse2; 
  cout << "input number: "; cin >> input;
  cout << "reverse it: " << (reverse1 = Reverse(input)) << endl;
  cout << "substract: " << input << " - " << reverse1 << " = " << (sub = input - reverse1) << endl;
  cout << "reverse it: " << (reverse2 = Reverse(sub)) << endl;
  cout << "add: " << reverse2 << " + " << sub << " = " << reverse2 + sub << endl;
  return 0;
}