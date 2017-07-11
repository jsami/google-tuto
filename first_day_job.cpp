// first_day_job.cpp, Sami Ramahasindry
// Example 7: Next steps with decomposition - Your first day on the job

#include <iostream>
using namespace std;

#define kSalesDay           6  
#define kWorkHour           8    // 8 hours per day;
#define kAveragePairPrice   225
#define kCommission2        0.1   // commission = 10% on sales
#define kCommission3        0.2  // commision = 20% on sales

void Prompt() {
  cout << "Weekly Sales (pairs of shoes): ";
}

int GetInput() {
  Prompt();
  int input;
  while (!(cin >> input) || input < 0) {
    cout << "Please inter numeric, non negative evalues." << endl;
    cin.clear();
    cin.ignore(50, '\n');
    Prompt();
  }
  return input;
}

void PrintHeader(const string& title) {
  cout << "--------------------------" << endl;
  cout << "      " << title << endl;
  cout << "--------------------------" << endl;
}

void PrintResult(const string& title, double compensation) {
  PrintHeader(title);
  cout << "Compensation : $" << compensation << " per week" << endl;
}

void CalcMethod1(int weeklySales) {
  PrintResult("Method1", 600);
}

void CalcMethod2(double weeklySales) {
  double commission = weeklySales * kAveragePairPrice * kCommission2;
  double compensation = 7 * kWorkHour * kSalesDay + commission;
  PrintResult("Method2", compensation);
}

void CalcMethod3(int weeklySales) {
  double commission = weeklySales * kAveragePairPrice * kCommission3;
  double compensation = 20 * weeklySales + commission;
  PrintResult("Method3", compensation);
}

int main() {
  int weekly_sales = GetInput();
  if(weekly_sales == 0)
    return 0;
  CalcMethod1(weekly_sales);
  CalcMethod2(weekly_sales);
  CalcMethod3(weekly_sales);
}