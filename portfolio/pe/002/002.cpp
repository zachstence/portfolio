#include <iostream>

int main() {
  int sum = 0,
    a = 1,
    b = 1;
  while (b <= 4000000) {
    int fib = a + b;
    a = b;
    b = fib;
    if (fib % 2 == 0) sum += fib; 
  }
  std::cout << sum << std::endl;
}
