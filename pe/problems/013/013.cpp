#include <iostream>
#include <fstream>
using namespace std;

const int ROWS = 100;
const int COLS = 50;

void display(int arr[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      cout << arr[r][c];
    }
  cout << endl;
  }
}

void displaySpace(int arr[COLS]) {
  for (int c = 0; c < COLS; c++) {
    cout << arr[c] << " ";
  }
}

void displayNoSpace(int arr[COLS]) {
  for (int c = 0; c < COLS; c++) {
    cout << arr[c] << "";
  }
}

int* sum(int arr[ROWS][COLS]) {
  int* sum = new int [COLS];
  int total;
  for (int c = COLS - 1; c >= 0; c--) {
    total = 0;
    for (int r = 0; r < ROWS; r++) {
      total += arr[r][c];
    }
    sum[c] = total;
  }
  return sum;
}

int* carry(int arr[]) {
  int ones, tens;
  for (int c = COLS - 1; c >= 1; c--) {
    ones = arr[c] % 10;
    tens = arr[c] / 10;
    arr[c - 1] += tens;
    arr[c] = ones;
  }
  return arr;
}


int main() {
  ifstream fin;
  fin.open("nums.txt");
//  if (fin.is_open()) cout << "File succesfully opened." << endl;

  int nums[ROWS][COLS];
  char ch;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      fin >> ch;
      nums[r][c] = ch - 48;
    }
  }
  
  int* ans = carry(sum(nums));

  for (int i = 0; i < 8; i++) {
    cout << ans[i];
  }
  cout << endl;
}
