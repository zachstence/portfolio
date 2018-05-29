#include<iostream>
#include<math.h>
using namespace std;

void displayArray(int array[], int size) {
  for(int i = 0; i < size; i++) {
    cout << array[i];
  }
  cout << endl;
}

int sumArray(int array[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

void carry(int array[], int size) {
  int ones, tens;
  for(int i = 1; i < size; i++) {
    if(array[i] >= 10) {
      ones = array[i] - 10;
      tens = array[i] / 10;
      array[i - 1] += tens;
      array[i] = ones;
    }
  }
}

void multiply(int array[], int size, int multiplier, int power) {
  for (int count = 1; count <= power; count++) {
    for(int i = 0; i < size; i++) {
      array[i] *= multiplier;
    }
  carry(array, size);
  }
}

void setup(int array[], int size) {
  array[size - 1] = 1;
  for(int i = 0; i < size - 1; i++) {
    array[i] = 0;
  }
}

int power(int base, int power) {
  int size = ceil(power * (log(base)/log(10)));
  int number[size];
  setup(number, size);
  
  multiply(number, size, base, power);
  carry(number, size);

  return sumArray(number, size);
}

int main() {
  int x = 2;
  int y = 1000;
  cout << power(x, y) << endl;
  
}
