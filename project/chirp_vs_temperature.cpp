// chirp_vs_temperature.cpp, Sami Ramahasindry
// calculate temperature in funciton of the chirps per minute

#include <iostream>
using namespace std;

int main() {
  int chirpsPerMinute;
  cout << "Number of chirps: "; cin >> chirpsPerMinute;
  double temperature = (chirpsPerMinute + 40.) / 4;
  cout << "The temperature is: " << temperature << endl;
  return 0;
}