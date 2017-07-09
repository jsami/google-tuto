#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

#define kHorsePrice   10
#define kPigPrice     3
#define kRabbitPrice  0.5
#define kTotalPrice   100
#define kTotalNumber  100

bool AreSame(double l, double r) {
  return fabs(l - r) < numeric_limits<double>::epsilon();
}

bool CheckAnimals(int n_horse, int n_pig, int n_rabbit) {
  int total_number = n_horse + n_pig + n_rabbit;
  double totalPrice = kHorsePrice * n_horse + kPigPrice * n_pig + kRabbitPrice * n_rabbit;
  return (total_number == kTotalNumber) && AreSame(totalPrice, kTotalPrice);
}

int MaxNumber(double price) {
  int max = (int)kTotalPrice / price;
  return max < kTotalNumber ? max : kTotalNumber;
}

int main() {
  int n_pig, n_horse, n_rabbit;
  int max_horse = MaxNumber(kHorsePrice);
  int max_pig = MaxNumber(kPigPrice);
  int max_rabbit = MaxNumber(kRabbitPrice);

  bool combination_found = false;
  for (n_horse = 1; n_horse < max_horse && !combination_found; ) {
    combination_found = CheckAnimals(n_horse, n_pig, n_rabbit);
    for (n_pig = 1; n_pig < max_pig && !combination_found; ) {
      combination_found = CheckAnimals(n_horse, n_pig, n_rabbit);
      for (n_rabbit = 1; n_rabbit < max_rabbit && !combination_found; n_rabbit++) {
        if ((combination_found = CheckAnimals(n_horse, n_pig, n_rabbit)))
          break;
      }
      if(!combination_found)
        n_pig++;
    }
    if(!combination_found)
      n_horse++;
  }

  cout << "Pig: " << n_pig << endl;
  cout << "Horse: " << n_horse << endl;
  cout << "Rabbit: " << n_rabbit << endl;
}
