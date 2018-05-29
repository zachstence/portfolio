#include<iostream>
#include<fstream>
using namespace std;

const int ROWS = 20;
const int COLS = 20;

void display2DArray(int arr[][COLS], int rows, int cols) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << arr[i][j] << " ";
    }
  cout << endl;
  }
}

int maxHP(int arr[][COLS], int rows, int cols) {
  int max = 0;
  int imax, jmax, num;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j <= COLS - 4; j++) {
//      cout << "Checking product at i = " << i << ", j = " << j << "." << endl;
      num = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
//      cout << arr[i][j] << " * " << arr[i][j+1] << " * " << arr[i][j+2]
//        << " * " << arr[i][j+3] << " = " << num << endl;
      if (num > max) {
        max = num;
        imax = i;
        jmax = j;
//        cout << "NEW MAX OF " << max << " AT " << imax << ", " << jmax << endl;
      }
    }
  }
//  cout << "maxHP: arr[" << imax << "][" << jmax << "] = " << max << endl;
  return max;
}

int maxVP(int arr[][COLS], int rows, int cols) {
  int max = 0;
  int imax, jmax, num;
  for (int i = 0; i <= ROWS - 4; i++) {
    for (int j = 0; j < COLS; j++) {
      num = arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
      if (num > max) {
        max = num;
        imax = i;
        jmax = j;
//        cout << "NEW MAX OF " << max << " AT " << imax << ", " << jmax << endl;
      }
    }
  }
//  cout << "maxVP: arr[" << imax << "][" << jmax << "] = " << max << endl;;
  return max;
}

int maxDP(int arr[][COLS], int rows, int cols) {
  int max = 0;
  int imax, jmax, num;
  for (int i = 0; i <= ROWS - 4; i++) {
    for (int j = 0; j <= COLS - 4; j++) {
      num = arr[i][j] * arr[i+1][j+1] * arr[i+2][j+2] * arr[i+3][j+3];
      if (num > max) {
        max = num;
        imax = i;
        jmax = j;
//        cout << "NEW MAX OF " << max << " AT " << imax << ", " << jmax << endl;
      }
    }
  }
//  cout << "maxDP: arr[" << imax << "][" << jmax << "] = " << max << endl;
  return max;
}

int maxDP2(int arr[][COLS], int rows, int cols) {
  int max = 0;
  int imax, jmax, num;
  for (int i = 0; i <= ROWS - 4; i++) {
    for (int j = 3; j < COLS; j++) {
      num = arr[i][j] * arr[i+1][j-1] * arr[i+2][j-2] * arr[i+3][j-3];
      if (num > max) {
        max = num;
        imax = i;
        jmax = j;
//        cout << "NEW MAX OF " << max << " AT " << imax << ", " << jmax << endl;
      }
    }
  }
//  cout << "maxDP2: arr[" << imax << "][" << jmax << "] = " << max << endl;
  return max;
}

int main() {
  int grid[ROWS][COLS] = {};

  ifstream fin("grid.txt");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      fin >> grid[i][j];
    }
  }
  cout << max(max(maxHP(grid, ROWS, COLS), maxVP(grid, ROWS, COLS)),
    max(maxDP(grid, ROWS, COLS), maxDP2(grid, ROWS, COLS))) << endl;
}
