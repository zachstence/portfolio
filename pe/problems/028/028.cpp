#include<iostream>
#include<math.h>
using namespace std;

int diags(int start, int dim) {
  int n = start, sum = start, l = 1, end = pow(dim, 2);
  while (n != end) {
    sum += 4*n + 20*l;
    n += 8*l;
    l++;
  }
  return sum;
}

int main() {
  int start = 1;
  int dim = 1001;
  cout << diags(start, dim) << endl;
}
