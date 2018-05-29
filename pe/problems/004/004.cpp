#include <iostream>

/**
 * Returns true if x is a palindrome, false otherwise
 * @param x: A positive integer
 */
bool isPalindrome(int x) {
  // Convert x to a string for easier processing
  std::string num = std::to_string(x);
  // Set iterators at first and last characters of string
  auto front = num.begin();
  auto back = num.end() - 1;
  // While iterators haven't passed each other
  while (front < back) {
    // If characters in the string aren't equal, isn't a palindrome
    if (*front != *back) return false;
    // Increment iterators
    ++front, --back;
  }
  return true;
}

int main() {
  int max = 0;
  // Loop through possible products and save maximum
  for (int num1 = 999; num1 >= 111; num1--) {
    for (int num2 = num1; num2 >= 111; num2--) {
      int product = num1 * num2;
      if (product > max && isPalindrome(product)) max = product;
    }
  }
  std::cout << max << std::endl;
}
