#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

int main() {
  vector<string> names;
  ifstream fin;
  fin.open("names.txt");
  string name;
  char other;
  while (fin) {
    fin >> other;
    if (isalpha(other))
      name += other;
    else {
      if (name != "")
        names.push_back(name);
      name = "";
    }
  }

  sort(names.begin(), names.end());
/*
  for (int i = 0; i < names.size(); i++) {
    cout << names[i] << endl;
  }
*/
  int total = 0;
  for (int i = 0; i < names.size(); i++) {
    int nameSum = 0;
    for (int c = 0; c < names[i].length(); c++) {
//      cout << names[i][c] << ": " << (int)names[i][c] - 64 << endl;
      nameSum += (int)names[i][c] - 64;
    }
//    cout << nameSum << " * " << i+1 << " = " << nameSum*i+1 << endl << endl;
    total += nameSum * (i+1);
  }

  cout << total;
}
