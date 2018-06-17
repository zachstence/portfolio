#include <iostream>
using namespace std;

const int PRECISION = 50;
const int UPPER = 1000;

bool isIn(int x, int arr[]) {
  for (int i = 0; i < UPPER; i++) {
    if (arr[i] == x)
      return true;
  }
  return false;
}

int* divide(int r, int x) {
  int* num = new int [PRECISION];
  for (int i = 0; i < PRECISION; i++) {
    num[i] = 0;
  }
  int rem[UPPER] = {0};

  for (int i = 0; i < PRECISION; i++) {
    if (isIn(r, rem)) {
      num[i] = -1;
      return num;
    }
    else {
      rem[i] = r;
      num[i] = (10 * r)/x;
      r = (10 * r) % x;
    }
  }
}

void display(int arr[], int size) {
  cout << endl << "0.";
  for (int i = 0; i < size; i++) {
    if (arr[i] >= 0) {
      cout << arr[i];
      break;
    }
  }
  cout << endl;
}

int main () {
  int a, x;
  cout << "Enter the numerator: ";
  cin >> a;
  cout << "Enter the denominator: ";
  cin >> x;

  display(divide(a, x), UPPER);
}
