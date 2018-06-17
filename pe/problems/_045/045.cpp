#include <iostream>
#include <math.h>
using namespace std;

bool isTri(int num) {
  for (int i = 1; i <= 2*sqrt(num); i++) {
    if ((i * (i + 1)) / 2 == num)
      return true;
  }
  return false;
}

bool isPent(int num) {
  for (int i = 1; i <= 2*sqrt(num); i++) {
    if ((i * (3*i - 1)) / 2 == num)
      return true;
  }
  return false;
}

bool isHex(int num) {
  for (int i = 1; i <=2*sqrt(num); i++) {
    if (i * (2*i - 1) == num)
      return true;
  }
  return false;
}

int main() {
  bool run = true;
  int num;
  for (int n = 144; run; n++) {
    num = n*(2*n-1);
    cout << "n: " << n << endl;
    if (isTri(num) && isPent(num)) {
      cout << num << endl;
      run = false;
    }
  }
}
