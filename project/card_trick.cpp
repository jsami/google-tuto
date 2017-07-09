#include <iostream>
#include <string>
using namespace std;

#define   kNumberOfDigits  3

const char kRemainderNames[3] = {'X', 'Y', 'Z'};

int Rotate(int input) {
  int firstDigit = input / 100;
  return (input % 100) * 10 + firstDigit;
}

int GetInput() {
  int input;
  cout << "Input 3 digits number: "; cin >> input;
  return input;
}

void PopulateRemainders(int* remainders, int input) {
  for (int i = 0; i < kNumberOfDigits; i++) {
    remainders[i] = input % 11;
    cout << "remainder of " << input << " : " << kRemainderNames[i] << " = " << remainders[i] << endl;
    input = Rotate(input);
  }
  cout << "------------------------" << endl;
}

void Half(int& n) {
  n /= 2;
  cout << "Half it: " << n << endl;
  cout << "------------------------" << endl;
}

// return true if we hit 9. false otherwise
bool AdjustOdd(int& n) {
  if (!(n % 2))
    return false;
  if (n < 9) {
    n += 11;
    cout << "sum is odd, increase by 11 => " << n << endl;
  }
  else if (n > 9) {
    n -= 11;
    cout << "sum is odd, decrease by 11 => " << n << endl;
  }
  else { // We hit 9
    cout << "No need to increase/decrease by 11 nor halving." << endl;
    return true;
  }
  return false;
}

void SumRemaindersThenHalf(int* remainders) {
  int sums[kNumberOfDigits];
  int sum_idx = 0;
  for (int i = 0; i < kNumberOfDigits - 1; i++) {
    for (int j = i + 1; j < kNumberOfDigits; j++) {
      sums[sum_idx] = remainders[i] + remainders[j];
      cout << kRemainderNames[i] << "+" << kRemainderNames[j] << " = " << sums[sum_idx] << endl;
      bool is_nine = AdjustOdd(sums[sum_idx]);
      if(is_nine)
        continue;
      Half(sums[sum_idx]);
      sum_idx++;
    }
  }
}

int main() {
  int input = GetInput();
  int remainders[kNumberOfDigits];
  PopulateRemainders(remainders, input);
  SumRemaindersThenHalf(remainders);
  return 0;
}