#include <iostream>
using namespace std;

void multiply(int arr[], int size, int mult) {
  for (int i = 0; i < size; i++) {
    arr[i] *= mult;
  }
}

void carry(int arr[], int size) {
  for (int i = size - 1; i >= 0; i--) {
    int ones = arr[i] % 10;
    int tens = arr[i] / 10;
    arr[i] = ones;
    arr[i-1] += tens;
  }
}

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i];
  }
  cout << endl;
}

int digitSum(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  int num[158];
  num[157] = 1;
  for (int i = 0; i < 157; i++) {
    num[i] = 0;
  }

  for (int m = 1; m <= 100; m++) {
    multiply(num, 158, m);
    carry(num, 158);
  }
  cout << digitSum(num, 158) << endl;
}
