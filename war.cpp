// war.cpp, Sami Ramahasindry
// War game in which we shoot enemy with cannon by adjusting shoot angle

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;

#define kEnemyMaxDistance   1000
#define kEnemyMinDistance   1
#define kMaxCannonBalls     10
#define kGravity            32.2
#define kVelocity           200.0
#define kPi                 3.14159265
#define kMinTolerance       -2
#define kMaxTolerance       2


void StartUp() {
  cout << "Welcome to Artillery." << endl;
  cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
  cout << "You have one cannon, which you can shoot at any angle." << endl;
  cout << "You only have 10 cannonballs for this target.." << endl;
  cout << "Let's begin..." << endl;
}

int GetEnemyDistance() {
  srand(time(NULL));
  return rand() % kEnemyMaxDistance + kEnemyMinDistance;
}

double GetShootAngle() {
  double angle = 0;
  cout << "What angle? "; cin >> angle;
  return angle * kPi / 180;
}

double Shoot(double angle, int target_distance) {
  double time_in_air = (2.0 * kVelocity * sin(angle)) / kGravity;
  int distance = round((kVelocity * cos(angle)) * time_in_air);
  return distance - target_distance;
}

int Fire() {
  int shots = 0;
  int enemy_distance = GetEnemyDistance();
  cout << "The enemy is " << enemy_distance << " feet away!!!" << endl;
  double shoot_angle;
  do {
    shoot_angle = GetShootAngle();
    double shoot_deviation = Shoot(shoot_angle, enemy_distance);
    if (kMinTolerance <= shoot_deviation && kMaxTolerance >= shoot_deviation) {
      cout << "You hit him!!!" << endl;
      cout << "It took " << shots << " shots.";
      return 1;
    }
    else if (shoot_deviation > 0) {
      cout << "You over shot by " << shoot_deviation << endl;
    }
    else {
      cout << "You under shot by " << -shoot_deviation << endl;
    }
    shots++;
  } while (shots <= kMaxCannonBalls);
  cout << "You have used all of your " << kMaxCannonBalls << " cannonballs." << endl;
  return 0;
}

int main() {
  StartUp();
  int killed = 0;
  char done = 'n';
  do {
    killed += Fire();
    cout << "I see another one, care to shoot again? (Y/N) "; cin >> done;
  } while (done != 'n' && done != 'N');
  cout << "You killed " << killed << " of the enemy." << endl;
}