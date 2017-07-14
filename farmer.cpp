#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

#define HORSE_PRICE   10
#define PIG_PRICE     3
#define RABBIT_PRICE  0.5
#define TOTAL_PRICE   100
#define TOTAL_NUMBER  100

bool AreSame(double l, double r) {
  return fabs(l - r) < numeric_limits<double>::epsilon();
}

bool CheckAnimals(int n_horse, int n_pig, int n_rabbit) {
  int total_number = n_horse + n_pig + n_rabbit;
  double totalPrice = HORSE_PRICE * n_horse + PIG_PRICE * n_pig + RABBIT_PRICE * n_rabbit;
  return (total_number == TOTAL_NUMBER) && AreSame(totalPrice, TOTAL_PRICE);
}

int MaxNumber(double price) {
  int max = (int)TOTAL_PRICE / price;
  return max < TOTAL_NUMBER ? max : TOTAL_NUMBER;
}

int main() {
  int n_pig, n_horse, n_rabbit;
  int max_horse = MaxNumber(HORSE_PRICE);
  int max_pig = MaxNumber(PIG_PRICE);
  int max_rabbit = MaxNumber(RABBIT_PRICE);

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
