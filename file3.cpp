// file3.cpp, Sami Ramahasindry
// Writing to / reading from file

#include <fstream>
#include <iostream>
using namespace std;

void PopulateFile(char* file_name) {
  ofstream People(file_name, ios::out);
  string entry;
  while (true) {
    cout << "Enter an entry. (Type 'done' to finish) : ";
    cin >> entry;
    if (entry.compare("done") == 0)
      break;
    People << entry << endl;
  }
  People.close();
}

void ReadFile(char* file_name) {
  ifstream People_in(file_name);
  string line;
  while (getline(People_in, line)) {
    cout << line << endl;
  }
  People_in.close();
}

int main() {
  char file_name[20];
  cout << "Enter the name of the file: ";
  cin >> file_name;
  PopulateFile(file_name);
  ReadFile(file_name);
  return 0;
}