#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 20;
const int COLS = 20;

void setup(long long arr[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (r == 0)
        arr[r][c] = c + 2;
      else if (c == 0)
        arr[r][c] = r + 2;
      else
        arr[r][c] = 0;
    }
  }
}

void fill(long long arr[ROWS][COLS]) {
  for (int r = 1; r < ROWS; r++) {
    for (int c = 1; c < COLS; c++) {
      arr[r][c] = arr[r-1][c] + arr[r][c-1];
    }
  }
}

void display2D(long long arr[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      cout << setw(13) << arr[r][c];
    }
    cout << endl;
  }
}

int main() {
  long long lattice[ROWS][COLS];
  setup(lattice);
  fill(lattice);
//  display2D(lattice);

  cout << lattice[19][19] << endl;
}
