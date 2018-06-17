#include <iostream>
#include <cmath>

bool isPrime(int x) {
  // 1 is not prime; false for non-positive integers
  if (x <= 1) return false;
  // 2 is prime
  else if (x == 2) return true;
  else if (x % 2 == 0) return false;
  else {
    // iterate through all odd nums less than square root of x
    for (int i = 3; i <= sqrt(x); i += 2)
      // if x is divisible by a number, it is not prime
      if (x % i == 0) return false;
    return true;
  }
}

int findNextPrime(int x) {
  for (x += 1; !isPrime(x); x++);
  return x;
}

int main() {
  int prime = 2;
  int index = 1;
  while (index < 10001) {
    prime = findNextPrime(prime);
    index++;
  }
  std::cout << prime << std::endl;
}
