// File Name: assign1_zms22.cpp
// 
// Author: Zachary Stence
// Date: 1/25/2017
// Assignment Number: 1
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman 
// 
// Keeps an array of 9 Rat structures conataining each rat's name, weight in 
// ounces, and time to complete a maze.
// Outputs a table of said data and gives the rats' average weight and name and 
// time of the fastest and slowest rat.

//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 9;

struct Rat {
  string name;
  double weight;
  int time;
};



//***********************************************************
// findSlowFast: Finds and prints the rats with the slowest and fastest times.
//
// labrats: the array containing all Rat structures
//***********************************************************

void findSlowFast(Rat labrats[], int &slowindex, int &fastindex) {
  double fast = labrats[0].time;
  double slow = labrats[0].time;
  for(int i = 0; i < SIZE; i++) {
    if(labrats[i].time < fast) {
      fast = labrats[i].time;
      fastindex = i;
    }
    if(labrats[i].time > slow) {
      slow = labrats[i].time;
      slowindex = i;
    }
  }
}



//***********************************************************
// averageWeight: determines the average weight of all lab rats
//
// labrats: the array containing all Rat structures
// returns: the average weight of all lab rats
//***********************************************************

double averageWeight(Rat labrats[]) {
  double total = 0;
  for(int i = 0; i < SIZE; i++) {
    total += labrats[i].weight;
  }
  return total/SIZE;
}

int main() {
  cout<<fixed<<setprecision(1);
  Rat labrats[SIZE] = {
    {"Ben",         6.5, 29},
    {"Fred",        5.8, 31},
    {"Splinter",    7.7, 33},
    {"Lima Bean",   6.5, 27},
    {"Black Bean",  5.8, 31},
    {"Pinto Bean",  7.7, 33},
    {"Skat",        6.5, 29},
    {"Big Pook",    9.8, 34},
    {"Tiger",       7.7, 33},
  };
  for(int i = 0; i < SIZE; i++) {
    cout << labrats[i].name << " " << labrats[i].weight << " "
      << labrats[i].time << endl;
  }

  cout << "\nThe average weight of the lab rats is " << averageWeight(labrats)
    << " ounces." << endl;
  int slowindex = 0;
  int fastindex = 0;
  findSlowFast(labrats, slowindex, fastindex);
  cout << "The fastest rat was " << labrats[fastindex].name
    << " with a time of " << labrats[fastindex].time << " seconds." << endl;
  cout << "The slowest rat was " << labrats[slowindex].name
    << " with a time of " << labrats[slowindex].time << " seconds." << endl;
}