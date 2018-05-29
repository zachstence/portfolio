

#include <iostream>
#include <cmath>
using namespace std;

int d(int num) {
  int sum = 0;
  for (int i = 1; i <= num/2; i++) {
    if (num % i == 0)
      sum += i;
  }
  return sum;
}

int main () {
  int sum = 0;
  for (int i = 1; i < 10000; i++) {
    if (i == d(d(i)) && i != d(i))
      sum += i;
  }
  cout << sum << endl;
}
