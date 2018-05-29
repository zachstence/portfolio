#include<iostream>
using namespace std;

int findLength(unsigned long long num) {
  int count = 1;
  while (num > 1) {
    if (num % 2 == 0) {
      num /= 2;
//      cout << num << endl;
      count ++;
    } else {
      num = 3 * num + 1;
//      cout << num << endl;
      count++;
    }
  }
  return count;
}

int main () {
  int longest = 0;
  int length = 0;
  for (int i = 1; i < 1000000; i += 2) {
    if (findLength(i) > length) {
      longest = i;
      length = findLength(i);
    }
  }
  cout << longest << endl;
}
