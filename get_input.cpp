// get_input.cpp, Sami Ramahasindry
// Description: Illustrate the use of cin to get input.

#include <iostream>
using namespace std;

#define kSuccess = 1;
#define kFailure = 0;

int TryGetInput(int& input) {
  cout << "Enter a number (-1 = quit): ";
  if (!(cin >> input)) {
    cout << "You entered a non-numeric." << endl;
    // recover from error
    cin.clear();  // set iostate flag to goodbit
    cin.ignore(50, '\n'); // discard up to 50 charcters until '\n' is met
    return kFailure;
  }
  return kSuccess;
}

int main() {
  int input_var = 0;
  do {
    if(TryGetInput(input_var) == kFailure)
      continue;
    if (input_var != -1) {
      cout << "You entered " << input_var << endl;
    }
  } while (input_var != -1);
  cout << "All done." << endl;
  return 0;
}