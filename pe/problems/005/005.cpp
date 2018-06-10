#include <iostream>

bool divisible(int x, int max) {
  for (int i = 2; i <= max; i++)
    if (x % i != 0) return false;
  return true;
}

int main() {
  int i = 0;
  bool cont;
  do {
    i++;
    cont = !divisible(i, 20);
  } while (cont);
  std::cout << i << std::endl;
}
