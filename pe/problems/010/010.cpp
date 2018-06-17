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

int main() {
  long long sum = 0;
  for (int i = 0; i < 2000000; i++) {
    if (isPrime(i)) sum += i;
  }
  std::cout << sum << std::endl;
}
