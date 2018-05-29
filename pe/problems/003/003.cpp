#include <iostream>
#include <cmath>

const long NUM = 600851475143;

/**
 * Returns true if x is prime, false otherwise.
 * @param x: A positive integer 
 */
bool isPrime(int x) {
  // 1 is not prime; false for non-positive integers
  if (x <= 1) return false;
  // 2 is prime
  else if (x == 2) return true;
  else {
    // iterate through all odd nums less than square root of x
    for (int i = 3; i < sqrt(x); i += 2)
      // if x is divisible by a number, it is not prime
      if (x % i == 0) return false;
    return true;
  }
}

int main() {
  // iterate through possible divisors
  for (int i = floor(sqrt(NUM)); i > 0; i--) {
    // if i is a divisor and it is prime, answer found
    if (NUM % i == 0 && isPrime(i)) {
      std::cout << i << std::endl;
      break;
    }
  }
}
