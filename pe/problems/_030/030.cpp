#include<iostream>
#include<cmath>
using namespace std;

int length(int x) {
  return floor(log10(x)+1);
}

int main() {
  int total = 0;
  for (int i = 2; i < 10000000; i++) {
    int num = i;
    int sum = 0;
    for (int j = length(num); j >= 0 && num > 0; j--) {
      sum += pow(num % 10, 5);
      num /= 10;
    }
    if (sum == i)
      total += i;
  }
  cout << total;
}
