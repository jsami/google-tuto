#include <fstream>
#include <iostream>
using namespace std;

int main() {
  char file_name[20];
  cout << "Enter the name of the file to read: "; cin >> file_name;

  ifstream People(file_name, ios::in);
  string line;
  if (People.is_open()) {
    while (getline(People, line)) { 
      cout << line << endl;
    }
    People.close();
  }
  return 0;
}