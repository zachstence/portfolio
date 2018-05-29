#include <iostream> 
#include <math.h>
#include <string>
using namespace std;

const int UPPER = 1000000;

int power(int b, int x) {
  int result = 1;
  for (int i = 0; i < x; i++) {
    result *= b;
  }
  return result;
}

int rotate(int x) {
  int digits = floor(log10(x)+1);
  int n = power(10, digits-1);
  return (x % n)*10 + floor(x/n);
}

bool isPrime(int x) {
  if (x == 1) return false;
  for (int i = 2; i <= floor(sqrt(x)); i++) {
    if (x % i == 0) return false;
  }
  return true;
}

bool doesContain(int num, int d) {
  int digits = floor(log10(num)+1);
  for (int i = digits; i > 0; i--) {
    if (num % 10 == d)
      return true;
    else
      num /= 10;
  }
  return false;
}


bool isCircular(int x) {
  if (doesContain(x, 0)) return false;
  int rot = floor(log10(x));
  for (int i = 0; i <= rot; i++) {
    if (!isPrime(x)) {
      return false;
    }
  x = rotate(x);
  }
  return true;
}

int main() {
  int count = 0;
  for (int i = 1; i < UPPER; i++) {
   if(isCircular(i)==true) {
      count++;
    }
  }
  cout << count << endl;
}
