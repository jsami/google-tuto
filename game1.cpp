// game1.cpp, Sami Ramahasindry
// Secret number guessing

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int kSuccess = 1;
const int kFailure = 0;

int GenerateRandom(int min, int max) {
  srand(time(NULL));
  return rand() % max + min;
}

// Get input from user
int TryGetInput(int& input) {
  cout << "Guess a number: ";
  if (!(cin >> input)) {
    cout << "You entered a non-numeric." << endl;
    cin.clear();
    cin.ignore(50, '\n');
    return kFailure;
  }
  return kSuccess;
}

// Check input against secret
bool CheckInput(int input, int secret) {
  if (input > secret) {
    cout << "Too high." << endl;
    return false;
  }
  else if (input < secret) {
    cout << "Too low." << endl;
    return false;
  }
  cout << "You got it!!" << endl;
  return true;
}

// execute main loop
int main() {
  int secret = GenerateRandom(0, 100);
  int input, attempt = 1;
  while(TryGetInput(input) == kFailure || !CheckInput(input, secret)) {
    attempt++;
  }
  cout << "Number of attempts: " << attempt << endl;
  return 0;
}