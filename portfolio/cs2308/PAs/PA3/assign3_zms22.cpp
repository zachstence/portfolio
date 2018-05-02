// File Name: assign3_zms22.cpp
//
// Author: Zachary Stence
// Date: 2/28/2017
// Assignment Number: 3
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Implements and tests four functions: isSorted, chain, grow, and subArray

#include<iostream>
#include<iomanip>
using namespace std;

//*****************************************************************************
// isSorted: tests if an array of ints is sorted in non-decreasing order
//
// arr: a pointer that points to the location of the first element of the
//      array being tested
// size: the size of the array being tested
// returns: true if the array is in non-decreasing order, false otherwise
//*****************************************************************************
bool isSorted (int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (*(arr + i) > *(arr + (i + 1)))
      return false;
  }
  return true;
}

//*****************************************************************************
// chain: converts inches into feet and inches using pointers
//
// totalInches: the amount of inches to be converted
// feet: a pointer that points to a variable in main which is the number 
//         of feet in total inches
// inches: a pointer that points to a variable in main which is the number
//           of inches left over
// returns: (# of feet * 3.49) + (# of inches * 0.3) ... (not sure why?)
//*****************************************************************************
double chain (int totalInches, int* feet, int* inches) {
  *feet = totalInches / 12;
  *inches = totalInches % 12;
  return *feet * 3.49 + *inches * 0.3;
}

//*****************************************************************************
// grow: takes an array and uses it to make a new array with each original 
//       element appearing twice consecutively
//
// arr: a pointer that points to an array in main which is the original array
// size: the size of arr
// returns: a pointer that points to a dynamically allocated array in main
//*****************************************************************************
int* grow(int* arr, int size) {
  int* gArray;
  if (size <= 0)
    return NULL;
  gArray = new int [size * 2];
  for (int i = 0; i < (size * 2) - 1; i += 2) {
    gArray[i] = arr[i / 2];
    gArray[i + 1] = arr[i / 2];
  }
  return gArray;
}

//*****************************************************************************
// duplicateArray: copies one array to another use dynamically allocated
//                 memory
//
// arr: a pointer that points to the array in main to be copied
// size: the size of arr
// returns: a pointer that points to a dynamically allocated array in main
//          which is an exact copy of arr
//*****************************************************************************
int* duplicateArray(int* arr, int size) {
  int* newArray;
  if(size <= 0)
    return NULL;
  newArray = new int[size];
  for(int i = 0; i < size; i++) {
    newArray[i] = arr[i];
  }
  return newArray;
}

//*****************************************************************************
// subArray: takes an array and returns a subArray based off of input
//           parameters
//
// arr: a pointer that points to an array in main
// start: an integer that serves as the index the user wishes to start the
//        sub-array at in arr
// length: an integer that is the desired length of the sub-array
// returns: a pointer to a dynamically allocated array containing the
//          sub-array, done by clever use of duplicateArray
//*****************************************************************************
int* subArray(int* arr, int start, int length) {
  int* result = duplicateArray(arr + start, length);
  return result;
}

//*****************************************************************************
// displayArray: displays an array through cout
//
// arr: the array to be displayed
// size: the size of the array
//*****************************************************************************
void displayArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}



int main () {
  cout << "----------------------------------------\n";

//---ISSORTED---------

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[] = {8, 7, 6, 5, 4, 3, 2, 1};
  int arr3[] = {1, 2, 3, 5, 4, 6, 7, 8};

  cout << endl << "testing isSorted():" << endl;
  
  cout << "arr1:\t\t\t";
  displayArray(arr1, 8);
  cout << endl << "Expected result:\ttrue" << endl;
  cout << "Actual result:\t\t" << boolalpha << isSorted(arr1, 8) << endl;;

  cout << "arr2:\t\t\t";
  displayArray(arr2, 8);
  cout << endl << "Expected result:\tfalse" << endl;
  cout << "Actual result:\t\t" << boolalpha << isSorted(arr2, 8) << endl;

  cout << "arr3:\t\t\t";
  displayArray(arr3, 8);
  cout << endl << "Expected result:\tfalse" << endl;
  cout << "Actual result:\t\t" << boolalpha << isSorted(arr3, 8) << endl;

  cout << endl;

//---CHAIN------------

  cout << "testing chain(53 inches):" << endl;

  int feet = 1;
  int inch = 1;
  cout << "Expected result: 15.46\tfeet: 4\tinches: 5" << endl;
  double actual = chain(53, &feet, &inch);
  cout << "Actual results:  " << actual << "\tfeet: " << feet 
    << "\tinches: " << inch << endl;

//---GROW-------------

  int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << endl << "testing grow():" << endl;

  cout << "test arr4[]:\t\t";
  displayArray(arr4, 9);
  cout << "\nExpected result:\t1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9" << endl;
  cout << "Actual result:\t\t";
  displayArray(grow(arr4, 9), 18);
  cout << endl;

//---SUBARRAY---------

  int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int start = 5;
  int length = 4;
  int* res;

  cout << endl << "testing subArray():" << endl;
  
  cout << "test arr5[]:\t\t";
  displayArray(arr5, 9);
  cout << endl << "start:\t\t\t" << start << endl << "length:\t\t\t" 
    << length << endl;
  cout << "Expected result:\t6 7 8 9" << endl;
  res = subArray(arr5, start, length);
  cout << "Actual result:\t\t";
  displayArray(res, length);
  cout << endl;
}
