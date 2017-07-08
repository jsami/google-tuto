#include  <iostream>
using namespace std;

int main() {
  int hour, min, sec;
  cout << "Number of seconds: "; cin >> sec;

  hour = sec / 3600;
  int remain = sec % 3600;
  min = remain / 60;
  sec = remain % 60;

  cout << "Hours: " << hour << endl;
  cout << "Minutes: " << min << endl;
  cout << "Seconds: " << sec << endl;

  return 0;
}