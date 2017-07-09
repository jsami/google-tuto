#include <iostream>
#include <string>
using namespace std;

#define   kNumberOfDigits  3

const char kRemainderNames[3] = {'X', 'Y', 'Z'};

int Rotate(int input) {
  int firstDigit = input / 100;
  return (input % 100) * 10 + firstDigit;
}

int main() {
  int input;
  cout << "Input 3 digits number: "; cin >> input;
  // manipulate remainders
  int remainders[kNumberOfDigits];
  for (int i = 0; i < kNumberOfDigits; i++) {
    remainders[i] = input % 11;
    cout << "remainder of " << input << " : " << kRemainderNames[i] << " = " << remainders[i] << endl;
    input = Rotate(input);
  }
  cout << "------------------------" << endl;

  // manipulates sums
  int sums[kNumberOfDigits];
  int sumIndx = 0;
  for (int i = 0; i < kNumberOfDigits-1; i++) {
    for (int j = i + 1; j < kNumberOfDigits; j++) {
      sums[sumIndx] = remainders[i] + remainders[j];
      cout << kRemainderNames[i] << "+" << kRemainderNames[j] << " = " << sums[sumIndx] << endl;
      if (sums[sumIndx] % 2) {
        if (sums[sumIndx] < 9) {
          sums[sumIndx] += 11;
          cout << "sum is odd, increase by 11 => " << sums[sumIndx] << endl;
        }
        else if (sums[sumIndx] > 9) {
          sums[sumIndx] -= 11;
          cout << "sum is odd, decrease by 11 => " << sums[sumIndx] << endl;
        }
        else {
          cout << "No need to increase/decrease by 11 nor halving." << endl;
          continue;
        }
      }
      sums[sumIndx] /= 2;
      cout << "Half it: " << sums[sumIndx] << endl;
      cout << "------------------------" << endl;
      sumIndx++;
    }
  }
  return 0;
}