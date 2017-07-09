#include <iostream>
using namespace std;

void accelerate(double& speed, double amount) {
  speed = speed + amount;
}

int main() {
  double speed;
  double acceleration;
  cout << "Current speed: "; cin >> speed;
  cout << "Acceleration: "; cin >> acceleration;
  cout << "-----------------" << endl;
  accelerate(speed, acceleration);
  cout << "New speed: " << speed << endl;
  return 0;
}