#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

bool AreSame(double l, double r) {
  return fabs(l - r) < numeric_limits<double>::epsilon();
}

bool CheckAnimals(int horse, int pig, int rabbit) {
  int totalNumber = horse + pig + rabbit;
  double totalPrice = 10 * horse + 3 * pig + 0.5 * rabbit;
  return (totalNumber == 100) && AreSame(totalPrice, 100);
}

int main() {
  int nPig, nHorse, nRabbit;
  bool combinationFound = false;
  for (nHorse = 1; nHorse < 10 && !combinationFound; ) {
    combinationFound = CheckAnimals(nHorse, nPig, nRabbit);
    for (nPig = 1; nPig < 33 && !combinationFound; ) {
      combinationFound = CheckAnimals(nHorse, nPig, nRabbit);
      for (nRabbit = 1; nRabbit < 100 && !combinationFound; nRabbit++) {
        if ((combinationFound = CheckAnimals(nHorse, nPig, nRabbit)))
          break;
      }
      if(!combinationFound)
        nPig++;
    }
    if(!combinationFound)
      nHorse++;
  }

  cout << "Pig: " << nPig << endl;
  cout << "Horse: " << nHorse << endl;
  cout << "Rabbit: " << nRabbit << endl;
}
