#include<iostream>
#include<math.h>
using namespace std;

int factors(unsigned long long num) {
  int count = 0;
  for (unsigned long long i = 1; i < sqrt(num); i++) {
    if (num % i == 0) {
      count +=2;
    }
  }
  return count;
}

int triangle(int num) {
  int sum = 0;
  for (int i = num; i > 0; i--) {
    sum += i;
  }
  return sum;
}

int main () {
  unsigned long long i = 0;
  while (factors(triangle(i)) < 500) {
    i++;
  }
  cout << triangle(i) << endl;
}
