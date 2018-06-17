#include <iostream>

int sumOfSq(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i * i;
  }
  return sum;
}

int sqOfSum(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum * sum;
}

int main() {
  std::cout << sqOfSum(100) - sumOfSq(100) << std::endl;
}
