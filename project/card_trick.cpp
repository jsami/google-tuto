// card_trick.cpp, Sami Ramahasindry
// Number version of a card trick

#include <iostream>
#include <string>
using namespace std;

#define NUMBER_OF_DIGITS  3

const char REMAINDER_NAMES[3] = {'X', 'Y', 'Z'};


int GetInput() {
  int input;
  cout << "Input 3 digits number: "; cin >> input;
  return input;
}

int Rotate(int input) {
  int firstDigit = input / 100;
  return (input % 100) * 10 + firstDigit;
}

void PopulateRemainders(int* remainders, int input) {
  for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
    remainders[i] = input % 11;
    cout << "remainder of " << input << " : " << REMAINDER_NAMES[i] << " = " << remainders[i] << endl;
    input = Rotate(input);
  }
  cout << "------------------------" << endl;
}

void Half(int& n) {
  n /= 2;
  cout << "Half it: " << n << endl;
  cout << "------------------------" << endl;
}

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
  int sums[NUMBER_OF_DIGITS];
  int sum_idx = 0;
  for (int i = 0; i < NUMBER_OF_DIGITS - 1; i++) {
    for (int j = i + 1; j < NUMBER_OF_DIGITS; j++) {
      sums[sum_idx] = remainders[i] + remainders[j];
      cout << REMAINDER_NAMES[i] << "+" << REMAINDER_NAMES[j] << " = " << sums[sum_idx] << endl;
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
  int remainders[NUMBER_OF_DIGITS];
  PopulateRemainders(remainders, input);
  SumRemaindersThenHalf(remainders);
  return 0;
}