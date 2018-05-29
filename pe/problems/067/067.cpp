#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


const int ROWS = 100;
const int COLS = ROWS;

void displayTri(int arr[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c <= r; c++) {
      cout << arr[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;
}


int main() {
  ifstream fin;
  string fileName;
  fin.open("pe_massive.txt");
  assert(fin.is_open());

  // read in triangle array from file
  int size = (ROWS*(ROWS+1))/2;
  int tri[ROWS][COLS];
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c <= r; c++) {
      fin >> tri[r][c];
    }
  }

  //bottom-up algorithm
  int start = ROWS - 2;
  for (int r = start; r >= 0; r--) {
    for (int c = 0; c <= r; c++) {
      if (tri[r+1][c] > tri[r+1][c+1])
        tri[r][c] += tri[r+1][c];
      else
        tri[r][c] += tri[r+1][c+1];
    }
  }

  cout << tri[0][0] << endl;

}

