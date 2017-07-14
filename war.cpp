// war.cpp, Sami Ramahasindry
// War game in which we shoot enemy with cannon by adjusting shoot angle

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;

#define ENEMY_MAX_DISTANCE   1000
#define ENEMY_MIN_DISTANCE   1
#define MAX_CANNON_BALLS     10
#define GRAVITY              32.2
#define VELOCITY             200.0
#define PI                   3.14159265
#define TOLERANCE_MIN        -2
#define TOLERANCE_MAX        2


void StartUp() {
  cout << "Welcome to Artillery." << endl;
  cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
  cout << "You have one cannon, which you can shoot at any angle." << endl;
  cout << "You only have 10 cannonballs for this target.." << endl;
  cout << "Let's begin..." << endl;
}

int GetEnemyDistance() {
  srand(time(NULL));
  return rand() % ENEMY_MAX_DISTANCE + ENEMY_MIN_DISTANCE;
}

double GetShootAngle() {
  double angle = 0;
  cout << "What angle? "; cin >> angle;
  return angle * PI / 180;
}

double Shoot(double angle, int target_distance) {
  double time_in_air = (2.0 * VELOCITY * sin(angle)) / GRAVITY;
  int distance = round((VELOCITY * cos(angle)) * time_in_air);
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
    if (TOLERANCE_MIN <= shoot_deviation && TOLERANCE_MAX >= shoot_deviation) {
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
  } while (shots <= MAX_CANNON_BALLS);
  cout << "You have used all of your " << MAX_CANNON_BALLS << " cannonballs." << endl;
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