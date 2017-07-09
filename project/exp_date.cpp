#include <iostream>
#include <sstream>
#include <string>
using namespace std;


const string kMonths[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

string GetMonth(const string& code) {
  string map = "ABCDEFGHIJKL";
  int index = map.find(code[0]);
  return kMonths[index];
}

int GetDate(const string& code) {
  string map = "QRSTUVWXYZ";
  int firstDigit = map.find(code[1]);
  int secondDigit = map.find(code[2]);
  return firstDigit * 10 + secondDigit;
}

int GetYear(const string& code) {
  string map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int offset = map.find(code[3]);
  return 1995 + offset;
}

string Decode(const string& code) {
  string decoded;
  stringstream ss;
  ss << GetMonth(code) << "-" << GetDate(code) << "-" << GetYear(code);
  ss >> decoded;
  return decoded;
}

int main() {
  string code = "ARZM";
  cout << code << ": " << Decode(code) << endl;
}